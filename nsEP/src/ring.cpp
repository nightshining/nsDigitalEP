
#include "ring.h"

//--------------------------------------------------------------
void ring::setup(){
    
    //One Rect for background
    rectPos.set(0, 0);
    
    vel.set(0.25f, 0.45f);
    noiseSpeed = 0.0f;
}

//--------------------------------------------------------------
void ring::update(){
    
    rotate += vel;
    
    noise += noiseSpeed;
    sendNoise = 3.0 * ofNoise(noise);
    
}

//--------------------------------------------------------------
void ring::draw(){
    
    
    //one rect for background
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofRect(rectPos, 400, 300);
    ofPopMatrix();
    
    for (int i = 0; i < 150; i += 5) {
        
    ofPushStyle(); {
        
        ofPushMatrix(); {
            
            ofSetCircleResolution(100);
            ofTranslate(rectPos);
            ofScale(2.0, 2.0);
            ofRotateY(rotate.x + i * PI / 2);
            ofRotateX(rotate.y);
            ofSetColor(ofColor::white, i);
            ofNoFill();
            ofCircle(0, 0, 50);
            
        } ofPopMatrix();
        
    } ofPopStyle();
        
        ofPushStyle(); {
            
            ofPushMatrix(); {
                
                ofSetCircleResolution(100);
                ofTranslate(rectPos);
                ofScale(sendNoise, sendNoise);
                ofRotateY(rotate.x + i * PI / 2 );
                ofRotateX(rotate.y);
                ofSetColor(250, 0, 90, i);
                ofNoFill();
                ofCircle(0, 0, 10);
                
            } ofPopMatrix();
            
        } ofPopStyle();
        
    }

}


//--------------------------------------------------------------
void ring::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ring::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ring::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void ring::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ring::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ring::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ring::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ring::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ring::dragEvent(ofDragInfo dragInfo){ 
    
}
