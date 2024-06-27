---
title: "CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation by Vote Aggregation"
collection: publications
permalink: /publications/cppf++
excerpt: 'Object pose estimation constitutes a critical area within the domain of 3D vision. While contemporary state-of-the-art methods that leverage real-world pose annotations have demonstrated commendable performance, the procurement of such real-world training data incurs substantial costs. This paper focuses on a specific setting wherein only 3D CAD models are utilized as a priori knowledge, devoid of any background or clutter information. We introduce a novel method, CPPF++, designed for sim-to-real pose estimation. This method builds upon the foundational point-pair voting scheme of CPPF, reconceptualizing it through a probabilistic lens. To address the challenge of voting collision, we model voting uncertainty by estimating the probabilistic distribution of each point pair within the canonical space. This approach is further augmented by iterative noise filtering, employed to eradicate votes associated with backgrounds or clutters.
Additionally, we enhance the context provided by each voting unit by introducing $N$-point tuples. In conjunction with this methodological contribution, we present a new category-level pose estimation dataset, DiversePose 300. This dataset is specifically crafted to facilitate a more rigorous evaluation of current state-of-the-art methods, encompassing a broader and more challenging array of real-world scenarios.
Empirical results substantiate the efficacy of our proposed method, revealing a significant reduction in the disparity between simulation and real-world performance. '
date: '2024-6-13'
venue: 'TPAMI'
image: '/images/cppf++.png'
weight: 500
arxiv: 'https://arxiv.org/abs/2211.13398'
code: 'https://github.com/qq456cvb/CPPF2'
site: '/projects/cppf++'
citation: 'You, Y., He, W., Liu, J., Xiong, H., Wang, W., & Lu, C. (2022). CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation by Vote Aggregation. TPAMI 2024.'
authors: '<b>Yang You</b>, Wenhao He, Jin Liu, Hongkai Xiong, Weiming Wang, Cewu Lu'
---