---
title: "Skeleton Merger, an Unsupervised Aligned Keypoint Detector"
collection: publications
permalink: /publications/skeleton
excerpt: ' In this paper, we propose an unsupervised aligned keypoint detector, Skeleton Merger, which utilizes skeletons to reconstruct objects. It is based on an Autoencoder architecture. The encoder proposes keypoints and predicts activation strengths of edges between keypoints. The decoder performs uniform sampling on the skeleton and refines it into small point clouds with pointwise offsets. Then the activation strengths are applied and the sub-clouds are merged. Composite Chamfer Distance (CCD) is proposed as a distance between the input point cloud and the reconstruction composed of sub-clouds masked by activation strengths.'
date: '2021-02-01'
venue: 'CVPR'
image: '/images/skeleton.jpg'
arxiv: 'https://arxiv.org/abs/2103.10814'
code: 'https://github.com/eliphatfs/SkeletonMerger'
weight: 85
citation: 'Shi, R., Xue, Z., You, Y., & Lu, C. (2021). Skeleton Merger: an Unsupervised Aligned Keypoint Detector. arXiv preprint arXiv:2103.10814.'
authors: 'Ruoxi Shi, Zhengrong Xue, Yang You, Cewu Lu'
---