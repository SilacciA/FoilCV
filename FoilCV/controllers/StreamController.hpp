//
//  StreamController.hpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#ifndef StreamController_hpp
#define StreamController_hpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include "../annotators/SIFTAnnotator.hpp"

using namespace cv;

class StreamController{
public:
    StreamController(String path, String destPath, SIFTAnnotator* annotator, double startingFrameNb);
    virtual ~StreamController();
    
    virtual void startProcessing(bool parallel,const unsigned int blocksize);
    
private:
    SIFTAnnotator* annotator;
    VideoCapture* cap;
    double startingFrameNb;
    String* destPath;

    void processSequentially(double startFrame, unsigned int stopFrame);
    void processSequentially();
    void processParallel();
    
    void saveResults(Result** results,int len,int indexStart);
    void saveResults(std::list<Result*>* results,int indexStart);
    
};
#endif /* StreamController_hpp */
