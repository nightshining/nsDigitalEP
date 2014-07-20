
#include "cube.h"

//--------------------------------------------------------------
void cube::setup(){
    
    //One Rect for background
    rectPos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
    
    int circleAmt = 10;
    
    cirSize.resize(circleAmt);
    
    for (int i = 0; i < cirSize.size(); i++) {
        
        cirSize[i] = ofRandom(10, 25);
    }
    
    circlePoints.resize(circleAmt);
    
    ofColor meshColor = ofColor::lightGray;
    meshColor.a = 100;
    mesh.enableColors();
    mesh.enableIndices();
    
    mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    for (int i = 0; i < circlePoints.size(); i++) {
        
        circlePoints[i].set(ofRandom(rectPos.x, 50), ofRandom(rectPos.y, 50), ofRandom(rectPos.z, -100));
        mesh.addVertex(circlePoints[i]);
        mesh.addIndex(i);
        mesh.addColor(meshColor);
    }
    
   
    alternateColor.set(250, 0, 90);

}

//--------------------------------------------------------------
void cube::update(){
    
    
    
   
    for (int i = 0; i < circlePoints.size(); i++) {
        
        circlePoints[i].y = diffFloating(ofMap(i, 0, 10, 1.0, 150.0), ofMap(i, 0, 10, 0.001, 0.003));
        mesh.setVertex(i, circlePoints[i]);
    }
    
    /*for (int i = 0; i < circlePoints.size(); i++) {

        circlePoints[i].y = sendNoise + sin(i);
    }*/

}


float cube::diffFloating(float verticalAmt, float speed) {
    
    noise += speed;
    sendNoise = verticalAmt * sin(noise);
    
    return sendNoise;
    
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
    
    cam.begin();
    for (int i = 0; i < circlePoints.size(); i++) {
        ofPushStyle();
        ofSetSphereResolution(100);
        ofPushMatrix();
        ofSetColor(alternateColor, 200);
        ofFill();
        ofDrawSphere(circlePoints[i], cirSize[i]);
        
        ofSetColor(ofColor::black, 200);
        ofDrawSphere(circlePoints[i], 2);

        mesh.draw();
        
        ofPopMatrix();
        ofPopStyle();
    }
    cam.end();
}


//--------------------------------------------------------------
void cube::keyPressed(int key){
    
    for (int i = 0; i < circlePoints.size(); i++) {
        
    if (key == ' ') {
        randomPlay = ofRandom(i);
        }
    }
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
