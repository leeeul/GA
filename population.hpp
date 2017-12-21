#ifndef population_hpp
#define population_hpp

#include <stdio.h>
#include "ofMain.h"
#include "rocket.hpp"

class Population{
public:
    int population;
    int generation=0;
    
    vector<Rocket> list;
    float mutationRate;
    
    Population(int population=100, float mutationRate=0.01);
    
    ofPoint start;
    ofPoint end;
    void setTarget(ofPoint start, ofPoint end);
    
    void run();
    void update();
    void draw();
    
    void evolve();
    void selection();
    Rocket reproduction(int mom, int dad);
    float fitSum=0;
    
};

#endif /* population_hpp */
