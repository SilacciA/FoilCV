//
//  main.cpp
//  CVTest
//
//  Created by Alessandro Silacci on 26.10.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <opencv2/opencv.hpp>
#include "annotators/SIFTAnnotator.hpp"
#include "controllers/StreamController.hpp"

using namespace cv;
using namespace std;

extern void showFrame(VideoCapture* cap, int crtFrame, int frameNb,  bool showFrameNumber = true);
extern Mat applySift(Mat* frame);

int main(int argc, const char * argv[]) {
    String* path = NULL;
    String* destPath = NULL;
    if(argc == 3){
        path = new String(argv[1]);
        destPath = new String(argv[2]);
    }else{
        std::cout << "You need to provide a source stream and a destination path (having the destination filename in it)." << std::endl;
        return 1;
    }
    std::cout << "Creating Annotator and controller" << std::endl;
    SIFTAnnotator annotator;
    StreamController streamController(*path,*destPath,&annotator,3790.0);
    
    std::cout << "Starting Processing" << std::endl;
    streamController.startProcessing(false,20);
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
