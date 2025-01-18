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
  <script src="/projects/img2cad/js/index.js"></script>

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
          <h2>Yang You, Mikaela Angelina Uy, Jiaqi Han, Rahul Thomas, Haotong Zhang, Suya You, Leonidas Guibas</h2>
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
              
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>


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
            Concurrently, input images introduce inherent challenges such as photometric variability and sensor noise, complicating the reverse engineering process. In this work, we introduce a novel approach that conditionally factorizes the task into two sub-problems. First, we leverage large foundation models, particularly GPT-4V, to predict the global discrete structure with semantic information. Second, we propose TrAssembler that conditioned on the discrete structure with semantics predicts the continuous attribute values.
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
              The task of reverse engineering a 3D model from input images is a challenging task in the computer graphics and vision literature due to the discrete-continuous nature of the problem, requiring the learning of the combinatorial space of shape and program structure and their corresponding continuous attributes. Our approach tackles the challenging image-to-CAD problem for common objects through <b>conditionally factorizing</b> the task into two sub-problems. First, we leverage on the capabilities of large foundation models (i.e., GPT-4V) to predict the global <b>discrete base structure</b> of the shape from a single input image. This discrete problem includes inferring the <b>semantics</b>semantics parts that are present in the image as well as providing the <b>CAD structure</b>, i.e. command types, of each underlying part. We then propose a novel transformer-based model that conditioned on this semantic-informed, discrete base structure predicts the <b>continuous attributes</b> for the sequence of CAD commands for each semantic part.
            </p>
          </div>
        </div>
      </div>
    <br>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Qualitative Comparison on ShapeNet</h2>
        <div class="tab">
          <button class="tablinks" onclick="openTab(event, 'Tab1')">Chair</button>
          <button class="tablinks" onclick="openTab(event, 'Tab2')">Table</button>
          <button class="tablinks" onclick="openTab(event, 'Tab3')">Cabinet</button>
        </div>
        <div id="Tab1" class="tabcontent">
          <div class="models-flex-container">

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/37821_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/37821_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/37821_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/37821_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/37821_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/36957_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/36957_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/36957_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/36957_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/36957_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

              <div class="model-container">
                <div class="img-container">
                  <img src="/projects/img2cad/meshes/shapenet/42713_gt.png" alt="Input"/>
                </div>
                <p class="caption">Input</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/42713_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">GPT-only</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/42713_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Image-3D-CAD</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/42713_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">DeepCAD-End2End</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/42713_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Ours</p>
              </div>
              
          </div>
        </div>

        <div id="Tab2" class="tabcontent">
          <div class="models-flex-container">

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/33007_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/33007_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/33007_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/33007_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/33007_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/19665_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/19665_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/19665_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/19665_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/19665_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

              <div class="model-container">
                <div class="img-container">
                  <img src="/projects/img2cad/meshes/shapenet/26488_gt.png" alt="Input"/>
                </div>
                <p class="caption">Input</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/26488_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">GPT-only</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/26488_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Image-3D-CAD</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/26488_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">DeepCAD-End2End</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/26488_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Ours</p>
              </div>
              
          </div>
        </div>


        <div id="Tab3" class="tabcontent">
          <div class="models-flex-container">

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/47154_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/47154_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/47154_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/47154_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/47154_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/shapenet/46586_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/46586_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/46586_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/46586_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/shapenet/46586_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

              <div class="model-container">
                <div class="img-container">
                  <img src="/projects/img2cad/meshes/shapenet/46553_gt.png" alt="Input"/>
                </div>
                <p class="caption">Input</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/46553_gpt-only.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">GPT-only</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/46553_img-3d-cad.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Image-3D-CAD</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/46553_deepcad-end2end.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">DeepCAD-End2End</p>
              </div>

              <div class="model-container">
                <model-viewer src="/projects/img2cad/meshes/shapenet/46553_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
                </model-viewer>
                <p class="caption">Ours</p>
              </div>
              
          </div>
        </div>


      </div>
    </div>

    <!-- <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Qualitative Comparison on Pix3D<br>(Real Images in the Wild)</h2>
        <div class="content">
          <img src="/projects/img2cad/images/dist-cat.png" />
          <img src="/projects/img2cad/images/dist-size.png" width="44%" />
          <img src="/projects/img2cad/images/dist-pose.png" width="57%" />
          <img src="/projects/img2cad/images/dist-occ.png" width="55%" />
        </div>
      </div>
    </div> -->

    <br>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Robustness on Random Viewpoints</h2>
          <div class="models-flex-container">

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/2360_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/2360_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
            <div style="width: 10%; height: 200px;"></div>
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/2858_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/2858_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>

            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/43149_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/43149_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
            <div style="width: 10%; height: 200px;"></div>
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/41067_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/41067_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>



            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/19416_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/19416_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>
            
            <div style="width: 10%; height: 200px;"></div>
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/21700_gt.png" alt="Input"/>
              </div>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/21700_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
            </div>



            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/37821_gt.png" alt="Input"/>
              </div>
              <p class="caption">Input</p>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/37821_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
              <p class="caption">Ours</p>
            </div>
            
            <div style="width: 10%; height: 200px;"></div>
            <div class="model-container">
              <div class="img-container">
                <img src="/projects/img2cad/meshes/robust/26150_gt.png" alt="Input"/>
              </div>
              <p class="caption">Input</p>
            </div>

            <div class="model-container">
              <model-viewer src="/projects/img2cad/meshes/robust/26150_ours.glb" alt="3D Model" ar ar-modes="webxr scene-viewer quick-look" environment-image="neutral" auto-rotate camera-controls ar-status="not-presenting">
              </model-viewer>
              <p class="caption">Ours</p>
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

<script>
  function openTab(evt, tabName) {
    var i, tabcontent, tablinks;
    var parent = evt.currentTarget.parentNode.parentNode; // Get the grandparent container of the button
    tabcontent = parent.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
        tabcontent[i].style.display = "none";
    }
    tablinks = parent.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
        tablinks[i].className = tablinks[i].className.replace(" active", "");
    }
    document.getElementById(tabName).style.display = "block";
    evt.currentTarget.className += " active";
  }
  document.addEventListener("DOMContentLoaded", function() {
      var tablinks = document.getElementsByClassName("tablinks");
      for (var i = 0; i < tablinks.length; i += 3) {
          tablinks[i].click();
      }
  });
</script>
</html>