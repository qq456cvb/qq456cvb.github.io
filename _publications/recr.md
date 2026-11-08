---
title: "What Remains in Sight? Autoregressive Video Decoding as Representation-Guided Context Rewriting"
collection: publications
permalink: /publications/recr
excerpt: 'ReCR is a training-free method for long-horizon autoregressive video generation. Under a fixed visible-token budget, it uses internal decoder representations to select context from the generated history, balancing global relevance, redundancy, temporal boundary coverage, and spatial-layout diversity. The selected context is temporally reindexed before decoding the next block, improving long-video consistency across multiple backbones without updating model weights.'
# First arXiv submission date; not the conference acceptance date.
date: '2026-11-03'
# Venue and BibTeX follow the official repository: https://github.com/lixuan27/ReCR
venue: 'NeurIPS'
weight: 1200
image: '/images/recr.png'
arxiv: 'https://arxiv.org/abs/2611.04164'
code: 'https://github.com/lixuan27/ReCR'
citation: 'He, L., Je, J., You, Y., & Guibas, L. (2026). What Remains in Sight? Autoregressive Video Decoding as Representation-Guided Context Rewriting. Advances in Neural Information Processing Systems.'
authors: 'Lixuan He, Jihyeon Je, <b>Yang You</b>, Leonidas Guibas'
bibtex: |
  @inproceedings{he2026recr,
    title     = {What Remains in Sight? Autoregressive Video Decoding as Representation-Guided Context Rewriting},
    author    = {He, Lixuan and Je, Jihyeon and You, Yang and Guibas, Leonidas},
    booktitle = {Advances in Neural Information Processing Systems},
    year      = {2026}
  }
---

Thumbnail: [Figure 2](https://arxiv.org/html/2611.04164v1) from this paper by Lixuan He, Jihyeon Je, Yang You, and Leonidas Guibas (2026), reproduced unchanged under [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/).
