//
//  Result.h
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//
#pragma once
#ifndef Result_h
#define Result_h
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

using namespace cv;

class Result {
public:
    Result(Mat frame, std::vector<KeyPoint> keypoints, Mat annotatedFrame);
    ~Result();
    virtual Mat* getFrame();
    virtual Mat* getAnnotatedFrame();
    virtual std::vector<KeyPoint>* getKeyPoints();
    
private:
    Mat* frame;
    Mat* annotatedFrame;
    std::vector<KeyPoint>* keypoints;
};

#endif /* Result_h */
