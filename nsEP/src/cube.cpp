
#include "cube.h"

//--------------------------------------------------------------
void cube::setup(){
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    alternateColor.set(250, 0, 90);
    alpha = 255;
}

//--------------------------------------------------------------
void cube::update(float rotateSpeed){
    
    rotate += rotateSpeed;
    
  
}

//--------------------------------------------------------------
void cube::draw(){
    
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofTranslate(rectPos);
    ofScale(1.0, 1.0);
    ofRect(0, 0, 400, 300);
    ofPopMatrix();
    
    drawCube(alternateColor, .75);
    drawCube(ofColor::white, 3.0);
   

}

void cube::drawCube(ofColor c, float scale) {
    
    ofPushStyle(); 
    ofSetBoxResolution(100);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofPushMatrix();
    ofTranslate(rectPos);
    ofScale(scale, scale);
    ofRotateX(rotate);
    ofRotateY(rotate);
    ofRotateZ(rotate);
    
    ofSetColor(c, alpha);
    ofFill();
    ofDrawBox(50);
    
    ofSetColor(ofColor::white);
    ofNoFill();
    ofDrawBox(50);
    
    ofPopMatrix();
    ofDisableAlphaBlending();
    ofDisableDepthTest();
    ofPopStyle();
    
    
}


//--------------------------------------------------------------
void cube::keyPressed(int key){
    
  
}

//--------------------------------------------------------------
void cube::keyReleased(int key){
    
}

//--------------------------------------------------------------
void cube::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void cube::mouseDragged(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void cube::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void cube::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void cube::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void cube::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void cube::dragEvent(ofDragInfo dragInfo){ 
    
}
