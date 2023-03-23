---
title: "CRIN: Rotation-Invariant Point Cloud Analysis and Rotation Estimation via Centrifugal Reference Frame"
collection: publications
permalink: /publications/crin
excerpt: 'In this paper, we propose the CRIN, namely Centrifugal Rotation-Invariant Network. CRIN directly takes the coordinates of points as input and transforms local points into rotation-invariant representations via centrifugal reference frames. Aided by centrifugal reference frames, each point corresponds to a discrete rotation so that the information of rotations can be implicitly stored in point features. Unfortunately, discrete points are far from describing the whole rotation space. We further introduce a continuous distribution for 3D rotations based on points. Furthermore, we propose an attention-based down-sampling strategy to sample points invariant to rotations. A relation module is adopted at last for reinforcing the long-range dependencies between sampled points and predicts the anchor point for unsupervised rotation estimation. Extensive experiments show that our method achieves rotation invariance, accurately estimates the object rotation. Ablation studies validate the effectiveness of the network design.'
date: '2023-02-01'
venue: 'AAAI'
image: '/images/crin.jpg'
arxiv: 'https://arxiv.org/abs/2303.03101'
code: 'https://github.com/yokinglou/CRIN'
weight: 50
citation: 'Lou, Y., Ye, Z., You, Y., Jiang, N., Lu, J., Wang, W., ... & Lu, C. (2023). CRIN: Rotation-Invariant Point Cloud Analysis and Rotation Estimation via Centrifugal Reference Frame. arXiv preprint arXiv:2303.03101.'
authors: 'Lou, Yujing and Ye, Zelin and <b>You, Yang</b> and Jiang, Nianjuan and Lu, Jiangbo and Wang, Weiming and Ma, Lizhuang and Lu, Cewu'
---