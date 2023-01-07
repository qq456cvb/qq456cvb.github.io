---
title: "Tensorflow implementation of <em>Collaborative Learning for Deep Neural Networks</em>"
collection: sideprojects
permalink: /sideprojects/coll
excerpt: 'This is a Tensorflow implementation of the paper <em>Collaborative Learning for Deep Neural Networks</em>. I got 6.09% error rate after 300 epochs which is a slightly different from the paper. Maybe the split point is different from the paper: in my implementation splitting is done right after Batch Normalization and Relu of transition layers while it is not clear whether they split before or after or in the transition layers. Besides, in my implementation, gradients would pass through soft label targets (notation "q" in the paper).'
code: 'https://github.com/qq456cvb/Collaborative-Learning'
---