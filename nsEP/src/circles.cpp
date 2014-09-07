#include "circles.h"

//--------------------------------------------------------------
void circles::setup(){
    
    //One Rect for background
    rectPos.set(0, 0);
    
    //int circleAmt = 10;
    
    //position.resize(circleAmt);
    //radius.resize(circleAmt);
    //alpha.resize(circleAmt);
    
    //int randomPositioning = 150;
    
    //for (int i = 0; i < position.size(); i++) {
    //position[i].set(ofRandom(rectPos.x - randomPositioning, rectPos.x + randomPositioning), ofRandom(rectPos.y - randomPositioning, rectPos.y + randomPositioning));
    //}
    
    //for (int i = 0; i < radius.size(); i++) {
    //radius[i] = ofRandom(5, 30);
    //}
    
    //for (int i = 0; i < alpha.size(); i++) {
    //alpha[i] = ofRandom(0, 255);
    //}
    
    altColor.set(0, 200, 150);
    radiusReact = 0;
    
    int totalCircles = 3;
    sendAlpha.resize(totalCircles); //bc i size is 4 elements
    
    for (int i = 0; i < sendAlpha.size(); i++) {
    
        sendAlpha[i] = 0;
        
    }
    
    
}

//--------------------------------------------------------------
void circles::reset(){
    
    //int randomPositioning = 125;
    
    //for (int i = 0; i < position.size(); i++) {
        
    //    position[i].set(ofRandom(rectPos.x - randomPositioning, rectPos.x + randomPositioning), ofRandom(rectPos.y - randomPositioning, rectPos.y + randomPositioning));
        
    //}

    
    
}

void circles::update() {
    
    sine += sineSpeed;
    sendSine = 1.0 * sin(sine);
    sendSine = ofMap(sendSine, -1.0, 1.0, 0.0, 1.0);
}

//--------------------------------------------------------------
void circles::draw(){
    
    //one rect for background
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(ofColor::black);
    ofRect(rectPos, 400, 300);
    ofPopMatrix();
    
    
    
    newCir(sendAlpha[3], 95, ofColor::white);
    newCir(sendAlpha[2], 80, ofColor::white);
    newCir(sendAlpha[1], 65, ofColor::white);
    newCir(sendAlpha[0], 45, altColor);

   
    
    //for (int i = 0; i < position.size(); i++) {
    //    cir(position[i], radius[i], alpha[i]);
    
    //}
    
}

void circles::newCir(int alpha, int size, ofColor c) {
    
    ofPushStyle(); {
        
        ofPushMatrix(); {
            ofSetCircleResolution(100);
            ofSetColor(c, alpha);
            ofTranslate(rectPos);
            ofScale(.50 + sendSine, .50 + sendSine);
            ofCircle(0, 0, size);
            
            
        } ofPopMatrix();
        
    } ofPopStyle();
    
}

void circles::cir(ofVec2f position, int radius, int alpha) {
    
    ofPushStyle();
    ofPushMatrix();
    ofSetCircleResolution(100);
    ofSetColor(ofColor::white, alpha);
    ofCircle(position, radius + radiusReact);
    ofPopMatrix();
    ofPopStyle();
    
}

//--------------------------------------------------------------
void circles::keyPressed(int key){
    
   //int randomPositioning = 125;
    
   // for (int i = 0; i < position.size(); i++) {
        
     //   position[i].set(ofRandom(rectPos.x - randomPositioning, rectPos.x + randomPositioning), ofRandom(rectPos.y - randomPositioning, rectPos.y + randomPositioning));
        
    //}
    
    
    
}

//--------------------------------------------------------------
void circles::keyReleased(int key){
    
}

//--------------------------------------------------------------
void circles::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void circles::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circles::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circles::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void circles::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void circles::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void circles::dragEvent(ofDragInfo dragInfo){ 
    
}
