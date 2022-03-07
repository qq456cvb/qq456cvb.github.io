---
title: "CPPF: Towards Robust Category-Level 9D Pose Estimation in the Wild"
collection: publications
permalink: /publications/cppf
excerpt: 'In this paper, we tackle the problem of category-level 9D pose estimation in the wild, given a single RGB-D frame. Drawing inspirations from traditional point pair features (PPFs), in this paper, we design a novel Category-level PPF (CPPF) voting method to achieve accurate, robust and generalizable 9D pose estimation in the wild. To obtain robust pose estimation, we sample numerous point pairs on an object, and for each pair our model predicts necessary SE(3)-invariant voting statistics on object centers, orientations and scales. A novel coarse-to-fine voting algorithm is proposed to eliminate noisy point pair samples and generate final predictions from the population. To get rid of false positives in the orientation voting process, an auxiliary binary disambiguating classification task is introduced for each sampled point pair. In order to detect objects in the wild, we carefully design our sim-to-real pipeline by training on synthetic point clouds only, unless objects have ambiguous poses in geometry.'
date: '2022-03-01'
venue: 'CVPR'
image: '/images/cppf.jpg'
arxiv: '/files/cppf.pdf'
code: 'https://github.com/qq456cvb/CPPF'
weight: 210
citation: ''
authors: 'Yang You, Ruoxi Shi, Weiming Wang, Cewu Lu'
---