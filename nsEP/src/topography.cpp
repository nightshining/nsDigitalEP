
#include "topography.h"

//--------------------------------------------------------------
void topography::setup() {
    
    //One Rect for background
    rectPos.set(0, 0);
    
    alternateColor.set(250, 0, 90);
    alpha = 255;
    
    int pointSize = 10;
    
    points.resize(pointSize);
    
    for (int i = 0; i < points.size(); i++) {
        
        points[i].set(ofRandom(500), ofRandom(500));
        
    }
}

//--------------------------------------------------------------
void topography::update() {
    

   
}

//--------------------------------------------------------------
void topography::draw(){
    
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofTranslate(rectPos);
    ofScale(1.0, 1.0);
    ofRect(0, 0, 400, 300);
    ofPopMatrix();
   
    
    for (int i = 0; i < points.size(); i++) {

    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(alternateColor);
        ofBeginShape();
        ofCurveVertex(points[i].x, points[i].y);

        ofEndShape();
    
    
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

