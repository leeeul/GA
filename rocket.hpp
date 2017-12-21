#ifndef rocket_hpp
#define rocket_hpp

#include <stdio.h>
#include "ofMain.h"

class Rocket{
public:
    vector<ofPoint> genoType;
    int time = 0;
    int genoLeng=600;
    float genoStep=.3;
    
    float fit;
    float prob;
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float radius = 5;
    
    bool bumped = false;
    
    void initVec(ofPoint stPoint);
    void setLoc(ofPoint stPoint);
    bool needToEvo();
    bool isBumped();
    void update();
    void draw();
    
    
    
};

#endif /* rocket_hpp */
