
#include "sculpture.h"

//--------------------------------------------------------------
void sculpture::setup(){
    
    //One Rect for background
    rectPos.set(0, 0);
        
    
}

//--------------------------------------------------------------
void sculpture::update(float rotateSpeed){
    
    
    rotate.x += rotateSpeed;
    rotate.y += rotateSpeed;
    
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
                        
                        ofSetColor(250, 0, 90, alpha);

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


