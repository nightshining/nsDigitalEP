
#include "sculpture.h"

//--------------------------------------------------------------
void sculpture::setup(){
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    vel.set(0.75f, 1.0f);
    
    
}

//--------------------------------------------------------------
void sculpture::update(){
    
    
    rotate += vel;
    
    
    noise += 0.05f;
    sendNoise = 255.0 * ofNoise(noise);
    
}


//--------------------------------------------------------------
void sculpture::draw(){
    
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofTranslate(rectPos);
    ofScale(1.0, 1.0);
    ofRect(0, 0, 400, 300);
    ofPopMatrix();
    
       ofPushStyle(); {
        
        ofSetIcoSphereResolution(.25);
           ofEnableAlphaBlending();
           ofEnableDepthTest();
           
        for (int i = 0; i < 150; i += 5) { //50
                        
            float scaleMap = ofMap(i, 0, 150, .25, 1.0);
            
            
                ofPushMatrix(); {
                    
                    if (i == 50) {
                        
                        ofSetColor(250, 0, 90);

                    } else {
                    
                        ofSetColor(ofColor::white, ofMap(i, 0, 150, 100, 200));
                    
                    }
                    
                    ofNoFill();
                    ofTranslate(rectPos);
                   // ofScale(scaleMap, scaleMap);
                    ofRotateY(rotate.y + i * PI / 2);
                    ofRotateX(rotate.x + i * PI / 2);

                    //ofDrawIcoSphere(i);
                
                    ofRect(0, 0, 150, 150);              
                    //cout << "i : " << i << endl;
                    
                } ofPopMatrix();
            }
           ofDisableDepthTest();
           ofDisableAlphaBlending();
        
    } ofPopStyle();
    
    
}

void sculpture::drawSculpt() {
    
   
    
}

//--------------------------------------------------------------
void sculpture::keyPressed(int key){
    
}

//--------------------------------------------------------------
void sculpture::keyReleased(int key){
    
}

//--------------------------------------------------------------
void sculpture::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void sculpture::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sculpture::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sculpture::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sculpture::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void sculpture::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void sculpture::dragEvent(ofDragInfo dragInfo){ 
    
}
