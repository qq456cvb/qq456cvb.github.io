/* Home page hero: a KeypointNet mug with its keypoints and 9D pose (oriented box = size and position, axes = rotation).
   On load the box and axes settle onto the mug once, the way a pose estimate converges; after that the figure only
   moves when the visitor drags it or uses the arrow keys. Block comments only: the page is HTML-compressed. */
(function () {
  var fig = document.getElementById('pose-figure');
  if (!fig) return;
  var canvas = fig.querySelector('canvas'), ctx = canvas.getContext('2d');
  var reduce = window.matchMedia('(prefers-reduced-motion: reduce)').matches;
  var VIEW = { yaw: 1.35, pitch: 0.5 }, yaw = VIEW.yaw, pitch = VIEW.pitch;
  var pts = null, kps = null, half = [1, 1, 1], W = 0, H = 0, dpr = 1, colors = null, settle = reduce ? 1 : 0, frame = 0;

  /* the wrong pose the estimate starts from: rotated, shifted and too large */
  var START = { axis: norm([0.35, 1, 0.25]), angle: 0.95, shift: [0.22, -0.14, 0.12], scale: 1.3 };

  function norm(v) { var l = Math.hypot(v[0], v[1], v[2]); return [v[0] / l, v[1] / l, v[2] / l]; }
  function rotate(v, a, t) {
    /* Rodrigues' rotation of v about unit axis a by angle t */
    var c = Math.cos(t), s = Math.sin(t), d = a[0] * v[0] + a[1] * v[1] + a[2] * v[2];
    return [
      v[0] * c + (a[1] * v[2] - a[2] * v[1]) * s + a[0] * d * (1 - c),
      v[1] * c + (a[2] * v[0] - a[0] * v[2]) * s + a[1] * d * (1 - c),
      v[2] * c + (a[0] * v[1] - a[1] * v[0]) * s + a[2] * d * (1 - c)
    ];
  }
  function ease(t) { return 1 - Math.pow(1 - t, 3); }
  /* estimated pose applied to a point of the box or axes, k in [0, 1] from start pose to the true pose */
  function posed(v, k) {
    var r = 1 - k, s = 1 + (START.scale - 1) * r, p = rotate([v[0] * s, v[1] * s, v[2] * s], START.axis, START.angle * r);
    return [p[0] + START.shift[0] * r, p[1] + START.shift[1] * r, p[2] + START.shift[2] * r];
  }
  function view(v) {
    var cy = Math.cos(yaw), sy = Math.sin(yaw), cp = Math.cos(pitch), sp = Math.sin(pitch);
    var x1 = cy * v[0] + sy * v[2], z1 = -sy * v[0] + cy * v[2];
    return [x1, cp * v[1] - sp * z1, sp * v[1] + cp * z1];
  }
  function project(v) {
    var q = view(v), R = Math.min(W, H) * 0.47, f = 1 + 0.1 * q[2];
    return [W * 0.47 + q[0] * R * f, H * 0.5 - q[1] * R * f, q[2]];
  }

  function readColors() {
    var cs = getComputedStyle(fig);
    function v(name, fb) { return cs.getPropertyValue(name).trim() || fb; }
    colors = { ink: v('--graphite', '#1d232a'), lead: v('--lead', '#5b6570'), paper: v('--vellum', '#f2f4f3'),
      x: v('--axis-x', '#d2453b'), y: v('--axis-y', '#2e9a5c'), z: v('--axis-z', '#2b67c6') };
  }

  function size() {
    dpr = Math.min(window.devicePixelRatio || 1, 2);
    W = canvas.clientWidth; H = canvas.clientHeight;
    canvas.width = Math.round(W * dpr); canvas.height = Math.round(H * dpr);
    draw();
  }

  function drawBox(k, hidden) {
    /* an edge is hidden when both faces it joins point away from the viewer (dashed, as in a technical drawing) */
    var axes = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    function faceVisible(a, s) {
      var n = axes[a].map(function (c) { return c * s; });
      var o = posed([0, 0, 0], k), e = posed(n, k);
      return view([e[0] - o[0], e[1] - o[1], e[2] - o[2]])[2] > 0;
    }
    ctx.lineWidth = 1.1; ctx.strokeStyle = colors.lead;
    ctx.setLineDash(hidden ? [3, 4] : []);
    ctx.globalAlpha = hidden ? 0.4 : 0.85;
    for (var a = 0; a < 3; a++) for (var b = a + 1; b < 3; b++) {
      var c = 3 - a - b;
      for (var sa = -1; sa <= 1; sa += 2) for (var sb = -1; sb <= 1; sb += 2) {
        var isHidden = !faceVisible(a, sa) && !faceVisible(b, sb);
        if (isHidden !== hidden) continue;
        var p0 = [0, 0, 0], p1 = [0, 0, 0];
        p0[a] = p1[a] = sa * half[a]; p0[b] = p1[b] = sb * half[b]; p0[c] = -half[c]; p1[c] = half[c];
        var u = project(posed(p0, k)), w = project(posed(p1, k));
        ctx.beginPath(); ctx.moveTo(u[0], u[1]); ctx.lineTo(w[0], w[1]); ctx.stroke();
      }
    }
    ctx.setLineDash([]); ctx.globalAlpha = 1;
  }

  function drawAxes(k) {
    var names = ['x', 'y', 'z'], o = project(posed([0, 0, 0], k));
    var order = [0, 1, 2].map(function (a) { var e = [0, 0, 0]; e[a] = half[a] + 0.2; return { a: a, tip: project(posed(e, k)) }; })
      .sort(function (p, q) { return p.tip[2] - q.tip[2]; });
    ctx.font = '600 13px Archivo, sans-serif'; ctx.textAlign = 'center'; ctx.textBaseline = 'middle';
    order.forEach(function (it) {
      var col = colors[names[it.a]], t = it.tip, dx = t[0] - o[0], dy = t[1] - o[1], l = Math.hypot(dx, dy) || 1;
      ctx.strokeStyle = col; ctx.fillStyle = col; ctx.lineWidth = 2.5; ctx.lineCap = 'round';
      ctx.beginPath(); ctx.moveTo(o[0], o[1]); ctx.lineTo(t[0], t[1]); ctx.stroke();
      var ux = dx / l, uy = dy / l, hs = 8;
      ctx.beginPath(); ctx.moveTo(t[0] + ux * 3, t[1] + uy * 3);
      ctx.lineTo(t[0] - ux * hs - uy * hs * 0.55, t[1] - uy * hs + ux * hs * 0.55);
      ctx.lineTo(t[0] - ux * hs + uy * hs * 0.55, t[1] - uy * hs - ux * hs * 0.55); ctx.closePath(); ctx.fill();
      ctx.fillText(names[it.a], t[0] + ux * 14, t[1] + uy * 14);
    });
    ctx.beginPath(); ctx.arc(o[0], o[1], 3, 0, 6.2832); ctx.fillStyle = colors.ink; ctx.fill();
  }

  function draw() {
    if (!pts || !colors || !W) return;
    var k = ease(settle), n = pts.length / 3, i;
    /* clear in device pixels: at fractional pixel ratios W * dpr is not whole, and a CSS-unit clear leaves a column */
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
    drawBox(k, true);
    var proj = new Array(n);
    for (i = 0; i < n; i++) proj[i] = project([pts[i * 3], pts[i * 3 + 1], pts[i * 3 + 2]]);
    var order = proj.map(function (_, j) { return j; }).sort(function (a, b) { return proj[a][2] - proj[b][2]; });
    var ps = Math.max(1.8, W / 230);
    order.forEach(function (j) {
      var p = proj[j];
      ctx.globalAlpha = 0.32 + 0.63 * Math.max(0, Math.min(1, (p[2] + 1) / 2));
      ctx.fillStyle = colors.ink; ctx.fillRect(p[0] - ps / 2, p[1] - ps / 2, ps, ps);
    });
    ctx.globalAlpha = 1;
    kps.forEach(function (j) {
      var p = proj[j];
      ctx.beginPath(); ctx.arc(p[0], p[1], 4.2, 0, 6.2832);
      ctx.fillStyle = colors.ink; ctx.fill(); ctx.lineWidth = 2; ctx.strokeStyle = colors.paper; ctx.stroke();
    });
    drawBox(k, false);
    drawAxes(k);
  }

  function play() {
    if (reduce) { settle = 1; draw(); return; }
    var t0 = null;
    function step(ts) {
      if (t0 === null) t0 = ts;
      settle = Math.min(1, (ts - t0) / 1600);
      draw();
      if (settle < 1) frame = requestAnimationFrame(step);
    }
    /* a short pause so the mug is seen before its pose arrives */
    setTimeout(function () { frame = requestAnimationFrame(step); }, 350);
  }

  function turn(dy, dp) {
    yaw += dy; pitch = Math.max(-1.3, Math.min(1.3, pitch + dp));
    if (settle < 1) { cancelAnimationFrame(frame); settle = 1; }
    draw();
  }

  var drag = null;
  canvas.addEventListener('pointerdown', function (e) { drag = { x: e.clientX, y: e.clientY }; canvas.setPointerCapture(e.pointerId); fig.classList.add('is-dragging'); });
  canvas.addEventListener('pointermove', function (e) {
    if (!drag) return;
    turn((e.clientX - drag.x) * 0.01, (e.clientY - drag.y) * 0.01);
    drag = { x: e.clientX, y: e.clientY };
  });
  function end() { drag = null; fig.classList.remove('is-dragging'); }
  canvas.addEventListener('pointerup', end); canvas.addEventListener('pointercancel', end);
  canvas.addEventListener('keydown', function (e) {
    var s = 0.15, m = { ArrowLeft: [-s, 0], ArrowRight: [s, 0], ArrowUp: [0, -s], ArrowDown: [0, s] }[e.key];
    if (m) { e.preventDefault(); turn(m[0], m[1]); }
    else if (e.key === 'Home') { e.preventDefault(); yaw = VIEW.yaw; pitch = VIEW.pitch; draw(); }
  });

  fetch(fig.getAttribute('data-src')).then(function (r) { if (!r.ok) throw new Error(r.status); return r.json(); }).then(function (d) {
    pts = d.p; kps = d.k;
    var lo = [1e9, 1e9, 1e9], hi = [-1e9, -1e9, -1e9];
    for (var i = 0; i < pts.length; i += 3) for (var a = 0; a < 3; a++) { lo[a] = Math.min(lo[a], pts[i + a]); hi[a] = Math.max(hi[a], pts[i + a]); }
    half = [0, 1, 2].map(function (a) { return (hi[a] - lo[a]) / 2; });
    readColors();
    fig.classList.add('is-ready');
    new ResizeObserver(size).observe(canvas);
    (document.fonts ? document.fonts.ready : Promise.resolve()).then(function () { size(); play(); });
  }).catch(function () { fig.classList.add('is-failed'); });
})();
