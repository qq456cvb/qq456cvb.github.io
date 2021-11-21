---
layout: keypointnet-single
permalink: /keypointnet/explore/
title: "KeypointNet Explore"
excerpt: ""
author_profile: false
redirect_from: /keypointnet/explore.html
sidebar: true
---

{% include base_path %}

<style>
  canvas { width: inherit; position: relative; top: 0;}
</style>

<p> Refresh <a href="#" id="refresh" onclick="reload(); return false;"><i class="fa fa-refresh"></i></a> </p>
<div id='canvas-holder' style="position: relative; width: inherit;">
</div>

<script>
    var color_map = {
        0: [0.95, 0.05, 0.05],
        1: [0.05, 0.95, 0.05],
        2: [0.35, 0.05, 0.95],
        3: [0.35, 0.65, 0.05],
        4: [0.95, 0.65, 0.05],
        5: [0.35, 0.05, 0.05],
        6: [0.35, 0.65, 0.95],
        7: [0.35, 0.05, 0.65],
        8: [0.05, 0.05, 0.65],
        9: [0.65, 0.05, 0.35],
        10: [0.05, 0.35, 0.35],
        11: [0.65, 0.65, 0.35],
        12: [0.35, 0.95, 0.05],
        13: [0.05, 0.35, 0.65],
        14: [0.95, 0.95, 0.35],
        15: [0.65, 0.65, 0.65],
        16: [0.95, 0.95, 0.05],
        17: [0.65, 0.35, 0.05],
        18: [0.95, 0.95, 0.65],
        19: [0.95, 0.65, 0.95],
        20: [0.95, 0.35, 0.65],
        21: [0.95, 0.05, 0.05],
        22: [0.05, 0.95, 0.05],
        23: [0.35, 0.05, 0.95],
        24: [0.35, 0.65, 0.05],
    };

    var id2name = {
        "02691156": "airplane",
        "02808440": "bathtub",
        "02818832": "bed",
        "02828884": "bench",
        "02876657": "bottle",
        "02924116": "bus",
        "02954340": "cap",
        "02958343": "car",
        "03001627": "chair",
        "03207941": "dishwasher",
        "03211117": "display",
        "03261776": "earphone",
        "03325088": "faucet",
        "03467517": "guitar",
        "03513137": "helmet",
        "03624134": "knife",
        "03636649": "lamp",
        "03642806": "laptop",
        "03790512": "motorcycle",
        "03797390": "mug",
        "03948459": "pistol",
        "04099429": "rocket",
        "04225987": "skateboard",
        "04379243": "table",
        "04530566": "vessel"
    };

    let canvasHolder = document.getElementById('canvas-holder');
    var width = canvasHolder.clientWidth;
    var height = width;
    canvasHolder.clientHeight = height;
    renderer = new THREE.WebGLRenderer();
    renderer.setSize( width, height );
    renderer.setClearColor(0xffffff);
    canvasHolder.appendChild( renderer.domElement );

    var camera = new THREE.PerspectiveCamera( 45, width / height, 0.1, 10000 );
    camera.applyMatrix( new THREE.Matrix4().makeTranslation( 0,0, 1.25 ) );
    camera.applyMatrix( new THREE.Matrix4().makeRotationX( -0.5 ) );

    var class_name = 'airplane';
    var labels;

    var scenes = [], objs = [];
    let pointlight_intensity = 0.3, ambientlight_intensity = 0.6;
    for (let j = 0; j < 9; j++) {
        scenes.push(new THREE.Scene());
        
        let pointLight = new THREE.PointLight( 0xffffff, pointlight_intensity);
        pointLight.name = 'pl';
        scenes[j].add( pointLight );

        let ambientLight = new THREE.AmbientLight( 0xcccccc, ambientlight_intensity);
        scenes[j].add( ambientLight );
        scenes[j].add( camera );
        objs.push( null );
    }

    var control = new TrackballControls( camera, renderer.domElement );
    control.rotateSpeed = 3.0;
    control.zoomSpeed = 1.2;
    control.panSpeed = 0.8;
    control.noZoom = false;
    control.noPan = true;
    control.staticMoving = true;
    control.dynamicDampingFactor = 0.3;
    control.keys = [ 65, 83, 68 ];
    control.addEventListener( 'change', render );

    function animate() {
        requestAnimationFrame( animate );
        control.update();
        render();
    }

    animate();
    reload();

    function create_balls() {
        let ballGeometry = new THREE.SphereGeometry(0.03, 32, 32);
        let results = [];
        for (let i = 0; i < 9; i++) {
            let tmp = [];
            for (let k = 0; k < 25; k++) {
                let material = new THREE.MeshBasicMaterial({ color: 'rgb(' + Math.floor(color_map[k][0] * 255) + ',' + Math.floor(color_map[k][1] * 255) + ',' + Math.floor(color_map[k][2] * 255) + ')'});
                let ball = new THREE.Mesh(ballGeometry, material);
                ball.position.copy(new THREE.Vector3(0, 0, 0));
                tmp.push(ball);
            }
            results.push(tmp);
        }
        return results;
    };

    var balls = create_balls();

    function reload() {
        fetch("/assets/jsons/" + class_name + ".json")
            .then(response => response.json())
            .then(json => {
                labels = json;
                for (let i = 0; i < 9; i++) {
                    scenes[i].remove(objs[i]);
                    for (let j = 0; j < 25; j++) {
                        scenes[i].remove(balls[i][j]);
                    }
                    let idx = Math.floor(Math.random() * labels.length);
                    let label = labels[idx];
                    let mtlloader = new THREE.MTLLoader();
                    mtlloader.setResourcePath('http://202.121.182.216:21386/shapenet/' + label.class_id + '/' + label.model_id + '/images/');
                    mtlloader.load( 'http://202.121.182.216:21386/mtl?name=' + label.class_id + '-' + label.model_id, function (materials) {
                        materials.preload();
                        new THREE.OBJLoader().setMaterials( materials ).load( 'http://202.121.182.216:21386/obj?name=' + label.class_id + '-' + label.model_id, function ( object ) {
                            objs[i] = object;
                            scenes[i].add( object );
                            for (let j = 0; j < label.keypoints.length; j++) {
                                let kp = label.keypoints[j];
                                let kp_idx = kp.semantic_id;
                                balls[i][kp_idx].position.set(kp.xyz[0], kp.xyz[1], kp.xyz[2]);
                                scenes[i].add(balls[i][kp_idx]);
                            }
                        }, function (xhr) {
                            if (id2name[label.class_id] !== class_name) {
                                xhr.currentTarget.abort();
                            }
                        });
                    }, function (xhr) {
                        if (id2name[label.class_id] !== class_name) {
                            xhr.currentTarget.abort();
                        }
                    });
                }
            });
    };

    function render() {
        let sub_width = width / 3 + 1;
        let sub_height = height / 3 + 1;
        for (let j = 0; j < 9; j++) {
            let pl = scenes[j].getObjectByName('pl');
            pl.position.set(camera.position.x, camera.position.y, camera.position.z);
            pl.y = camera.position.y;
            pl.z = camera.position.z;
            let x = j % 3;
            let y = Math.floor(j / 3);
            let left = width / 3 * x;
            let bottom = height / 3 * y;

            renderer.setScissor( left, bottom, sub_width, sub_height );
            renderer.setScissorTest( true );
            renderer.setViewport( left, bottom, sub_width, sub_height);

            renderer.render( scenes[j], camera );
        }
    }
</script>