//
//  Annotator.hpp
//  FoilCV
//
//  Created by Alessandro Silacci on 07.11.17.
//  Copyright © 2017 Alessandro Silacci. All rights reserved.
//

#ifndef Annotator_h
#define Annotator_h
#include "Result.h"
class Annotator{
public:
    Annotator();
    virtual ~Annotator();
    
    virtual Result* annotate(Mat* frame) = 0;
};

#endif /* Annotator_h */
