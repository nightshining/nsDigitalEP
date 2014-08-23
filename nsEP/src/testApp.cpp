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
    graph.setup();
    }
    
    pos.set(ofGetWidth(), ofGetHeight());
    //size.set(1.0, 1.0);
    
    font.loadFont("font/codeFont.otf", 48);

    int totalTracks = 6;
    programNum.resize(totalTracks);
    
    for (int i = 0; i < programNum.size(); i++) {
        programNum[i] = false;
    }
    
    trackTitle.setup(50, 50);
    
}

//--------------------------------------------------------------
void testApp::update(){

    tri.update();
    r.update();
    
    audioReactiveData.update();
    
    //// AUDIO REACTIVE MODE ////
    
    
    ///Circles///
    
   // cir.radiusReact = audioReactiveData.spectrum[1] * 10;
   // for (int i = 0; i < cir.alpha.size(); i++) {
   // cir.alpha[i] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0, 255);
   // }
    
    cir.update();
    
    cir.sendAlpha[0] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0, 250);
    cir.sendAlpha[1] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 25, 100);
    cir.sendAlpha[2] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 50, 150);
    cir.sendAlpha[3] = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 100, 200);

    cir.sineSpeed = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0, 0.10);
    
    if (audioReactiveData.normValue == 0 && audioReactiveData.sendValue1 <= 0.25) {
        cir.reset();        
    }
    
    ///Triangle///
    tri.radius = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0, 20.0);
    tri.easing.x = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, .50, 10.0);
    tri.easing.y = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 1.0, 7.0);
    
    ///Ring///
    r.noiseSpeed = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 0.50f);
    r.vel.x = audioReactiveData.sendValue1;
    r.vel.y = audioReactiveData.sendValue2;
    
    ///Bar Circles///
    b.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 2.0f));
    b.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, -200, 255);
    
    
    ///Rectangles///
    
    sculpt.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 4.0f));
    sculpt.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0, 255);
 
    ///Topo///
    graph.update();

    
    timeline = audioReactiveData.sound.getPosition();
    
   
    
    ///Change Objects Based on Track

    if (timeline == ofWrap(timeline, 0.00, 0.0999)) {
        
        programNum[0] = true;
        
    } else {
        
        programNum[0] = false;
    }
    
    if (timeline == ofWrap(timeline, 0.100, 0.2189)) {
        
        programNum[1] = true;
        
    } else {
        
        programNum[1] = false;
    }
    
    
    if (timeline == ofWrap(timeline, .219, .3189)) {
        
        programNum[2] = true;
    
    } else {
        
        programNum[2] = false;
    }
    
    if (timeline == ofWrap(timeline, .319, .5359)) {
        
        programNum[3] = true;
        
    } else {
        
        programNum[3] = false;
    }
    
    
    if (timeline == ofWrap(timeline, .536, .7009)) {
        
        programNum[4] = true;
        
    } else {
        
        programNum[4] = false;
    }
    
    if (timeline == ofWrap(timeline, .701, 1.0)) {
        
        programNum[5] = true;
        
    } else {
        
        programNum[5] = false;
    }

    trackTitle.update();

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
    
    ///Time and Song Titles
    ofPushStyle(); 
    ofPushMatrix(); 
    ofSetColor(ofColor::black);
    ofNoFill();
    font.drawString(ofToString(audioReactiveData.sound.getPositionMS()), ofGetWidth() * 0.10, ofGetHeight() * 0.15);
    ofPopMatrix();
    ofPopStyle();
    
    ///Draw Objects///
    
    ofPushMatrix();
    
        {
            
    ofScale(size.x, size.y);
            
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
                        
    if(programNum[5] == true) {
    ofPushMatrix();
    ofTranslate(pos.x * .10, pos.y * .25);
    cir.draw();
    ofPopMatrix();
    }
                
    if(programNum[1] == true) {
    ofPushMatrix();
    ofTranslate(pos.x * .50, pos.y * .25);
    tri.draw();
    ofPopMatrix();
            }
        
    
    if(programNum[2] == true) {
    ofPushMatrix();
    ofTranslate(pos.x * .90, pos.y * .25);
    r.draw();
    ofPopMatrix();
    }
    
    if(programNum[3] == true) {   
    ofPushMatrix();
    ofTranslate(pos.x * .10, pos.y * .80);
    b.draw();
    ofPopMatrix();
    }
             
    if(programNum[4] == true) {
    ofPushMatrix();
    ofTranslate(pos.x * .50, pos.y * .80);
    sculpt.draw();
    ofPopMatrix();
    }
    
    if (programNum[0] == true) {  
    ofPushMatrix();
    ofTranslate(pos.x * .90, pos.y * .80);
    graph.draw();
    ofPopMatrix();
             
            }
        }
    ofPopMatrix();
    
    //Sound Utils
    audioReactiveData.showLength();
    audioReactiveData.songAnalyzer();
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Position:" + ofToString(timeline), 400, 100);
    
    trackTitle.draw("Track 1");
   
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    cir.keyPressed(key);
    
    if (key == '1') {
        size.set(1.0, 1.0);
        pos.set(0, 0);
        sPos1.set(0, 0);
        sPos2.set(0, 0);
        sPos3.set(0, 0);
        sPos4.set(0, 0);
        sPos5.set(0, 0);
        sPos6.set(0, 0);
        
        
    } else if (key == '2') {
        pos.set(ofGetWidth(), ofGetHeight());

        size.set(.50, .50);
        
        sPos1.set(.10, .25);
        sPos2.set(.50, .25);
        sPos3.set(.90, .25);
        sPos4.set(.10, .80);
        sPos5.set(.50, .80);
        sPos6.set(.90, .80);
     
        
    
    }
    
    audioReactiveData.selectBand(key);
    
    //0.0 0.99

    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    audioReactiveData.sound.setPosition(ofMap(x, 0, ofGetWidth(), 0.0, 1.0));
    trackTitle.mouseMoved(x, y);
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
