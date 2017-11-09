//
//  Result.cpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//
#include "Result.h"

Result::Result(Mat frame, std::vector<KeyPoint> keypoints, Mat annotatedFrame){
    this->frame = new Mat(frame);
    this->keypoints = new std::vector<KeyPoint>(keypoints);
    this->annotatedFrame = new Mat(annotatedFrame);
}

Result::~Result(){
    delete this->frame;
    delete this->keypoints;
    delete this->annotatedFrame;
}

Mat* Result::getFrame(){
    return this->frame;
}

Mat* Result::getAnnotatedFrame(){
    return this->annotatedFrame;
}

std::vector<KeyPoint>* Result::getKeyPoints(){
    return this->keypoints;
}

