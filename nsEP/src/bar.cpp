
#include "bar.h"

//--------------------------------------------------------------
void bar::setup(){
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    vel.set(0.75f, 1.0f);
    

}

//--------------------------------------------------------------
void bar::update(){
    

    rotate += vel;

    
    noise += 0.05f;
    sendNoise = 255.0 * ofNoise(noise);
    
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
                ofSetColor(ofColor::white);
            }
            
        ofTranslate(rectPos.x - 60, rectPos.y - 50);   
        ofTranslate(i, j);   
        ofRotateX(rotate.x + i * PI / 2);
        ofRotateY(rotate.y + i * PI / 2);
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

//--------------------------------------------------------------
void bar::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void bar::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void bar::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void bar::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void bar::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void bar::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void bar::dragEvent(ofDragInfo dragInfo){ 
    
}
