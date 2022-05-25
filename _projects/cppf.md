---
permalink: /projects/cppf
classes: wide
---

<h1 align="center">
CPPF: Towards Robust Category-Level 9D Pose Estimation in the Wild
</h1>

<p align='center'>
<img align="center" src='/images/cppf.jpg' width='50%'/>
</p>

<div align="center">
<h3>
<a href="https://qq456cvb.github.io">Yang You</a>, Ruoxi Shi, Weiming Wang, Cewu Lu
<br>
<br>
CVPR 2022
<br>
<br>
<a href='https://arxiv.org/pdf/2203.03089.pdf'>
<img src='https://img.shields.io/badge/Paper-PDF-orange?style=flat&logo=arxiv&logoColor=orange' alt='Paper PDF'/>
</a>
<a href='https://github.com/qq456cvb/CPPF'>
<img src='https://img.shields.io/badge/Github-Code-green?style=flat&logo=github' alt='Code'/>
</a>
<!-- <a href='https://colab.research.google.com/'>
<img src='https://colab.research.google.com/assets/colab-badge.svg' alt='Google Colab'>
</a> -->

<br>
</h3>
</div>

CPPF is a pure sim-to-real method that achieves 9D pose estimation in the wild. Our model is trained solely on ShapeNet synthetic models (without any real-world background pasting), and could be directly applied to real-world scenarios (i.e., NOCS REAL275, SUN RGB-D, etc.). CPPF achieves the goal by using only local $SE3$-invariant geometric features, and leverages a bottom-up voting scheme, which is quite different from previous end-to-end learning methods. Our model is robust to noise, and can obtain decent predictions even if only bounding box masks are provided.

<p style="text-align:center;">
<iframe width="640" height="360" src="https://www.youtube.com/embed/MbR3Lq1kJaM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</p>

# Abstract
In this paper, we tackle the problem of category-level 9D pose estimation in the wild, given a single RGB-D frame. Using supervised data of real-world 9D poses is tedious and erroneous, and also fails to generalize to unseen scenarios. Besides, category-level pose estimation requires a method to be able to generalize to unseen objects at test time, which is also challenging. Drawing inspirations from traditional point pair features (PPFs), in this paper, we design a novel Category-level PPF (CPPF) voting method to achieve accurate, robust and generalizable 9D pose estimation in the wild. To obtain robust pose estimation, we sample numerous point pairs on an object, and for each pair our model predicts necessary SE(3)-invariant voting statistics on object centers, orientations and scales. A novel coarse-to-fine voting algorithm is proposed to eliminate noisy point pair samples and generate final predictions from the population. To get rid of false positives in the orientation voting process, an auxiliary binary disambiguating classification task is introduced for each sampled point pair. In order to detect objects in the wild, we carefully design our sim-to-real pipeline by training on synthetic point clouds only, unless objects have ambiguous poses in geometry. Under this circumstance, color information is leveraged to disambiguate these poses. Results on standard benchmarks show that our method is on par with current state of the arts with real-world training data. Extensive experiments further show that our method is robust to noise and gives promising results under extremely challenging scenarios.


# Method Overview
<figure style='width:25%;display:inline-block;margin-right:10%'>
<!-- <img src="/images/cppf/centervotes.png" alt="CenterVotes" style="width:100%">
<figcaption style="text-align: left;"><b>Fig.1 - Center voting scheme.</b> For each point pair, candidate centers are generated on the dash circle for an interval of $\frac{2\pi}{K}$.</figcaption> -->
<img src="/images/cppf/centerstat.png" alt="CenterVotes" style="width:100%">
<figcaption style="text-align: left;">
<b>Fig.1 - Center voting scheme.</b>
Take a bowl as an example, our model would predict
$\mu=\|\overrightarrow{\mathbf{p}_1\mathbf{c}}\|_2$ and $\nu=\|\overrightarrow{\mathbf{c}\mathbf{o}}\|_2$, where $\mathbf{c}$
is the perpendicular foot on $\overrightarrow{\mathbf{p}_1\mathbf{p}_2}$ opposite $\mathbf{o}$. Once $\mu$ and $\nu$ are fixed, object center would possibly lie on the red dash circle.
</figcaption>
</figure>
<figure style='width:30%;display:inline-block;'>
<img src="/images/cppf/orivotes.png" alt="Orientationvotes" style="width:100%">
<figcaption style="text-align: left;"><b>Fig.2 - Orientation Voting scheme.</b> <b>Left:</b> Once $\alpha$ is predicted, the candidate orientation vector will lie on a cone with one degree of freedom. <b>Right:</b> For two point pairs $\mathbf{p}_1$, $\mathbf{p}_2$ and $\mathbf{p}_1$, $\mathbf{p}_3$, we generate candidate votes and count them into bins, the final prediction is the one with the most votes.</figcaption>
</figure>
<br style="clear:both" />
For each sampled point pair lying on an object, we generate both center votes and orientation votes as illustrated above; while votes for scales are the average of predicted scales for all pairs. The network architecture predicting these voting targets are illustrated below:

<p align="center">
<figure style='width:70%'>
<img src="/images/cppf/arch.jpg" alt="Architecture" style="width:100%">
<figcaption style="text-align: left;"><b>Fig.3 - Our network architecture.</b> For each input point pair, we first extract $SE(3)$ invariant embeddings for each point. Then the two embeddings are concatenated with the original PPF feature, and fed into multi-layer perceptions to predict final outputs.</figcaption>
</figure>
</p>

# Quantitative Results
<figure style='width:60%;align:center'>
<img src="/images/cppf/quan.png" alt="Architecture" style="width:100%">
<figcaption style="text-align: left;"><b>Fig.4 - Performance comparison of various methods.</b> <i>Syn.(O)</i> means synthetic ShapeNet objects only; while <i>Syn.(O+B)</i> means ShapeNet models rendered with real backgrounds. <i>Real</i> means the real-world training data provided by NOCS. The best using real-world training data is marked <span style="color:blue;">blue</span>, and the best using synthetic training data is marked <span style="color:red;">red</span>. *Our model only leverages RGB information for laptops.</figcaption>
</figure>

# Qualitative Results
## NOCS REAL275 with Instance Segmentation Masks
<figure style='width:40%;align:center'>
<img src="/images/cppf/nocsinst.png" alt="Architecture" style="width:100%">
</figure>

## NOCS REAL275 with Bounding Box Masks
<figure style='width:60%;align:center'>
<img src="/images/cppf/nocsbbox.png" alt="Architecture" style="width:100%">
</figure>

## SUN RGB-D in the Wild
<figure style='width:40%;align:center'>
<img src="/images/cppf/sunrgbd.png" alt="Architecture" style="width:100%">
</figure>

# Citation
<pre>
@inproceedings{you2022cppf,
  title={CPPF: Towards Robust Category-Level 9D Pose Estimation in the Wild},
  author={You, Yang and Shi, Ruoxi and Wang, Weiming and Lu, Cewu},
  booktitle={Proceedings of the IEEE/CVF Conference on Computer Vision and Pattern Recognition},
  year={2022}
}
</pre>