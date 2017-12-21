#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //    ofSetWindowShape(640,480); i did it at main.cpp
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    start = ofPoint(50, ofGetHeight()/2);
    end = ofPoint(ofGetWidth()-50, ofGetHeight()/2);
    p.setTarget(start, end);
    
    ofSetColor(255);
    ofSetCircleResolution(24);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 10);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for(int i=0; i<=4; i++){
        if(i%2==0){
            ofSetColor(255,0,0);
        }else{
            ofSetColor(255);
        }
        
        ofDrawCircle(end.x, end.y, 30-i*5);
    }
    
    
    
    if(ofGetMousePressed()){
        ofNoFill();
        ofSetColor(255);
        ofDrawRectangle(boxLoc, ofGetMouseX()-boxLoc.x, ofGetMouseY()-boxLoc.y);
        ofFill();
    }
    
    ofSetColor(255,200);
    p.update();
    p.draw();
    
    ofSetColor(255, 100);
    
    for(int i=0; i<obList.size(); i++){
        Obstacle &ob = obList.at(i);
        ob.draw();
        ob.detect(p);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    boxLoc = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    boxSize = ofPoint(x-boxLoc.x, y-boxLoc.y);
    obList.push_back(Obstacle(boxLoc, boxSize));
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
