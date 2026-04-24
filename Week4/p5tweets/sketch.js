j=0;function setup(){createCanvas(1080,500)}function draw(){translate(500,200);i=frameCount;while(i-->0.1){stroke(i*j%360,99,99);rect(j++%i,j%i,1,i%0.5);rotate(10)}}

