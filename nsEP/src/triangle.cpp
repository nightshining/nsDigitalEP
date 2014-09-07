#include "triangle.h"

//--------------------------------------------------------------
void triangle::setup(){
    
    ofLoadImage(triangle, "tri.png");
    
    
    //One Rect for background
    rectPos.set(0, 0);
    
    vel.set(0.25f, 0.45f);
    radius = 0.0;
}

//--------------------------------------------------------------
void triangle::update(){
    
    rotate += vel * easing;
    
  
    
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
        
        ofSetColor(0, 200, 150,  200);
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
        ofCircle(0, 0, 20 + radius);
        ofSetColor(ofColor::white, 200);
        ofCircle(0, 0, 5 + radius);
        
        
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
