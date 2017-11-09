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

Result* SIFTAnnotator::annotate(Mat* frame){
    Mat grayScaledFrame;
    cvtColor(*frame, grayScaledFrame, CV_BGR2GRAY);
    Mat output;
    std::vector<KeyPoint> keypoints;
    this->f2d->detect(*frame, keypoints);
    drawKeypoints(*frame, keypoints, output);
    return new Result(*frame,keypoints,output);
}

