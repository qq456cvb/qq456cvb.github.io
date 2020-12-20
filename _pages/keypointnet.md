---
layout: keypointnet-single
permalink: /keypointnet/
title: "KeypointNet"
excerpt: "KeypointNet"
author_profile: false
redirect_from: /keypointnet.html
sidebar: false
---

{% include base_path %}

**Full dataset is available now!** KeypointNet is a large-scale and diverse 3D keypoint dataset that contains
83,231 keypoints and 8,329 3D models from 16 object categories, by leveraging numerous human annotations, based on ShapeNet models. Our paper is available on <a href="https://arxiv.org/pdf/2002.12687.pdf" target="_blank">Arxiv</a> and is accepted to CVPR 2020. **Example usage and benchmark scripts can be found on <a href="https://github.com/qq456cvb/KeypointNet" target="_blank">Github</a>**.

# Keypoint Data
Dataset can be downloaded from <a href="https://drive.google.com/drive/folders/1_d1TzZEF25Wy5kRj5ZugrgGeyf7xxu8F?usp=sharing" target="_blank">Google Drive</a> or <a href="http://youyangsoft.com/public/KeypointNet/ShapeNetCore.v2.zip" target="_blank">here</a> (Open link in new tab if necessary) or <a href="https://1drv.ms/u/s!Aj0NuSsDz6hDyF3LT3xaPkXK9DXC?e=kcrfSg" target="_blank">OneDrive</a>. Annotated JSON data is placed under **annotations**. In addition, we provide sampled point clouds (2048 points) for each ShapeNet model under **pcds**.

We have processed and cleaned labels for airplane (1022 models), bathtub (492 models), bed (146 models), bottle (380 models), cap (38 models), car (1002 models), chair (999 models), guitar (697 models), helmet (90 models), knife (270 models), laptop (439 models), motorcycle (298 models), mug (198 models), skateboard (141 models), table (1124 models) and vessel (910 models).

**UPDATE:** we have managed to add **color** information onto sampled point clouds and keypoints. In addition, since processing raw ShapeNet obj file as colored triangle meshes is painful, we have generated corresponding ply files (named **ShapeNetCore.v2.ply.zip**) with vertex colors (diffuse texture color), for those are interested in dealing with triangle meshes. We believe color is an important source when learning from 3D geometries.


# Citation
If you use the KeypointNet data or code, please cite:
```
@article{you2020keypointnet,
  title={KeypointNet: A Large-scale 3D Keypoint Dataset Aggregated from Numerous Human Annotations},
  author={You, Yang and Lou, Yujing and Li, Chengkun and Cheng, Zhoujun and Li, Liangwei and Ma, Lizhuang and Lu, Cewu and Wang, Weiming},
  journal={arXiv preprint arXiv:2002.12687},
  year={2020}
}
```