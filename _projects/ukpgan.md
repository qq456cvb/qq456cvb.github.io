---
permalink: /projects/ukpgan
classes: wide
---

<h1 align="center">
UKPGAN: A General Self-Supervised Keypoint Detector
</h1>

<p align='center'>
<img align="center" src='/images/ukpgan.jpg' width='70%'/>
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
<img src='https://img.shields.io/badge/Github-Code-green?style=flat&logo=github' alt='Code'/>
</a>
  <!-- <a href='https://colab.research.google.com/'>
    <img src='https://colab.research.google.com/assets/colab-badge.svg' alt='Google Colab'>
  </a> -->
<br>
</h3>
</div>
 
UKPGAN is a **self-supervised** 3D keypoint detector on both rigid/non-rigid objects and real scenes. Note that our keypoint detector solely depends on local features and is both translational and rotational invariant.

<p style="text-align:center;">
<iframe width="640" height="360" align="middle" src="https://www.youtube.com/embed/IyGzkdR5MLU" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</p>

# Abstract
Keypoint detection is an essential component for the object registration and alignment. In this work, we reckon keypoint detection as information compression, and force the model to distill out irrelevant points of an object. Based on this, we propose UKPGAN, a general **self-supervised** 3D keypoint detector where keypoints are detected so that they could reconstruct the original object shape. Two modules: **GAN-based keypoint sparsity control** and **salient information distillation** modules are proposed to locate those important keypoints. Extensive experiments show that our keypoints align well with human annotated keypoint labels, and can be applied to SMPL human bodies under various non-rigid deformations. Furthermore, our keypoint detector trained on clean object collections generalizes well to real-world scenarios, thus further improves geometric registration when combined with off-the-shelf point descriptors. Repeatability experiments show that our model is stable under both rigid and non-rigid transformations, with local reference frame estimation. 

# Method Overview

<p align="center">
<figure style='width:90%'>
<img src="/images/ukpgan/arch.jpg" alt="Architecture" style="width:100%">
<figcaption style="text-align: left;"><b>Fig.1 - Our network architecture.</b> We first extract point-wise rotation invariant features and then output keypoint probabilities and semantic embeddings through two MLPs, respectively. GAN is leveraged to control keypoint sparsity, and salient information distillation is utilized to distill most salient features. A decoder is concatenated to reconstruct original point clouds.</figcaption>
</figure>
</p>

# Qualitative Results

## Real-world Scenes
<div align='center'>
{% assign width = 99 | divided_by: 2 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/3dmatch' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

## SMPL Models
### With NMS
<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/smpl_nms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

### Without NMS (*p* > 0.5)
<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/smpl_nonms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

## ShapeNet Models
### With NMS
- Chairs

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/chair_nms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

- Tables

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/table_nms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

- Airplanes

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/airplane_nms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

### Without NMS (*p* > 0.5)
- Chairs

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/chair_nonms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

- Tables

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/table_nonms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

- Airplanes

<div align='center'>
{% assign width = 99 | divided_by: 5 %}
{% for glb in site.static_files %}
{% if glb.path contains 'models/ukpgan/airplane_nonms' %}
  <model-viewer style="width:{{ width }}%; height: 250px; display:inline-block;" src="{{ glb.path }}" alt="{{ glb.path }}" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
  </model-viewer>
{% endif %}
{% endfor %}
</div>

# Citation
<pre>
@inproceedings{you2022ukpgan,
  title={UKPGAN: A General Self-Supervised Keypoint Detector},
  author={You, Yang and Liu, Wenhai and Ze, Yanjie and Li, Yong-Lu and Wang, Weiming and Lu, Cewu},
  booktitle={Proceedings of the IEEE/CVF Conference on Computer Vision and Pattern Recognition},
  year={2022}
}
</pre>

<script type="module" src="https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js"></script>