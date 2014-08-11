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
    
    pos.set(ofGetWidth(), ofGetHeight());
    //size.set(1.0, 1.0);
    
    font.loadFont("font/codeFont.otf", 48);
    
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
 
    
    ///Cube///
    c.update(ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 4.0f), ofMap(audioReactiveData.sendValue1, 0.0, 1.0, 0.0f, 4.0f), 10.0);
    c.alpha = ofMap(audioReactiveData.sendValue1, 0.0, 1.0, -100, 255);
    
    
    timeline = audioReactiveData.sound.getPosition();
    
    if (timeline < .2) {
        object1 = true;
    }
    if (timeline > .2) {
        object1 = false;
        object2 = true;
    }
    if (timeline > .5) {
        object2 = false;
        object3 = true;
    }
    if (timeline > .7) {
        object3 = false;
        object4 = true;
    }
    if (timeline > .8) {
        object4 = false;
        object5 = true;
    }
    if (timeline > .9) {
        object5 = false;
        object6 = true;
    }
    
    
    cout << "Play Position: " << audioReactiveData.sound.getPosition() << endl;

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
            
    if (object1 == true) {
                

    ofPushMatrix();
    ofTranslate(pos.x * .10, pos.y * .25);
    cir.draw();
    ofPopMatrix();
    
    }
    
    if (object2 == true) {

    ofPushMatrix();
    ofTranslate(pos.x * .50, pos.y * .25);
    tri.draw();
    ofPopMatrix();
     
    }
    
    if (object3 == true) {

    ofPushMatrix();
    ofTranslate(pos.x * .90, pos.y * .25);
    r.draw();
    ofPopMatrix();
    
    }
    
    if (object4 == true) {

    ofPushMatrix();
    ofTranslate(pos.x * .10, pos.y * .80);
    b.draw();
    ofPopMatrix();
     
    }
    
    if (object5 == true) {

    ofPushMatrix();
    ofTranslate(pos.x * .50, pos.y * .80);
    sculpt.draw();
    ofPopMatrix();
    
    }
    
    if (object6 == true) {

    ofPushMatrix();
    ofTranslate(pos.x * .90, pos.y * .80);
    c.draw();
    ofPopMatrix();
    
    }
            
        }
    ofPopMatrix();
    
    //Sound Utils
    audioReactiveData.showLength();
    audioReactiveData.songAnalyzer();
    
    
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
        
        object1 = false;
        object2 = false;
        object3 = false;
        object4 = false;
        object5 = false;
        object6 = false;
        
    
    }
    
    audioReactiveData.selectBand(key);
    
    switch (key) {
        case '1':
            object1 = true;
            break;
        case '2':
            object2 = true;
            break;
        case '3':
            object3 = true;
            break;
        case '4':
            object4 = true;
            break;
        case '5':
            object5 = true;
            break;
        case '6':
            object6 = true;
            break;
            
        default:
            break;
    }
    
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
