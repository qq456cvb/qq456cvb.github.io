---
layout: compress
permalink: /projects/pace
---

<html>
<head>
  <meta charset="utf-8">
  <meta name="description"
        content="Pose Annotations in Cluttered Environments">
  <meta name="keywords" content="PACE, dataset, pose estimation, clutter">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>PACE: Pose Annotations in Cluttered Environments</title>

  <link href="https://fonts.googleapis.com/css?family=Google+Sans|Noto+Sans|Castoro"
        rel="stylesheet">

  <link rel="stylesheet" href="/projects/pace/static/css/bulma.min.css">
  <link rel="stylesheet" href="/projects/pace/static/css/bulma-carousel.min.css">
  <link rel="stylesheet" href="/projects/pace/static/css/bulma-slider.min.css">
  <link rel="stylesheet" href="/projects/pace/static/css/fontawesome.all.min.css">
  <link rel="stylesheet"
        href="https://cdn.jsdelivr.net/gh/jpswalsh/academicons@1/css/academicons.min.css">
  <link rel="stylesheet" href="/projects/pace/static/css/index.css">
  <link rel="icon" href="/projects/pace/static/images/favicon.svg">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/swiper@11/swiper-bundle.min.css"/>

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script defer src="/projects/pace/static/js/fontawesome.all.min.js"></script>
  <script src="/projects/pace/static/js/bulma-carousel.min.js"></script>
  <script src="/projects/pace/static/js/bulma-slider.min.js"></script>
  <script src="/projects/pace/static/js/index.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/swiper@11/swiper-bundle.min.js"></script>

  <style>

    .grid-container {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      grid-template-rows: repeat(2, 1fr);
      gap: 10px; /* Adjust the gap between images as needed */
    }

    .grid-item {
      overflow: hidden;
      width: 100%;
      height: auto;
    }

    .grid-item img {
      width: 100%;
      height: auto;
      object-fit: cover; /* Adjust this as needed */
    }

    .swiper {
      width: 100%;
      height: auto;
      display: flex;
    }

    .swiper-slide {
      text-align: center;
      font-size: 18px;
      background: #fff;
      display: flex;
      justify-content: center;
      align-items: center;
    }
  </style>
</head>
<body>

<!-- <nav class="navbar" role="navigation" aria-label="main navigation">
  <div class="navbar-brand">
    <a role="button" class="navbar-burger" aria-label="menu" aria-expanded="false">
      <span aria-hidden="true"></span>
      <span aria-hidden="true"></span>
      <span aria-hidden="true"></span>
    </a>
  </div>
  <div class="navbar-menu">
    <div class="navbar-start" style="flex-grow: 1; justify-content: center;">
      <a class="navbar-item" href="https://keunhong.com">
      <span class="icon">
          <i class="fas fa-home"></i>
      </span>
      </a>

      <div class="navbar-item has-dropdown is-hoverable">
        <a class="navbar-link">
          More Research
        </a>
        <div class="navbar-dropdown">
          <a class="navbar-item" href="https://hypernerf.github.io">
            HyperNeRF
          </a>
          <a class="navbar-item" href="https://nerfies.github.io">
            Nerfies
          </a>
          <a class="navbar-item" href="https://latentfusion.github.io">
            LatentFusion
          </a>
          <a class="navbar-item" href="https://photoshape.github.io">
            PhotoShape
          </a>
        </div>
      </div>
    </div>

  </div>
</nav> -->


<section class="hero">
  <div class="hero-body">
    <div class="container is-max-desktop">
      <div class="columns is-centered">
        <div class="column has-text-centered">
          <h1 class="title is-1 publication-title">PACE: Pose Annotations in Cluttered Environments</h1>
          <h4 class="title is-4 conference">European Conference on Computer Vision (<span class="grad_text">ECCV</span>) 2024</h4>
          <div class="is-size-5 publication-authors">
            <span class="author-block">
              <a href="https://qq456cvb.github.io">Yang You</a><sup>1</sup>,</span>
            <span class="author-block">
              <a href="https://xiongkai.netlify.app">Kai Xiong</a><sup>2</sup>,</span>
            <span class="author-block">
              Zhening Yang<sup>3</sup>,
            </span>
            <span class="author-block">
              <a href="https://github.com/huangzhengxiang">Zhengxiang Huang</a><sup>2</sup>,
            </span>
            <span class="author-block">
              <a href="https://github.com/Zhou-jw">Junwei Zhou</a><sup>2</sup>,
            </span>
            <span class="author-block">
              <a href="https://rshi.top">Ruoxi Shi</a><sup>2</sup>,
            </span>
            <span class="author-block">
              Zhou Fang<sup>2</sup>
            </span>
            <span class="author-block">
              <a href="https://adamharley.com">Adam W Harley</a><sup>1</sup>
            </span>
            <span class="author-block">
              <a href="https://geometry.stanford.edu/member/guibas/">Leonidas Guibas</a><sup>1</sup>
            </span>
            <span class="author-block">
              <a href="https://www.mvig.org">Cewu Lu</a><sup>2</sup>
            </span>
          </div>
          <div class="is-size-5 publication-authors">
            <span class="author-block"><sup>1</sup>Stanford University</span>
            <span class="author-block"><sup>2</sup>Shanghai Jiao Tong University</span>
            <span class="author-block"><sup>3</sup>Horizon Robotics</span>
          </div>
          <div class="column has-text-centered">
            <div class="publication-links">
              <!-- PDF Link. -->
              <span class="link-block">
                <a href="https://arxiv.org/pdf/2312.15130.pdf"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fas fa-file-pdf"></i>
                  </span>
                  <span>Paper</span>
                </a>
              </span>
              <!-- Video Link. -->
              <span class="link-block">
                <a href="#"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fab fa-youtube"></i>
                  </span>
                  <span>Video (Coming Soon)</span>
                </a>
              </span>
              <!-- Code Link. -->
              <span class="link-block">
                <a href="https://github.com/qq456cvb/PACE"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fab fa-github"></i>
                  </span>
                  <span>Code</span>
                  </a>
              </span>
              <!-- Dataset Link. -->
              <span class="link-block">
                <a href="https://huggingface.co/datasets/qq456cvb/PACE"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="far fa-images"></i>
                  </span>
                  <span>Data</span>
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
    <!-- Abstract. -->
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Abstract</h2>
        <div class="content has-text-justified">
          <p>
            We introduce <b>PACE</b> (Pose Annotations in Cluttered Environments), a large-scale benchmark designed to advance the development and evaluation of pose estimation methods in cluttered scenarios. PACE provides a large-scale real-world benchmark for both instance-level and category-level settings. The benchmark consists of 55K frames with 258K annotations across 300 videos, covering 238 objects from 43 categories and featuring a mix of rigid and articulated items in cluttered scenes. To annotate the real-world data efficiently, we develop an innovative annotation system with a calibrated 3-camera setup. Additionally, we offer <b>PACESim</b>, which contains 100K photo-realistic simulated frames with 2.4M annotations across 931 objects. We test state-of-the-art algorithms in PACE along two tracks: pose estimation, and object pose tracking, revealing the benchmark’s challenges and research opportunities.
          </p>
        </div>
      </div>
    </div>
    <!--/ Abstract. -->
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <div class="content">
          <img src="/projects/pace/static/images/teaser.jpg" />
        </div>
      </div>
    </div>
  </div>
</section>


<section class="section">
  <div class="container">
    <div class="columns is-centered has-text-centered">
      <h2 class="title is-3">Annotation Visualization</h2>
    </div>
    <div class="swiper">
      <div class="swiper-wrapper">
        <div class="swiper-slide">
          <div class="grid-container">
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/rgb_000092.png" alt="Image 1"><p>RGB</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/render_000092.png" alt="Image 2"><p>Rendered Object</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/pose_000092.png" alt="Image 3"><p>Object Pose</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/depth_000092.png" alt="Image 4"><p>Depth</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/nocs_000092.png" alt="Image 5"><p>NOCS Map</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide1/mask_000092.png" alt="Image 6"><p>Instance Mask</p></div>
          </div>
        </div>
        <div class="swiper-slide">
          <div class="grid-container">
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/rgb_000059.png" alt="Image 1"><p>RGB</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/render_000059.png" alt="Image 2"><p>Rendered Object</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/pose_000059.png" alt="Image 3"><p>Object Pose</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/depth_000059.png" alt="Image 4"><p>Depth</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/nocs_000059.png" alt="Image 5"><p>NOCS Map</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide2/mask_000059.png" alt="Image 6"><p>Instance Mask</p></div>
          </div>
        </div>
        <div class="swiper-slide">
          <div class="grid-container">
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/rgb_000117.png" alt="Image 1"><p>RGB</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/render_000117.png" alt="Image 2"><p>Rendered Object</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/pose_000117.png" alt="Image 3"><p>Object Pose</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/depth_000117.png" alt="Image 4"><p>Depth</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/nocs_000117.png" alt="Image 5"><p>NOCS Map</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide3/mask_000117.png" alt="Image 6"><p>Instance Mask</p></div>
          </div>
        </div>
        <div class="swiper-slide">
          <div class="grid-container">
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/rgb_000077.png" alt="Image 1"><p>RGB</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/render_000077.png" alt="Image 2"><p>Rendered Object</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/pose_000077.png" alt="Image 3"><p>Object Pose</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/depth_000077.png" alt="Image 4"><p>Depth</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/nocs_000077.png" alt="Image 5"><p>NOCS Map</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide4/mask_000077.png" alt="Image 6"><p>Instance Mask</p></div>
          </div>
        </div>
        <div class="swiper-slide">
          <div class="grid-container">
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/rgb_000109.png" alt="Image 1"><p>RGB</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/render_000109.png" alt="Image 2"><p>Rendered Object</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/pose_000109.png" alt="Image 3"><p>Object Pose</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/depth_000109.png" alt="Image 4"><p>Depth</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/nocs_000109.png" alt="Image 5"><p>NOCS Map</p></div>
            <div class="grid-item"><img src="/projects/pace/static/images/slide5/mask_000109.png" alt="Image 6"><p>Instance Mask</p></div>
          </div>
        </div>
      </div>
      <!-- Add Pagination -->
      <div class="swiper-pagination"></div>
      <!-- Add Arrows -->
      <div class="swiper-button-next"></div>
      <div class="swiper-button-prev"></div>
    </div>
  </div>
</section>


<section class="section">
  <div class="container is-max-desktop">
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Dataset Comparison</h2>
        <div class="content">
          <img src="/projects/pace/static/images/compare.png" width="100%" />
        </div>
      </div>
    </div>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Data Distribution</h2>
        <div class="content">
          <img src="/projects/pace/static/images/dist-cat.png" />
          <p>Pose Annotation Distrubtion</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/dist-instance.png" width="100%" />
          <p>Object Instance Distrubtion</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/dist-size.png" width="55%" />
          <p>Object Size Distrubtion</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/dist-pose.png" width="57%" />
          <p>Azimuth and Elevation Distrubtion</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/dist-occ.png" width="55%" />
          <p>Occlusion Distrubtion</p>
        </div>
      </div>
    </div>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Benchmarks</h2>
        <div class="content">
          <img src="/projects/pace/static/images/bench-inst.png" width="50%" />
          <p>Instance-level Pose Estimation</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/bench-cat.png" width="100%" />
          <p>Category-level Pose Estimation</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/bench-mf.svg" width="70%" />
          <p>Model-free Pose Tracking</p>
        </div>
        <div class="content">
          <img src="/projects/pace/static/images/bench-mb.svg" width="50%" />
          <p>Model-based Pose Tracking</p>
        </div>
      </div>
    </div>
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Data Collection Pipeline</h2>
        <div class="content">
          <img src="/projects/pace/static/images/pipeline.jpg" />
        </div>
      </div>
    </div>
  </div>
</section>


<section class="section" id="BibTeX">
  <div class="container is-max-desktop content">
    <h2 class="title">BibTeX</h2>
    <pre><code>
@misc{you2023pace,
    title={PACE: Pose Annotations in Cluttered Environments},
    author={You, Yang and Xiong, Kai and Yang, Zhening and Huang, Zhengxiang and Zhou, Junwei and Shi, Ruoxi and Fang, Zhou and Harley, Adam W. and Guibas, Leonidas and Lu, Cewu},
    booktitle={European Conference on Computer Vision},
    year={2024},
    organization={Springer}
}
    </code></pre>
  </div>
</section>


<footer class="footer">
  <div class="container">
    <div class="content has-text-centered">
      <a class="icon-link" href="#">
        <i class="fas fa-file-pdf"></i>
      </a>
      <a class="icon-link" href="#" class="external-link" disabled>
        <i class="fab fa-github"></i>
      </a>
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

<script>
    var swiper = new Swiper('.swiper', {
      spaceBetween: 30,
      centeredSlides: false,
      autoplay: {
        delay: 3000,
        disableOnInteraction: true,
      },
      pagination: {
        el: '.swiper-pagination',
        clickable: true,
      },
      navigation: {
        nextEl: '.swiper-button-next',
        prevEl: '.swiper-button-prev',
      },
    });
  </script>

  

</body>
</html>
