# FoilCV

## Introduction
By this project I'm trying to determine who has the priority on a, lets say it like that, "double touch" in foil. As foil has a particular way, same for sabre, to deal with this kind of points it is sometimes hard to believe the arbitrator has all recorded in his mind. So, instead of not listening during my master's lectures I decided to give an attempt at using various computer vision technologies to try and determine who would have the priority. 

I, for now, only use the video published on YouTube that I extract and convert.

Please feel free to contact me if you may have an idea on how to do it or just want to discuss.

## Current State
The project is still at an early phase, it's only capable of annotating the frames with SIFT for feature points extraction. But I'm already thinking on what should be the next steps.
![A sifted frame result](https://github.com/SilacciA/FoilCV/blob/master/foil_01_sifted_5704.png?raw=true)
Above is the result of SIFT on one of the frames.

## Planned features
* SIFT
* Homography, or something like that in order to keep the very interesting points
* Maybe using OpenMP (or CUDA) to be more efficient