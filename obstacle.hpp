#ifndef obstacle_hpp
#define obstacle_hpp

#include <stdio.h>
#include "ofMain.h"

class Population;

class Obstacle{
public:
    ofPoint loc;
    ofPoint size;
    
    Obstacle(ofPoint loc, ofPoint size);
    
    void detect(Population &p);
    void draw();
    
};
#endif
