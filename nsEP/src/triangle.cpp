#include "triangle.h"

//--------------------------------------------------------------
void triangle::setup(){
    
    ofLoadImage(triangle, "tri.png");
    
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    vel.set(0.25f, 0.45f);
}

//--------------------------------------------------------------
void triangle::update(){
    
    rotate += vel * easing;
    
    easing.set(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 2.50), ofMap(ofGetMouseY(), ofGetHeight(), 0, 0.0, 2.50));
    
    
}

//--------------------------------------------------------------
void triangle::draw(){
    
    
    //one rect for background
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofRect(rectPos, 400, 300);
    ofPopMatrix();
    
    ofPushStyle(); {
        ofPushMatrix(); {
        
        ofSetColor(250, 0, 90,  200);
        ofTranslate(rectPos);
        ofRotateX(rotate.x);
        ofRotateY(rotate.y);
        triangle.draw(0, 0);
        
        } ofPopMatrix();
    } ofPopStyle();
        
    ofPushStyle(); {
        ofPushMatrix(); {
        ofSetCircleResolution(100);
        ofTranslate(rectPos);
        ofSetColor(ofColor::black, 200);
        ofCircle(0, 0, 20);
        ofSetColor(ofColor::white, 200);
        ofCircle(0, 0, 5);
        
        
        } ofPopMatrix();
    } ofPopStyle();
}


//--------------------------------------------------------------
void triangle::keyPressed(int key){
    
}

//--------------------------------------------------------------
void triangle::keyReleased(int key){
    
}

//--------------------------------------------------------------
void triangle::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void triangle::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void triangle::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void triangle::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void triangle::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void triangle::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void triangle::dragEvent(ofDragInfo dragInfo){ 
    
}
