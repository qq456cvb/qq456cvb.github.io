---
layout: compress
permalink: /projects/img2cad
---

<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="description"
        content="Reverse Engineering 3D CAD Models from Images through VLM-Assisted Conditional Factorization">
  <meta name="keywords" content="Image-to-CAD, Reverse Engineering, Vision Language Model">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Img2CAD: Reverse Engineering 3D CAD Models from Images through VLM-Assisted Conditional Factorization</title>

  <link href="https://fonts.googleapis.com/css?family=Google+Sans|Noto+Sans|Castoro"
        rel="stylesheet">

  <link rel="stylesheet" href="/projects/img2cad/css/bulma.min.css">
  <link rel="stylesheet" href="/projects/img2cad/css/bulma-carousel.min.css">
  <link rel="stylesheet" href="/projects/img2cad/css/bulma-slider.min.css">
  <link rel="stylesheet" href="/projects/img2cad/css/fontawesome.all.min.css">
  <link rel="stylesheet"
        href="https://cdn.jsdelivr.net/gh/jpswalsh/academicons@1/css/academicons.min.css">
  <link rel="stylesheet" href="/projects/img2cad/css/index.css">
  <link rel="icon" href="/projects/img2cad/images/favicon.svg">

  <script type="module" src="https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script defer src="/projects/img2cad/js/fontawesome.all.min.js"></script>
  <script src="/projects/img2cad/js/bulma-carousel.min.js"></script>
  <script src="/projects/img2cad/js/bulma-slider.min.js"></script>
  <script src="/projects/img2cad/js/index.js?v={{ site.time | date: '%Y%m%d%H%M%S' }}"></script>

  <style>
    /* Basic styling for tabs */
    .tab {
      display: flex; /* Enables Flexbox */
      justify-content: center; /* Centers children horizontally */
      align-items: center; /* Centers children vertically */
      margin-bottom: 4px; /* Adds a small space below the tabs */
      /* border: 1px solid #ccc; 
      background-color: #f1f1f1; */
        }
        .tab button {
            background-color: #f1f1f1;
            float: left; /* Align buttons side by side */
            border: none; /* No borders on the buttons */
            outline: none;
            cursor: pointer; /* Pointer cursor on hover */
            padding: 10px 20px; /* Vertical and horizontal padding */
            transition: 0.3s; /* Smooth transition for hover effect */
            font-size: 16px; /* Larger font size for better readability */
            border-radius: 5px; /* Rounded corners for a softer look */
        }
        .tab button:hover {
            background-color: #ddd; /* Darker shade on hover */
            box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2); /* Shadow effect for depth */
        }
        .tab button.active {
            background-color: #b2e6fa; /* White background for the active tab */
            box-shadow: 0 4px 8px 0 rgba(0,0,0,0.1); /* Lighter shadow for active tab */
        }
        .models-flex-container {
            display: flex;
            justify-content: center; /* Centers the items horizontally */
            align-items: flex-start; /* Aligns items from the top */
            flex-wrap: wrap; /* Allows items to wrap onto the next line as needed */
            gap: 0px; /* Spacing between each model container */
        }
        .models-flex-container-robust {
            display: flex;
            justify-content: center; /* Centers the items horizontally */
            align-items: flex-start; /* Aligns items from the top */
            flex-wrap: wrap; /* Allows items to wrap onto the next line as needed */
            gap: 0px; /* Spacing between each model container */
        }
        .model-container-robust {
            width: 22%; /* Adjust the width as needed */
            text-align: center; /* Centers the caption text */
            height: 200px; /* Fixed height for both model-viewer and img container */
            display: flex;
            flex-direction: column;
            justify-content: center; /* Vertically centers the img within the container */
        }
        .model-container {
            width: 19%; /* Adjust the width as needed */
            text-align: center; /* Centers the caption text */
            height: 200px; /* Fixed height for both model-viewer and img container */
            display: flex;
            flex-direction: column;
            justify-content: center; /* Vertically centers the img within the container */
        }
        model-viewer {
            width: 100%;
            height: 200px; /* Fixed height as specified */
            display: block;
        }
        .img-container {
            width: 100%; /* Takes full width of the model-container */
            height: 100%; /* Takes full height of the model-container */
            display: flex;
            align-items: center; /* Centers img vertically */
            justify-content: center; /* Centers img horizontally */
            overflow: hidden; /* Prevents any overflow from the container */
        }
        .img-container img {
            max-width: 100%; /* Ensures img does not exceed the container width */
            height: auto; /* Adjusts height automatically to maintain aspect ratio */
        }
        .caption {
            font-size: 14px; /* Adjust the font size as needed */
            color: #333; /* Adjust the text color as needed */
            margin-top: 10px; /* Adds a small space above the caption */
        }
</style>
</head>


<body>

<section class="hero">
  <div class="hero-body">
    <div class="container is-max-desktop">
      <div class="columns is-centered">
        <div class="column has-text-centered">
          <h1 class="title is-1 publication-title">Img2CAD: Reverse Engineering 3D CAD Models from Images through VLM-Assisted Conditional Factorization</h1>
          <div class="conference-badge" style="margin-bottom: 20px;">
            <span style="background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: white; padding: 8px 16px; border-radius: 20px; font-weight: bold; font-size: 18px;">SIGGRAPH Asia 2025</span>
          </div>
          <div class="authors-section">
            <p class="authors" style="font-size: 18px; line-height: 1.4; margin-bottom: 10px;">
              <a href="https://qq456cvb.github.io/" style="color: #0ea5e9; text-decoration: none;">Yang You<sup>1</sup></a>, <a href="https://mikacuy.github.io/" style="color: #0ea5e9; text-decoration: none;">Mikaela Angelina Uy<sup>1,2</sup></a>, <a href="https://hanjq17.github.io/" style="color: #0ea5e9; text-decoration: none;">Jiaqi Han<sup>1</sup></a>, <a href="https://scholar.google.com/citations?user=dXOWqeYAAAAJ&hl=en" style="color: #0ea5e9; text-decoration: none;">Rahul Thomas<sup>1</sup></a>, <a href="https://pku.ai/author/haotong-zhang/" style="color: #0ea5e9; text-decoration: none;">Haotong Zhang<sup>3</sup></a>,<br>
              <a href="https://profiles.stanford.edu/yi-du" style="color: #0ea5e9; text-decoration: none;">Yi Du<sup>1</sup></a>, <a href="https://hanshengchen.com/" style="color: #0ea5e9; text-decoration: none;">Hansheng Chen<sup>1</sup></a>, <a href="https://francisengelmann.github.io/" style="color: #0ea5e9; text-decoration: none;">Francis Engelmann<sup>1</sup></a>, <a href="https://scholar.google.com/citations?user=LkpA-L0AAAAJ&hl=en" style="color: #0ea5e9; text-decoration: none;">Suya You<sup>4</sup></a>, <a href="https://geometry.stanford.edu/" style="color: #0ea5e9; text-decoration: none;">Leonidas Guibas<sup>1</sup>✉</a>
            </p>
            <p class="affiliations" style="font-size: 14px; color: #666; line-height: 1.3; margin-bottom: 5px;">
              <sup>1</sup>Stanford University; <sup>2</sup>NVIDIA; <sup>3</sup>Peking University; <sup>4</sup>DEVCOM Army Research Laboratory;
            </p>
            <p class="contributions" style="font-size: 12px; color: #888; font-style: italic;">
              ✉ Corresponding Author
            </p>
          </div>
          <div class="column has-text-centered">
            <div class="publication-links">
              <!-- PDF Link. -->
              <span class="link-block">
                <a href="https://arxiv.org/abs/2408.01437"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fas fa-file-pdf"></i>
                  </span>
                  <span>Arxiv</span>
                </a>
              </span>
              <!-- Code Link. -->
              <span class="link-block">
                <a href="https://github.com/qq456cvb/Img2CAD"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fab fa-github"></i>
                  </span>
                  <span>Code</span>
                </a>
              </span>
              
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>
<div class="container is-max-desktop">
  <div class="content">
    <img src="/projects/img2cad/images/teaser.gif" />
  </div>
</div>
<section class="section">
  <div class="container is-max-desktop">
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Abstract</h2>
        <div class="content">
          <img src="/projects/img2cad/images/teaser.png" />
        </div>
        <div class="content has-text-justified">
          <p>
            Reverse engineering 3D computer-aided design (CAD) models from images is an important task for many downstream applications including interactive editing, manufacturing, architecture, robotics, etc. The difficulty of the task lies in vast representational disparities between the CAD output and the image input. CAD models are precise, programmatic constructs that involves sequential operations combining discrete command structure with continuous attributes -- making it challenging to learn and optimize in an end-to-end fashion. 
            Concurrently, input images introduce inherent challenges such as photometric variability and sensor noise, complicating the reverse engineering process. In this work, we introduce a novel approach that conditionally factorizes the task into two sub-problems. First, we leverage vision-language foundation models (VLMs), a finetuned Llama3.2, to predict the global <em>discrete base structure</em> with semantic information. Second, we propose TrAssembler that conditioned on the discrete structure with semantics predicts the <em>continuous attribute</em> values.
            To support the training of our TrAssembler, we further constructed an annotated CAD dataset of common objects from ShapeNet. Putting all together, our approach and data demonstrate significant first steps towards CAD-ifying images in the wild.
          </p>
        </div>
      </div>
    </div>
    <br>
    <div class="container is-max-desktop">
      <!-- method. -->
      <div class="columns is-centered has-text-centered">
        <div class="column is-five-sixths">
          <h2 class="title is-3">Pipeline</h2>
          <div class="content">
            <img src="/projects/img2cad/images/network_arch.png" />
          </div>
          <div class="content has-text-justified">
            <p>
              The task of reverse engineering a 3D model from input images is a challenging task in the computer graphics and vision literature due to the discrete-continuous nature of the problem, requiring the learning of the combinatorial space of shape and program structure and their corresponding continuous attributes. Our approach tackles the challenging image-to-CAD problem for common objects through <b>conditionally factorizing</b> the task into two sub-problems. First, we leverage on the capabilities of finetuned large foundation models (i.e., Llama 3.2) to predict the global <b>discrete base structure</b> of the shape from a single input image. This discrete problem includes inferring the <b>semantics</b>semantics parts that are present in the image as well as providing the <b>CAD structure</b>, i.e. command types, of each underlying part. We then propose a novel transformer-based model that conditioned on this semantic-informed, discrete base structure predicts the <b>continuous attributes</b> for the sequence of CAD commands for each semantic part.
            </p>
          </div>
        </div>
      </div>
    <br>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Qualitative Results on ShapeNet</h2>
        <!-- <div class="tab">
          <button class="tablinks" onclick="openTab(event, 'Tab1')">Chair</button>
          <button class="tablinks" onclick="openTab(event, 'Tab2')">Table</button>
          <button class="tablinks" onclick="openTab(event, 'Tab3')">Cabinet</button>
        </div> -->
        <div id="Tab1" class="tabcontent">
          <div class="models-flex-container">
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/42569_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/44319_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/40338_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/43477_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/37874_gt.png" alt="GT"/>
              </div>
            </div>

            <div style="width: 100%; height: 0;"></div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/42569_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/44319_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/40338_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/43477_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/37874_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
          </div>
          
          <div class="models-flex-container">
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/40783_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/31105_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/3271_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/29373_gt.png" alt="GT"/>
              </div>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/19167_gt.png" alt="GT"/>
              </div>
            </div>

            <div style="width: 100%; height: 0;"></div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/40783_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/31105_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/3271_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/29373_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/19167_ours.glb" alt="Prediction" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
          </div>
        </div>

      </div>
    </div>
    </div>
  </div>
</section>

<footer class="footer">
  <div class="container">
    <div class="content has-text-centered">
    </div>
    <div class="columns is-centered">
      <div class="column is-8">
        <div class="content">
          <p>
            This website is licensed under a <a rel="license"
                                                href="http://creativecommons.org/licenses/by-sa/4.0/">Creative
            Commons Attribution-ShareAlike 4.0 International License</a>.
          </p>
          <p>
            Website template from <a href="https://github.com/nerfies/nerfies.github.io">Nerfies</a>.
          </p>
        </div>
      </div>
    </div>
  </div>
</footer>
</body>
</html>