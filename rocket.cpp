#include "rocket.hpp"

void Rocket::initVec(ofPoint stPoint){
    for(int i=0; i<genoLeng; i++){
        genoType.push_back(
                           ofPoint(
                                   ofRandom(-genoStep, genoStep),
                                   ofRandom(-genoStep, genoStep)
                                   )
                           );
    }
    loc = stPoint;
}

void Rocket::setLoc(ofPoint stPoint){
    loc = stPoint;
}

bool Rocket::needToEvo(){
    if(time==genoLeng){
        return true;
    }else{
        return false;
    }
}

void Rocket::update(){
    if(!bumped){
        acc = genoType.at(time);
//        cout<<time<<endl;
        vel += acc;
        loc.x = ofClamp(loc.x+vel.x,0,ofGetWidth());
        loc.y = ofClamp(loc.y+vel.y,0,ofGetHeight());
        
        
        if(loc.x == 0 || loc.x == ofGetWidth()){
            bumped = true;
        }
        if(loc.y == 0 || loc.y == ofGetHeight()){
            bumped =true;
        }
    }
    
    time++;
}
void Rocket::draw(){
    //    if(isBumped()){
    //        ofSetColor(0);
    //    }else{
    //        ofSetColor(255);
    //    }
    
    float degree = vel.angle(ofPoint(1,0));
    if(vel.y<0){
        degree *= -1;
    }
    //    cout<<vel<<endl;
    
    ofPushMatrix();
    
    ofTranslate(loc);
    ofRotate(degree);
    ofDrawTriangle(0,radius, 2.5*radius,0,0,-radius);
    
    ofPopMatrix();
}
