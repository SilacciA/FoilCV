//
//  StreamController.cpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#include "StreamController.hpp"
StreamController::StreamController(String path, String destPath, SIFTAnnotator* annotator, double startingFrameNb){
    this->cap = new VideoCapture(path);
    this->annotator = annotator;
    this->destPath = new String(destPath);
    this->startingFrameNb = startingFrameNb;
}

StreamController::~StreamController(){
    delete this->cap;
    delete this->destPath;
}

void StreamController::startProcessing(){
    if(!this->cap->isOpened())  // check if stream is open
        return;
    int frameNb = this->cap->get(CV_CAP_PROP_FRAME_COUNT); // for now not used
    this->cap->set(CV_CAP_PROP_POS_FRAMES, 3790.0);
    std::list<Result*> results;
    for(int i = 0; i < 10;i++){ // indicational number of frames to compute, will change (obviously).
        Mat frame;
        (*cap) >> frame;
        Result* res = this->annotator->annotate(&frame);
        results.push_back(res);
    }
    int i = 0;
    for(std::list<Result*>::iterator iterator=results.begin();iterator != results.end();iterator++){
        Result* res = (*iterator);
        Mat* output = res->getAnnotatedFrame();
        std::cout << "Write of image started" << std::endl;
        imwrite(format("%s_%d.png",this->destPath->c_str(),i++),*output);
        std::cout << "Write of image completed" << std::endl;
    }
}


