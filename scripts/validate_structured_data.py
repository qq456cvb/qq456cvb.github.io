#!/usr/bin/env python3
"""Check project JSON-LD and the publication evidence for self-hosted videos.

Run: python3 scripts/validate_structured_data.py
This offline regression check complements Google's Rich Results Test; it does
not claim to implement Google's validator or verify Search Console coverage.
"""

import json
import re
from datetime import datetime, timezone
from html.parser import HTMLParser
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATETIME = re.compile(r"\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}(?:\.\d+)?(?:Z|[+-]\d{2}:\d{2})")


class JsonLdParser(HTMLParser):
    def __init__(self):
        super().__init__(convert_charrefs=False)
        self.blocks = []
        self.current = None

    def handle_starttag(self, tag, attrs):
        if tag == "script" and dict(attrs).get("type", "").lower() == "application/ld+json":
            self.current = []

    def handle_data(self, data):
        if self.current is not None:
            self.current.append(data)

    def handle_endtag(self, tag):
        if tag == "script" and self.current is not None:
            self.blocks.append(json.loads("".join(self.current)))
            self.current = None


def walk(value):
    if isinstance(value, dict):
        yield value
        for child in value.values():
            yield from walk(child)
    elif isinstance(value, list):
        for child in value:
            yield from walk(child)


def validate(root=ROOT):
    evidence = json.loads((root / "scripts/video_publication.json").read_text())["videos"]
    records = {(row["page"], row["contentUrl"]): row for row in evidence}
    if len(records) != len(evidence):
        raise ValueError("Duplicate video publication evidence")
    seen = set()
    counts = {"Dataset": 0, "VideoObject": 0, "blocks": 0}
    for path in sorted((root / "_projects").rglob("*.html")):
        relative = path.relative_to(root).as_posix()
        parser = JsonLdParser()
        try:
            parser.feed(path.read_text())
            counts["blocks"] += len(parser.blocks)
            for node in walk(parser.blocks):
                types = node.get("@type", [])
                types = [types] if isinstance(types, str) else types
                if "Dataset" in types:
                    counts["Dataset"] += 1
                    # Google documents Text and CreativeWork, but its live test
                    # rejects our resolved ScholarlyArticle citations. Keep the
                    # tested Text representation for this site's Dataset nodes.
                    citation = node.get("citation")
                    if citation is not None:
                        values = citation if isinstance(citation, list) else [citation]
                        if not values or not all(isinstance(v, str) and v.strip() for v in values):
                            raise ValueError("Dataset.citation must use nonempty Text for Google compatibility")
                if "VideoObject" not in types:
                    continue
                counts["VideoObject"] += 1
                stamp = node.get("uploadDate", "")
                if not isinstance(stamp, str) or not DATETIME.fullmatch(stamp):
                    raise ValueError("VideoObject.uploadDate needs ISO 8601 date, time and timezone")
                parsed = datetime.fromisoformat(stamp.replace("Z", "+00:00"))
                if parsed > datetime.now(timezone.utc):
                    raise ValueError("VideoObject.uploadDate is in the future")
                key = (relative, node.get("contentUrl"))
                if key in seen:
                    raise ValueError("Duplicate VideoObject for the same contentUrl")
                seen.add(key)
                record = records.get(key)
                if record is None or record["uploadDate"] != stamp:
                    raise ValueError("VideoObject.uploadDate lacks matching publication evidence")
                if not re.fullmatch(r"[0-9a-f]{40}", record["commit"]):
                    raise ValueError("Publication evidence needs the asset's first commit")
                if not re.fullmatch(r"https://github\.com/qq456cvb/qq456cvb\.github\.io/actions/runs/\d+/job/\d+", record["deployment"]):
                    raise ValueError("Publication evidence needs a deployment job URL")
        except (ValueError, TypeError) as error:
            raise ValueError(f"{relative}: {error}") from error
    if seen != records.keys():
        raise ValueError(f"Stale publication evidence: {records.keys() - seen}")
    if not counts["blocks"] or not counts["VideoObject"]:
        raise ValueError("No project JSON-LD/videos found; check the input directory")
    return counts


if __name__ == "__main__":
    result = validate()
    print(f"PASS: {result['blocks']} JSON-LD blocks, {result['Dataset']} Datasets, "
          f"{result['VideoObject']} VideoObjects with publication evidence")
