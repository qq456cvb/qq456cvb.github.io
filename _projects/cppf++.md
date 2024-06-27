---
layout: compress
permalink: /projects/cppf++
---

<html>
<head>
  <meta charset="utf-8">
  <meta name="description"
        content="CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation">
  <meta name="keywords" content="6D pose estimation, generalization in the wild">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation by Vote Aggregation</title>

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

  <link rel="stylesheet" href="/projects/cppf++/static/css/bulma.min.css">
  <link rel="stylesheet" href="/projects/cppf++/static/css/bulma-carousel.min.css">
  <link rel="stylesheet" href="/projects/cppf++/static/css/bulma-slider.min.css">
  <link rel="stylesheet" href="/projects/cppf++/static/css/fontawesome.all.min.css">
  <link rel="stylesheet"
        href="https://cdn.jsdelivr.net/gh/jpswalsh/academicons@1/css/academicons.min.css">
  <link rel="stylesheet" href="/projects/cppf++/static/css/index.css">
  <link rel="icon" href="/projects/cppf++/static/images/favicon.svg">

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script defer src="/projects/cppf++/static/js/fontawesome.all.min.js"></script>
  <script src="/projects/cppf++/static/js/bulma-carousel.min.js"></script>
  <script src="/projects/cppf++/static/js/bulma-slider.min.js"></script>
  <script src="/projects/cppf++/static/js/index.js"></script>
</head>
<body>


<section class="hero">
  <div class="hero-body">
    <div class="container is-max-desktop">
      <div class="columns is-centered">
        <div class="column has-text-centered">
          <h1 class="title is-1 publication-title">CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation by Vote Aggregation</h1>
          <div class="is-size-5 publication-authors">
            <span class="author-block">
              <a href="https://qq456cvb.github.io">Yang You</a><sup>1,3</sup>,</span>
            <span class="author-block">
              Wenhao He<sup>2</sup>,</span>
            <span class="author-block">
              Jin Liu<sup>1</sup>,
            </span>
            <span class="author-block">
              <a href="https://min.sjtu.edu.cn/En/FacultyShow/4?Vid=14">Hongkai Xiong</a><sup>1</sup>,
            </span>
            <span class="author-block">
              Weiming Wang<sup>1</sup>,
            </span>
            <span class="author-block">
              <a href="https://www.mvig.org">Cewu Lu</a><sup>1</sup>
            </span>
          </div>

          <div class="is-size-5 publication-authors">
            <span class="author-block"><sup>1</sup>Shanghai Jiao Tong University</span>
            <span class="author-block"><sup>2</sup>Flexiv Robotics Inc.</span>
            <span class="author-block"><sup>3</sup>Stanford University</span>
          </div>

          <div class="column has-text-centered">
            <div class="publication-links">
              <!-- PDF Link. -->
              <span class="link-block">
                <a href="https://arxiv.org/pdf/2211.13398"
                   class="external-link button is-normal is-rounded is-dark">
                  <span class="icon">
                      <i class="fas fa-file-pdf"></i>
                  </span>
                  <span>Paper</span>
                </a>
              </span>
              <!-- Code Link. -->
              <span class="link-block">
                <a href="https://github.com/qq456cvb/CPPF2"
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

<section class="section">
  <div class="container is-max-desktop">
    <!-- Abstract. -->
    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
      <p style="font-size: 24px;">
<b>Are you seeking a robust, generalized 6D pose estimator for RGB-D images captured by any sensor, tailored to your custom robotic setup? Here it is!</b> In this work, we present a novel voting mechanism designed to mitigate the challenge of domain overfitting. Our category-level pose estimator, CPPF++, can be trained exclusively on synthetic objects while maintaining strong generalization to various real-world datasets. Please check out our paper for more details.
</p>
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
            Object pose estimation constitutes a critical area within the domain of 3D vision. While contemporary state-of-the-art methods that leverage real-world pose annotations have demonstrated commendable performance, the procurement of such real training data incurs substantial costs. This paper focuses on a specific setting wherein only 3D CAD models are utilized as a priori knowledge, devoid of any background or clutter information. We introduce a novel method, CPPF++, designed for sim-to-real category-level pose estimation. This method builds upon the foundational point-pair voting scheme of CPPF, reformulating it through a probabilistic view. To address the challenge posed by vote collision, we propose a novel approach that involves modeling the voting uncertainty by estimating the probabilistic distribution of each point pair within the canonical space. Furthermore, we augment the contextual information provided by each voting unit through the introduction of $N$-point tuples. To enhance the robustness and accuracy of the model, we incorporate several innovative modules, including noisy pair filtering, online alignment optimization, and a tuple feature ensemble. Alongside these methodological advancements, we introduce a new category-level pose estimation dataset, named DiversePose 300. Empirical evidence demonstrates that our method significantly surpasses previous sim-to-real approaches and achieves comparable or superior performance on novel datasets.
          </p>
        </div>
      </div>
    </div>
    <!--/ Abstract. -->

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <!-- <h2 class="title is-3">Teaser</h2> -->
        <div class="content">
          <img src="/projects/cppf++/static/images/pipeline.png" />
        </div>
      </div>
    </div>

    <div>
     <p>
     Our pipeline commences with a masked point cloud input, derived from an off-the-shelf instance segmentation model. Subsequently, point tuples are randomly sampled from the object. Features for each tuple are extracted and fed into a tuple encoder to obtain the tuple embedding. Following is the prediction of the canonical coordinate and scale of each tuple. During inference, the computed canonical coordinates and scales are utilized to vote for the object's center. To mitigate the influence of erroneous tuple samples, we introduce a noisy pair filtering module, enabling the orientation vote to be cast exclusively by reliable point tuples. Finally, an online alignment optimization step is employed to further refine the predicted rotation and translation, enhancing the accuracy of our model's output.
     </p>
    </div>

    <br>
    <br>

    <div class="columns is-centered has-text-centered">
      <div class="column is-five-sixths">
        <h2 class="title is-3">SotA Performance on Multiple Datasets<br> (best in bold and second-best underscored)</h2>
        <div class="content">
          <img src="/projects/cppf++/static/images/comp1.png" width="100%" />
          <img src="/projects/cppf++/static/images/comp2.png" width="100%" />
        </div>
      </div>
    </div>

  </div>

</section>


<section class="section" id="BibTeX">
  <div class="container is-max-desktop content">
    <h2 class="title">BibTeX</h2>
    <pre><code>
    @article{You_2024,
        title={CPPF++: Uncertainty-Aware Sim2Real Object Pose Estimation by Vote Aggregation},
        ISSN={1939-3539},
        url={http://dx.doi.org/10.1109/TPAMI.2024.3419038},
        DOI={10.1109/tpami.2024.3419038},
        journal={IEEE Transactions on Pattern Analysis and Machine Intelligence},
        publisher={Institute of Electrical and Electronics Engineers (IEEE)},
        author={You, Yang and He, Wenhao and Liu, Jin and Xiong, Hongkai and Wang, Weiming and Lu, Cewu},
        year={2024},
        pages={1–16}
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

</body>
</html>
