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

  <!-- Global site tag (gtag.js) - Google Analytics -->
  <!-- <script async src="https://www.googletagmanager.com/gtag/js?id=G-PYVRSFMDRL"></script>
  <script>
    window.dataLayer = window.dataLayer || [];

    function gtag() {
      dataLayer.push(arguments);
    }

    gtag('js', new Date());

    gtag('config', 'G-PYVRSFMDRL');
  </script> -->

  <link href="https://fonts.googleapis.com/css?family=Google+Sans|Noto+Sans|Castoro"
        rel="stylesheet">

  <link rel="stylesheet" href="static/css/bulma.min.css">
  <link rel="stylesheet" href="static/css/bulma-carousel.min.css">
  <link rel="stylesheet" href="static/css/bulma-slider.min.css">
  <link rel="stylesheet" href="static/css/fontawesome.all.min.css">
  <link rel="stylesheet"
        href="https://cdn.jsdelivr.net/gh/jpswalsh/academicons@1/css/academicons.min.css">
  <link rel="stylesheet" href="static/css/index.css">
  <link rel="icon" href="static/images/favicon.svg">

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script defer src="static/js/fontawesome.all.min.js"></script>
  <script src="static/js/bulma-carousel.min.js"></script>
  <script src="static/js/bulma-slider.min.js"></script>
  <script src="static/js/index.js"></script>
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
          <div class="is-size-5 publication-authors">
            <span class="author-block">
              <a href="https://qq456cvb.github.io">Yang You</a><sup>1,3</sup>,</span>
            <span class="author-block">
              <a href="https://xiongkai.netlify.app">Kai Xiong</a><sup>1</sup>,</span>
            <span class="author-block">
              Zhening Yang<sup>2</sup>,
            </span>
            <span class="author-block">
              <a href="https://github.com/huangzhengxiang">Zhengxiang Huang</a><sup>1</sup>,
            </span>
            <span class="author-block">
              <a href="https://github.com/Zhou-jw">Junwei Zhou</a><sup>1</sup>,
            </span>
            <span class="author-block">
              <a href="https://rshi.top">Ruoxi Shi</a><sup>1</sup>,
            </span>
            <span class="author-block">
              Zhou Fang<sup>1</sup>
            </span>
            <span class="author-block">
              <a href="https://adamharley.com">Adam W Harley</a><sup>3</sup>
            </span>
            <span class="author-block">
              <a href="https://www.mvig.org">Cewu Lu</a><sup>1</sup>
            </span>
          </div>

          <div class="is-size-5 publication-authors">
            <span class="author-block"><sup>1</sup>Shanghai Jiao Tong University</span>
            <span class="author-block"><sup>2</sup>Horizon Robotics</span>
            <span class="author-block"><sup>3</sup>Stanford University</span>
          </div>

          <div class="column has-text-centered">
            <div class="publication-links">
              <!-- PDF Link. -->
              <span class="link-block">
                <a href="/files/pace.pdf"
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
                  <span>Video</span>
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
                <a href="https://sjtueducn-my.sharepoint.com/:f:/g/personal/qq456cvb_sjtu_edu_cn/Ei3YV1Iz5U1Ai2fkgD7wMO0BlnAjzgRSahLu3YwD8W-dZQ"
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

<!-- <section class="hero teaser">
  <div class="container is-max-desktop">
    <div class="hero-body">
      <video id="teaser" autoplay muted loop playsinline height="100%">
        <source src="static/videos/teaser.mp4"
                type="video/mp4">
      </video>
      <h2 class="subtitle has-text-centered">
        <span class="dnerf">Nerfies</span> turns selfie videos from your phone into
        free-viewpoint
        portraits.
      </h2>
    </div>
  </div>
</section>


<section class="hero is-light is-small">
  <div class="hero-body">
    <div class="container">
      <div id="results-carousel" class="carousel results-carousel">
        <div class="item item-steve">
          <video poster="" id="steve" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/steve.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-chair-tp">
          <video poster="" id="chair-tp" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/chair-tp.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-shiba">
          <video poster="" id="shiba" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/shiba.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-fullbody">
          <video poster="" id="fullbody" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/fullbody.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-blueshirt">
          <video poster="" id="blueshirt" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/blueshirt.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-mask">
          <video poster="" id="mask" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/mask.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-coffee">
          <video poster="" id="coffee" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/coffee.mp4"
                    type="video/mp4">
          </video>
        </div>
        <div class="item item-toby">
          <video poster="" id="toby" autoplay controls muted loop playsinline height="100%">
            <source src="static/videos/toby2.mp4"
                    type="video/mp4">
          </video>
        </div>
      </div>
    </div>
  </div>
</section> -->


<section class="section">
  <div class="container is-max-desktop">
    <!-- Abstract. -->
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Abstract</h2>
        <div class="content has-text-justified">
          <p>
            Pose estimation is a crucial task in computer vision,
            enabling tracking and manipulating objects in images or videos.
            While several datasets exist for pose estimation,
            there is a lack of large-scale datasets specifically focusing on cluttered scenes with occlusions.
            This limitation is a bottleneck in the development and evaluation of pose estimation methods,
            particularly toward the goal of real-world application in environments where occlusions are common.
            Addressing this, we introduce PACE (Pose Annotations in Cluttered Environments), a large-scale
            benchmark designed to advance the development and evaluation of pose estimation methods
            in cluttered scenarios. PACE encompasses 54,945 frames with 257,673 annotations across 300 videos,
            covering 576 objects from 44 categories and featuring a mix of rigid and articulated items
            in cluttered scenes. To annotate the real-world data efficiently,
            we developed an innovative annotation system utilizing a calibrated 3-camera setup.
            We test state-of-the-art algorithms in PACE along two tracks: pose estimation,
            and object pose tracking, revealing the benchmark's challenges and research opportunities.
            We plan to release PACE as a public evaluation benchmark,
            along the annotations tools we developed, to stimulate further advancements in the field.
          </p>
        </div>
      </div>
    </div>
    <!--/ Abstract. -->

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <!-- <h2 class="title is-3">Video</h2> -->
        <div class="content">
          <img src="static/images/teaser.jpg" />
        </div>
      </div>
    </div>

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Dataset Comparison</h2>
        <div class="content">
          <img src="static/images/compare.svg" width="100%" />
        </div>
      </div>
    </div>

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Data Distribution</h2>
        <div class="content">
          <img src="static/images/dist-cat.png" />
          <img src="static/images/dist-size.png" width="44%" />
          <img src="static/images/dist-pose.png" width="57%" />
          <img src="static/images/dist-occ.png" width="55%" />
        </div>
      </div>
    </div>

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Benchmarks</h2>
        <div class="content">
          <img src="static/images/bench-ins.svg" width="70%" />
          <p>Instance-level Pose Estimation</p>
        </div>
        <div class="content">
          <img src="static/images/bench-cat.svg" width="100%" />
          <p>Category-level Pose Estimation</p>
        </div>
        <div class="content">
          <img src="static/images/bench-mf.svg" width="70%" />
          <p>Model-free Pose Tracking</p>
        </div>
        <div class="content">
          <img src="static/images/bench-mb.svg" width="50%" />
          <p>Model-based Pose Tracking</p>
        </div>
      </div>
    </div>

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">Pipeline</h2>
        <div class="content">
          <img src="static/images/pipeline.jpg" />
        </div>
      </div>
    </div>
  </div>

</section>


<section class="section" id="BibTeX">
  <div class="container is-max-desktop content">
    <h2 class="title">BibTeX</h2>
    <pre><code>
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

</body>
</html>
