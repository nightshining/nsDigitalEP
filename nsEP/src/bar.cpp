
#include "bar.h"

//--------------------------------------------------------------
void bar::setup(){
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    
    alpha = 0;
}

//--------------------------------------------------------------
void bar::update(float rotateSpeed){
    

    rotate.x += rotateSpeed;
    rotate.y += rotateSpeed;
    
    noise += 0.05f;
    sendNoise = 255.0 * ofNoise(noise);
    
    //alpha -= 20.0;
}


//--------------------------------------------------------------
void bar::draw(){

    ofColor c = ofColor::black;
    ofColor c2 = ofColor::white;
    c2.a = sendNoise;
    
    drawRect(c, 1.0);
    //drawRect(c2, .50);
    
    ofPushStyle(); {
    
        ofSetCircleResolution(100);
    
    for (int i = 0; i < 150; i += 30) {

        for (int j = 0; j < 100; j += 30) {
            
        ofPushMatrix(); {
        
            if (i == 120 && j == 60) {
                ofSetColor(250, 0, 90);

            } else {
                ofSetColor(ofColor::white, alpha);
            }
            ofFill();
        ofTranslate(rectPos.x - 60, rectPos.y - 50);   
        ofTranslate(i, j);   
        ofRotateX(rotate.x + i * PI / 2);
        ofRotateY(rotate.y + i * PI / 2);
        ofCircle(0, 0, 10);
            
            
            if (i == 120 && j == 60) {
                ofSetColor(250, 0, 90);
                
            } else {
                ofSetColor(ofColor::white);
            }
            ofNoFill();
            ofCircle(0, 0, 10);
            
            //cout << "i : " << i << endl;
            //cout << "j : " << j << endl;

        } ofPopMatrix();
            
            }
        }
        
        
    } ofPopStyle();
        

}

void bar::drawRect(ofColor setColor, float size) {
    
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(setColor);
    ofTranslate(rectPos);
    ofScale(size, size);
    ofRect(0, 0, 400, 300);
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void bar::keyPressed(int key){
    
}

//--------------------------------------------------------------
void bar::keyReleased(int key){
    
}


