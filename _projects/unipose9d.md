---
layout: compress
permalink: /projects/unipose9d
---

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>UniPose9D: Universal Category Agnostic Object Pose Estimation</title>
    <meta
      name="description"
      content="UniPose9D estimates object rotation, translation, and metric size from color and depth, or from a single color image with predicted depth. It does not require category labels, CAD models, shape priors, or reference views."
    >
    <meta property="og:title" content="UniPose9D">
    <meta property="og:description" content="Universal Category Agnostic Object Pose Estimation">
    <meta property="og:image" content="/projects/unipose9d/images/teaser1.jpg">

    <link href="https://fonts.googleapis.com/css?family=Google+Sans|Noto+Sans|Castoro&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/jpswalsh/academicons@1/css/academicons.min.css">
    <link rel="stylesheet" href="/projects/unipose9d/assets/site.css">
  </head>
  <body>

    <section class="hero">
      <div class="hero-body">
        <div class="container is-max-desktop">
          <div class="columns is-centered">
            <div class="column has-text-centered">
              <h1 class="title is-1 publication-title">UniPose9D: Universal Category Agnostic Object Pose Estimation</h1>

              <div class="is-size-5 publication-authors">
                <span class="author-block">
                  <a href="https://qq456cvb.github.io/" target="_blank" rel="noopener">Yang You</a>,</span>
                <span class="author-block">
                  <a href="https://scholar.google.com/citations?user=LhYjApUAAAAJ&amp;hl=en" target="_blank" rel="noopener">Yi Du</a>,</span>
                <span class="author-block">
                  <a href="https://www.linkedin.com/in/cole-harrison-ai/" target="_blank" rel="noopener">Cole Harrison</a>,</span>
                <span class="author-block">
                  <a href="https://geometry.stanford.edu/" target="_blank" rel="noopener">Leonidas Guibas</a></span>
              </div>

              <!-- TODO: add affiliations, e.g.
              <div class="is-size-5 publication-authors">
                <span class="author-block">Stanford University</span>
              </div>
              -->

              <div class="publication-links">
                <span class="link-block">
                  <a href="https://arxiv.org/abs/2607.09985" class="external-link button is-normal is-rounded is-dark" title="View on arXiv">
                    <span class="icon"><i class="ai ai-arxiv"></i></span>
                    <span>arXiv</span>
                  </a>
                </span>
                <span class="link-block">
                  <a href="https://arxiv.org/pdf/2607.09985" class="external-link button is-normal is-rounded is-dark" title="Read the paper PDF">
                    <span class="icon"><i class="fas fa-file-pdf"></i></span>
                    <span>Paper</span>
                  </a>
                </span>
                <span class="link-block">
                  <a href="https://github.com/qq456cvb/UniPose9D" target="_blank" rel="noopener" class="external-link button is-normal is-rounded is-dark">
                    <span class="icon"><i class="fab fa-github"></i></span>
                    <span>Code</span>
                  </a>
                </span>
                <!-- TODO: replace # with the dataset link -->
                <span class="link-block">
                  <a href="#" class="external-link button is-normal is-rounded is-dark" title="Dataset (coming soon)">
                    <span class="icon"><i class="fas fa-database"></i></span>
                    <span>Dataset</span>
                  </a>
                </span>
                <span class="link-block">
                  <a href="https://huggingface.co/spaces/qq456cvb/UniPose9D" target="_blank" rel="noopener" class="external-link button is-normal is-rounded is-dark">
                    <span class="icon">🤗</span>
                    <span>Demo</span>
                  </a>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>

    <section class="hero teaser">
      <div class="container is-max-desktop">
        <div class="hero-body">
          <img src="/projects/unipose9d/images/teaser1.jpg" alt="UniPose9D pose estimates across cluttered tabletops, occlusions, robotic manipulation, and everyday photos">
          <h2 class="subtitle has-text-centered teaser-caption">
            Given an object mask and either <b>color with depth</b> or <b>color with predicted depth</b>,
            UniPose9D estimates rotation, translation, and a metric 3D bounding box. It does not need
            category labels, CAD models, shape priors, or reference images. Yellow cuboids show the
            predicted metric boxes, while the colored axes show orientation.
          </h2>
        </div>
      </div>
    </section>

    <section class="section">
      <div class="container is-max-desktop">
        <div class="columns is-centered has-text-centered">
          <div class="column is-four-fifths">
            <h2 class="title is-3">Abstract</h2>
            <div class="content has-text-justified">
              <p>
                <b>UniPose9D</b> is a universal, category agnostic model for 9D object pose estimation.
                From one masked color and depth observation, or one color image with predicted metric
                depth, it estimates rotation, translation, and metric bounding box size. At inference
                time, it does not need a category name, template, shape prior, CAD model, or reference
                image.
              </p>
              <p>
                Rather than regress NOCS coordinates independently at every pixel, UniPose9D samples
                pairs of points from the observed object cloud and combines geometric features with
                DINOv2 visual features. It predicts NOCS coordinates for each pair, creating many more
                correspondences for robust pose estimation with RANSAC and Kabsch Umeyama. Metric
                scale comes from the relationship between distances in the predicted NOCS space and
                the observed point cloud. An iterative Kabsch Umeyama procedure then refines the
                inlier threshold. Flow matching represents multiple valid poses for symmetric objects
                without requiring an explicit list of symmetries.
              </p>
              <p>
                A single model is trained on a mixture of public pose datasets. It performs
                competitively on standard benchmarks and also transfers to unseen object categories
                and everyday scenes.
              </p>
            </div>
          </div>
        </div>
      </div>
    </section>

    <section class="section">
      <div class="container is-max-desktop">
        <h2 class="title is-3 has-text-centered">Method</h2>
        <figure class="paper-figure">
          <img src="/projects/unipose9d/images/pipeline.jpg" alt="UniPose9D pipeline: feature extraction, point pair NOCS prediction, and iterative Kabsch Umeyama pose recovery">
          <figcaption>
            <b>Pipeline.</b> (A) Visual and geometric features are extracted for each point in the masked
            observation. (B) Point pairs are sampled and a flow matching MLP head predicts NOCS
            coordinates and metric box scale for each pair. (C) An iterative Kabsch Umeyama solver
            refines the inlier set and recovers the complete 9D pose.
          </figcaption>
        </figure>
      </div>
    </section>

    <section class="section" id="demo">
      <div class="container is-max-desktop">
        <h2 class="title is-3 has-text-centered">Interactive Demo</h2>
        <p class="has-text-centered demo-note">
          Try UniPose9D in your browser. Upload an image, mark the object with point prompts, then
          estimate its 9D pose.
          If the embedded app does not load, open it directly on
          <a href="https://huggingface.co/spaces/qq456cvb/UniPose9D" target="_blank" rel="noopener">🤗 Hugging Face</a>.
        </p>
        <!-- Note: the Space is currently private; make it public for the embed to load for visitors. -->
        <div class="demo-frame">
          <iframe
            src="https://qq456cvb-unipose9d.hf.space"
            title="UniPose9D Hugging Face demo"
            allow="clipboard-write"
            loading="lazy"
          ></iframe>
        </div>
      </div>
    </section>

    <section class="section">
      <div class="container is-max-desktop">
        <h2 class="title is-3 has-text-centered">Results in the Wild</h2>

        <figure class="paper-figure">
          <img src="/projects/unipose9d/images/teaser2.jpg" alt="Pose estimates in robotic, artistic, and natural scenes">
          <figcaption>
            <b>In the wild.</b> UniPose9D transfers from robotic manipulation to artwork and natural
            imagery. From a single color image with predicted depth, it recovers a metric 3D box and
            object orientation.
          </figcaption>
        </figure>
      </div>
    </section>

    <section class="section" id="BibTeX">
      <div class="container is-max-desktop content">
        <h2 class="title is-3">BibTeX</h2>
        <pre><code>@misc{you2026unipose9duniversalcategoryagnosticobject,
  title         = {UniPose9D: Universal Category-Agnostic Object Pose Estimation},
  author        = {Yang You and Yi Du and Cole Harrison and Leonidas Guibas},
  year          = {2026},
  eprint        = {2607.09985},
  archivePrefix = {arXiv},
  primaryClass  = {cs.CV},
  url           = {https://arxiv.org/abs/2607.09985},
}</code></pre>
      </div>
    </section>

    <footer class="footer">
      <div class="container">
        <div class="columns is-centered">
          <div class="column is-8 has-text-centered">
            <p>
              UniPose9D builds on <a href="https://github.com/facebookresearch/dinov2" target="_blank" rel="noopener">DINOv2</a>,
              <a href="https://github.com/facebookresearch/sam2" target="_blank" rel="noopener">SAM2</a>,
              <a href="https://github.com/IDEA-Research/GroundingDINO" target="_blank" rel="noopener">GroundingDINO</a>, and
              <a href="https://github.com/microsoft/MoGe" target="_blank" rel="noopener">MoGe</a>;
              each dependency is distributed under its own license.
            </p>
            <p>
              This website is licensed under a
              <a href="http://creativecommons.org/licenses/by-sa/4.0/" target="_blank" rel="noopener">Creative Commons Attribution ShareAlike 4.0 License</a>
              and adapted from the <a href="https://github.com/nerfies/nerfies.github.io" target="_blank" rel="noopener">Nerfies</a>
              project page template.
            </p>
          </div>
        </div>
      </div>
    </footer>

  </body>
</html>
