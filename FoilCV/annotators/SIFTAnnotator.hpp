//
//  SIFTAnnotator.hpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#ifndef SIFTAnnotator_hpp
#define SIFTAnnotator_hpp

#include <cstdio>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include "Annotator.hpp"
#include "../Result.h"

using namespace cv;

class SIFTAnnotator{
public:
    SIFTAnnotator();
    ~SIFTAnnotator();
    virtual Result* annotate(Mat* frame);
private:
    Ptr<Feature2D> f2d;   
};
#endif /* SIFTAnnotator_hpp */
