---
title: "CPPF: Towards Robust Category-Level 9D Pose Estimation in the Wild"
collection: publications
permalink: /publications/cppf
excerpt: 'This paper addresses category-level 9D pose estimation in the wild using a single RGB-D frame. Inspired by traditional point pair features (PPFs), we introduce a novel Category-level PPF (CPPF) voting method for accurate, robust, and generalizable 9D pose estimation. Our approach samples numerous point pairs on an object, predicting SE(3)-invariant voting statistics for object centers, orientations, and scales. We propose a coarse-to-fine voting algorithm to filter out noisy samples and refine predictions. An auxiliary binary classification task helps eliminate false positives in orientation voting. To ensure robustness, our sim-to-real pipeline trains on synthetic point clouds, except for geometrically ambiguous objects.'
date: '2022-03-01'
venue: 'CVPR'
image: '/images/cppf.jpg'
arxiv: 'https://arxiv.org/abs/2203.03089'
code: 'https://github.com/qq456cvb/CPPF'
site: '/projects/cppf'
weight: 210
citation: ''
authors: '<b>Yang You</b>, Ruoxi Shi, Weiming Wang, Cewu Lu'
---