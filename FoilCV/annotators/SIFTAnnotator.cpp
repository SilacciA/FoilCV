//
//  SIFTAnnotator.cpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#include "SIFTAnnotator.hpp"
SIFTAnnotator::SIFTAnnotator(){
    this->f2d = xfeatures2d::SIFT::create();
}

SIFTAnnotator::~SIFTAnnotator(){
    this->f2d.release();
}

Result* SIFTAnnotator::annotate(Mat& frame){
    /*Mat grayScaledFrame;
    cvtColor(*frame, grayScaledFrame, CV_BGR2GRAY);*/
    Mat* output = new Mat();
    std::vector<KeyPoint>* keypoints = new std::vector<KeyPoint>();
    this->f2d->detect(frame, *keypoints);
    drawKeypoints(frame, *keypoints, *output);
    Result* res = new Result(frame,*keypoints,*output);
    delete output;
    delete keypoints;
    return res;
}

