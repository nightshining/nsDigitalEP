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
    keyFont.loadFont("font/codeFont.otf", 10);
    sampleKeyOn = false;

    int totalTracks = 6;
    programNum.resize(totalTracks);
    
    float textPosLeft = ofGetWidth() * 0.05;
    
    for (int i = 0; i < programNum.size(); i++) {
        programNum[i] = false;
    }
    
    
    trackTitle.resize(totalTracks);
    trackTitle[0].setup(textPosLeft, ofGetHeight() * .25, 1.10);
    trackTitle[1].setup(textPosLeft, ofGetHeight() * .30, 1.09);
    trackTitle[2].setup(textPosLeft, ofGetHeight() * .35, 1.08);
    trackTitle[3].setup(textPosLeft, ofGetHeight() * .40, 1.07);
    trackTitle[4].setup(textPosLeft, ofGetHeight() * .45, 1.06);
    trackTitle[5].setup(textPosLeft, ofGetHeight() * .50, 1.05);
    
    //setup
    audioReactiveData.sound.play();
    audioReactiveData.sound.setPosition(0.0);
    
    
    size.set(1.0, 1.0);
    pos.set(0, 0);
    sPos1.set(0, 0);
    sPos2.set(0, 0);
    sPos3.set(0, 0);
    sPos4.set(0, 0);
    sPos5.set(0, 0);
    sPos6.set(0, 0);
    
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

    if (audioReactiveData.sound.getIsPlaying()) {
        
    
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

    for (int i = 0; i < trackTitle.size(); i++) {
        
    trackTitle[i].update();
        
    }
    
        }

    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ///Title Text///
    ofPushStyle(); 
    ofPushMatrix();
    ofSetCircleResolution(4);
    ofSetColor(ofColor::whiteSmoke);
    ofFill();
    ofCircle(ofGetWidth() * 0.06, ofGetHeight() * 0.12, 50);
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
    
    //DEBUG TIME 
    //ofSetColor(ofColor::black);
    //ofDrawBitmapString("Position:" + ofToString(timeline), 400, 100);
    for (int i = 0; i < trackTitle.size(); i++) {
        trackTitle[i].draw("Track" + ofToString(i));
    }
    
    sampleKeys();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    cir.keyPressed(key);
    
    if (key == '1') {
        
        audioReactiveData.sound.play();
        audioReactiveData.sound.setPosition(0.0);
      
        
        size.set(1.0, 1.0);
        pos.set(0, 0);
        sPos1.set(0, 0);
        sPos2.set(0, 0);
        sPos3.set(0, 0);
        sPos4.set(0, 0);
        sPos5.set(0, 0);
        sPos6.set(0, 0);
        
        
    } else if (key == '2') {
        
        audioReactiveData.sound.stop();
        audioReactiveData.sound.setPosition(0.0);
        
        for (int i = 0; i < programNum.size(); i++) {
            programNum[i] = true;
        }
        
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

    if (!audioReactiveData.sound.getIsPlaying()) {
        
        switch (key) {
            case 'a':
                audioReactiveData.drum1.play();
                break;
            
            case 's':
                audioReactiveData.drum2.play();
                break;
            
            case 'd':
                audioReactiveData.bass1.play();
                break;
            
            case 'j':
                audioReactiveData.bass2.play();
                break;
                
            case 'k':                
                audioReactiveData.pad.play();
                break;
                
            case 'l':
                audioReactiveData.keys.play();
                break;
                
            default:
                break;
        } 
        
        sampleKeyOn = true;
        
    } else {
        
        audioReactiveData.drum1.stop();
        audioReactiveData.drum2.stop();
        audioReactiveData.bass1.stop();
        audioReactiveData.bass2.stop();
        audioReactiveData.pad.stop();
        audioReactiveData.keys.stop();
        
        sampleKeyOn = false;
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    
    for (int i = 0; i < trackTitle.size(); i++) {
    trackTitle[i].mouseMoved(x, y);
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < trackTitle.size(); i++) {
        trackTitle[i].mousePressed(x, y);
    }
    
    if (trackTitle[0].trackToggle == true) {
    audioReactiveData.sound.setPosition(0.0);
   
    }
    
    else if (trackTitle[1].trackToggle == true) {
        audioReactiveData.sound.setPosition(0.100);

    } 
    else if (trackTitle[2].trackToggle == true) {
        audioReactiveData.sound.setPosition(0.219);

    }
    else if (trackTitle[3].trackToggle == true) {
        audioReactiveData.sound.setPosition(0.319);

    }
    else if (trackTitle[4].trackToggle == true) {
        audioReactiveData.sound.setPosition(0.536);

    }
    else if (trackTitle[5].trackToggle == true) {
        audioReactiveData.sound.setPosition(0.701);

    }
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < trackTitle.size(); i++) {
        trackTitle[i].mouseReleased(x, y);
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::sampleKeys() {
    
    if (sampleKeyOn) {

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(ofGetWidth() * .70, ofGetHeight() * .85);
    ofSetColor(ofColor::black);
    keyFont.drawString("Play Sounds: 'a' 's' 'd' 'j' 'k' 'l'", 0, 0);
    
    ofPopMatrix();
    ofPopStyle();
    } else {
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(ofGetWidth() * .70, ofGetHeight() * .85);
    ofSetColor(ofColor::black);
    keyFont.drawString("Mode Listen '1' :: Mode Play '2'", 0, 0);

    ofPopMatrix();
    ofPopStyle();
    }
    
}


