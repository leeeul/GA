#include "obstacle.hpp"
#include "population.hpp"

Obstacle::Obstacle(ofPoint loc, ofPoint size){
    this->loc = loc;
    this-> size = size;
}

void Obstacle::detect(Population &p){
    for(int i=0; i<p.population; i++){
        Rocket &r = p.list.at(i);
        
        float x = r.loc.x;
        float y = r.loc.y;
        
        if(
           ((loc.x-x)*(loc.x+size.x-x)<=0)
           &&((loc.y-y)*(loc.y+size.y-y)<=0)
           )
        {
            r.bumped=true;
        }
    }
}

void Obstacle::draw(){
    ofDrawRectangle(loc, size.x, size.y);
}
