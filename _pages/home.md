---
permalink: /
title: "About Me"
seo_title: "Yang You (尤洋) – Stanford Postdoc in 3D Vision, Graphics & Robotics"
description: "Yang You (尤洋) is a postdoctoral researcher in Leonidas Guibas's Geometric Computation group at Stanford University, working on 3D computer vision, graphics and robotics: category-level object pose estimation (CPPF, UniPose9D), 3D keypoints and correspondence (KeypointNet), datasets such as PACE, and perception for robot manipulation."
excerpt: "Home page"
author_profile: false
hide_title: true
classes: home
redirect_from:
---

{% include home-hero.html %}

{% include_relative about_content.md %}

<section class="home-section" aria-labelledby="news">
  <h2 class="home-section__title" id="news">News</h2>
  <div class="home-section__body">
    {% include news-list.html limit=8 %}
    <p class="home-section__more"><a href="{{ base_path }}/news/">All news</a></p>
  </div>
</section>

{% if site.visitor_globe %}{% include visitor-globe.html %}{% endif %}
