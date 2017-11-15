//
//  StreamController.cpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#include "StreamController.hpp"
//#include <omp.h> one day it will work
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

void StreamController::startProcessing(bool parallel=false,const unsigned int blocksize=0){
    if(parallel){
        //processParallel();
    }else{
        if(blocksize == 0){
            processSequentially();
        }else{
            unsigned int frameNb = (unsigned int) this->cap->get(CV_CAP_PROP_FRAME_COUNT);
            unsigned int blocks = (unsigned int) (frameNb/blocksize); // CAREFUL I ASSUME YOU USE A MULTIPLE of the frame number
            double frameStart = 3790.0;
            std::cout << "Cutting the computation into " << blocks << " blocks." << std::endl;
            for(unsigned int i = 0; i < 100;i++){
                std::cout << "Processing block " << i << std::endl;
                this->processSequentially(frameStart,blocksize);
                frameStart += (double) blocksize;
                std::cout << "Completed processing block " << i << std::endl;
            }
        }
    }
}
void StreamController::processSequentially(){
    unsigned int frameNb = (unsigned int) this->cap->get(CV_CAP_PROP_FRAME_COUNT);
    this->processSequentially(0,frameNb);
}


void StreamController::processSequentially(double startFrame, unsigned int numberOfFrames){
    if(!this->cap->isOpened())  // check if stream is open
        return;
    this->cap->set(CV_CAP_PROP_POS_FRAMES, startFrame);
    Result** results = new Result*[numberOfFrames];
    unsigned int st_int = (unsigned int) startFrame; // yes I did it.
    unsigned int n = st_int+numberOfFrames;
    unsigned int res_i = 0;
    for(unsigned int i = st_int; i < n;i++){ // indicational number of frames to compute, will change (obviously).
        Mat* frame = new Mat();
        (*cap) >> (*frame);
        results[res_i++] = this->annotator->annotate(*frame);
        delete frame;
    }
    this->saveResults(results,numberOfFrames,startFrame);
    for(int i = 0; i < numberOfFrames;i++){
        delete results[i];
    }
    delete[] results;
}

/**
 * DO NOT USE THAT ! IT DOES NOT WORK AT ALL.
 * */
/*void StreamController::processParallel(){
    if(!this->cap->isOpened())  // check if stream is open
        return;
    int frameNb = this->cap->get(CV_CAP_PROP_FRAME_COUNT); // for now not used
    
    std::list<Result*> results;
#pragma omp parallel for
    for(int i = 0; i < frameNb;i++){ // indicational number of frames to compute, will change (obviously).
        Mat frame;
        this->cap->set(CV_CAP_PROP_POS_FRAMES, i);
        (*cap) >> frame;
        Result* res = this->annotator->annotate(*frame);
        results.push_back(res);
    }
    this->saveResults(&results,0);
}*/

void StreamController::saveResults(Result** results,int len,int indexStart=0){
    int i = indexStart;
    for(int res_i=0;res_i< len;res_i++){
        Result* res = results[res_i];
        Mat* output = res->getAnnotatedFrame();
        std::cout << "Write of image started" << std::endl;
        imwrite(format("%s_%d.png",this->destPath->c_str(),i++),*output);
        std::cout << "Write of image completed" << std::endl;
    }
}

void StreamController::saveResults(std::list<Result*>* results,int indexStart=0){
    int i = indexStart;
    for(std::list<Result*>::iterator iterator=results->begin();iterator != results->end();iterator++){
        Result* res = (*iterator);
        Mat* output = res->getAnnotatedFrame();
        std::cout << "Write of image started" << std::endl;
        imwrite(format("%s_%d.png",this->destPath->c_str(),i++),*output);
        std::cout << "Write of image completed" << std::endl;
    }
}


