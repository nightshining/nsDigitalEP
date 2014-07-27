#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(ofColor::white);
    
    audioReactiveData.setup();
    
    if (audioReactiveData.sound.isLoaded()) {
    cir.setup();
    tri.setup();
    r.setup();
    b.setup();
    sculpt.setup();
    c.setup();
    }
    
    
    font.loadFont("font/codeFont.otf", 48);
    
}

//--------------------------------------------------------------
void testApp::update(){

    tri.update();
    r.update();
    
    
    audioReactiveData.update();
    
    //// AUDIO REACTIVE MODE ////
    
    
    ///Circles///
    
    cir.radiusReact = audioReactiveData.spectrum[1] * 10;
    for (int i = 0; i < cir.alpha.size(); i++) {
    cir.alpha[i] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0, 255);
    }
    
    if (audioReactiveData.normValue == 0 && audioReactiveData.sendValue1 <= 0.25) {
        cir.reset();        
    }
    
    ///Ring///
    
    r.noiseSpeed = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 0.50f);
    r.vel.x = audioReactiveData.sendValue1;
    r.vel.y = audioReactiveData.sendValue2;
    
    ///Bar Circles///
    b.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 2.0f));
    b.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, -200, 255);
    
    
    ///Rectangles
    
    sculpt.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 4.0f));
    sculpt.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0, 255);
 
    
    ///Cube
    c.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 4.0f));
    c.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, -100, 255);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ///Title Text///
    ofPushStyle(); 
    ofPushMatrix(); 
    ofSetColor(ofColor::black);
    ofNoFill();
    font.drawString("ns", ofGetWidth() * 0.03, ofGetHeight() * 0.15);
    ofPopMatrix();
    ofPopStyle();
    
    ///Draw Objects///
    
    /*
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofScale(size.x, size.y);
    cir.draw();
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(pos.x + 250, pos.y);
    ofScale(size.x, size.y);
    tri.draw();
    ofPopMatrix();
     
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofScale(size.x, size.y);
    r.draw();
    ofPopMatrix();
    

    ofPushMatrix();
    ofTranslate(pos.x, pos.y + 200);
    ofScale(size.x, size.y);
    b.draw();
    ofPopMatrix();
     
    
    ofPushMatrix();
    ofTranslate(pos.x + 250, pos.y + 200);
    ofScale(size.x, size.y);
    sculpt.draw();
    ofPopMatrix();
    
     */
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofScale(size.x, size.y);
    c.draw();
    ofPopMatrix();
     
    
    
    //Sound Utils
    audioReactiveData.showLength();
    audioReactiveData.songAnalyzer();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    cir.keyPressed(key);
    
    if (key == '1') {
        size.set(.50, .50);
        pos.set(100, 100);
        
    } else if (key == '2') {
        size.set(1.0, 1.0);
        pos.set(0,0);
    }
    
    audioReactiveData.selectBand(key);
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    audioReactiveData.sound.setPosition(ofMap(x, 0, ofGetWidth(), 0.0, 1.0));
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
