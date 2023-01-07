---
title: "Semantic 3D Reconstruction from a Collection of Images"
collection: sideprojects
permalink: /sideprojects/slammask
excerpt: This project implemented real-time indoor objects segmentation and 3D reconstruction. We used fine-tuned MaskRCNN doing instance segmentation for 51 different objects and build 3D model by Truncated Signed Distance Function Volume Reconstruction with semantic predicted from MaskRCNN. By now, there are two steps to execute the pipe line. First, download datasets from RGB-D SLAM datasets. Using mask_process.py to generate mask images for specific datasets. Second, change configuration in kernel.cpp to execute TSDF.
code: 'https://github.com/qq456cvb/SLAM-MaskRCNN'
---