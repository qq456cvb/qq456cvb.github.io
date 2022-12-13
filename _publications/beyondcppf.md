---
title: "Go Beyond Point Pairs: A General and Accurate Sim2Real Object Pose Voting Method with Efficient Online Synthetic Training"
collection: publications
permalink: /publications/beyondcppf
excerpt: 'Object pose estimation is an important topic in 3D vision. Though most current state-of-the-art method that trains on real-world pose annotations achieve good results, the cost of such real-world training data is too high. In this paper, we propose a novel method for sim-to-real pose estimation, which is effective on both instance-level and category-level settings. The proposed method is based on the point-pair voting scheme from CPPF to vote for object centers, orientations, and scales. Unlike naive point pairs, to enrich the context provided by each voting unit, we introduce N-point tuples to fuse features from more than two points. Besides, a novel vote selection module is leveraged in order to discard those "bad" votes. Experiments show that our proposed method greatly advances the performance on both instance-level and category-level scenarios. Our method further narrows the gap between sim-to-real and real-training methods by generating synthetic training data online efficiently, while all previous sim-to-real methods need to generate data offline, because of their complex background synthesizing or photo-realistic rendering.'
date: '2022-11-01'
venue: 'Arxiv'
image: '/images/beyondcppf.jpg'
weight: 250
arxiv: 'https://arxiv.org/abs/2211.13398'
code: 'https://github.com/qq456cvb/BeyondPPF'
citation: 'You, Y., He, W., Liu, M. X., Wang, W., & Lu, C. (2022). Go Beyond Point Pairs: A General and Accurate Sim2Real Object Pose Voting Method with Efficient Online Synthetic Training. arXiv preprint arXiv:2211.13398.'
authors: '<b>Yang You</b>, Wenhao He, Michael Xu Liu, Weiming Wang, Cewu Lu'
---