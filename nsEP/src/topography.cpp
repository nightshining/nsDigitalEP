
#include "topography.h"

//--------------------------------------------------------------
void topography::setup() {
    
    //One Rect for background
    rectPos.set(0, 0);
    
    alternateColor.set(0, 200, 150);
    alpha = 255;
    
    
        
    
}

//--------------------------------------------------------------
void topography::update() {
    
    rotate += 0.005f;
    
    sine += 0.005f;
    sendSine = 15.0 * sin(sine);
    
    
}

//--------------------------------------------------------------
void topography::draw(){
    
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofTranslate(rectPos);
    ofRect(0, 0, 400, 300);
    ofPopMatrix();
   
    
    
    
    for (int i = 0; i < 30; i++) {
        
        ofPushStyle();

        ofPushMatrix();
        ofSetCircleResolution(100);
        ofRotateX(sendSine * i);
        //ofRotateY(sendSine * ofMap(i, 0, 25, 0.0, TWO_PI * 10));
        //ofRotateY(sendSine * i);

        ofSetColor(alternateColor, ofMap(i, 0, 30, 175, 70));
        ofNoFill();
        ofCircle(rectPos.x, rectPos.y, i * 3, i * 3);
        //ofSetColor(alternateColor, ofMap(i, 0, 10, 50, 100));
        //ofFill();
        //ofCircle(rectPos.x, rectPos.y, i * 3, i * 3);
        ofPopMatrix();
        
        
        ofPushMatrix();
        ofRotateX(-sendSine * i);
       // ofRotateY(-sendSine * i);

        ofSetColor(ofColor::white, ofMap(i, 0, 30, 175, 70));
        ofNoFill();
        ofCircle(rectPos.x, rectPos.y, i * 3, i * 3);
        //ofSetColor(alternateColor, ofMap(i, 0, 10, 50, 100));
        //ofFill();
        //ofCircle(rectPos.x, rectPos.y, i * 3, i * 3);
        ofPopMatrix();
        ofPopStyle();

        
    }
    
}

//--------------------------------------------------------------
void topography::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void topography::keyReleased(int key){
    
}

