---
permalink: /projects/ukpgan
classes: wide
---

<h1 align="center">
UKPGAN: A General Self-Supervised Keypoint Detector
</h1>

<p align='center'>
<img align="center" src='/images/ukpgan.jpg' width='70%'> </img>
</p>

<div align="center">
<h3>
<a href="https://qq456cvb.github.io">Yang You</a>, Wenhai Liu, Yanjie Ze, Yong-Lu Li, Weiming Wang, Cewu Lu
<br>
<br>
CVPR 2022
<br>
<br>
<a href='https://arxiv.org/pdf/2011.11974.pdf'>
  <img src='https://img.shields.io/badge/Paper-PDF-orange?style=flat&logo=arxiv&logoColor=orange' alt='Paper PDF'>
</a>
<a href='https://github.com/qq456cvb/UKPGAN'>
<img src='https://img.shields.io/badge/Github-Code-green?style=flat&logo=github' alt='Code'>
</a>
  <!-- <a href='https://colab.research.google.com/'>
    <img src='https://colab.research.google.com/assets/colab-badge.svg' alt='Google Colab'>
  </a> -->
<br>
</h3>
</div>
 
UKPGAN is a **self-supervised** 3D keypoint detector on both rigid/non-rigid objects and real scenes. Note that our keypoint detector solely depends on local features and is both translational and rotational invariant.

# Abstract
Keypoint detection is an essential component for the object registration and alignment. In this work, we reckon keypoint detection as information compression, and force the model to distill out irrelevant points of an object. Based on this, we propose UKPGAN, a general **self-supervised** 3D keypoint detector where keypoints are detected so that they could reconstruct the original object shape. Two modules: **GAN-based keypoint sparsity control** and **salient information distillation** modules are proposed to locate those important keypoints. Extensive experiments show that our keypoints align well with human annotated keypoint labels, and can be applied to SMPL human bodies under various non-rigid deformations. Furthermore, our keypoint detector trained on clean object collections generalizes well to real-world scenarios, thus further improves geometric registration when combined with off-the-shelf point descriptors. Repeatability experiments show that our model is stable under both rigid and non-rigid transformations, with local reference frame estimation. 