#include "track.h"

//--------------------------------------------------------------
void track::setup(int posX, int posY, float textPos){
    
    rectW = 75;
    rectH = 25;
    //clickPos.set(posX, posY);
    clickPad.set(posX, posY, rectW, rectH);
    altColor.set(0, 200, 150);
    alpha = 0;
    trackFont.loadFont("font/codeFont.otf", 12);
    textDrawPercent = textPos;
    trackToggle = false;
}

//--------------------------------------------------------------
void track::update(){
    
   
}

//--------------------------------------------------------------
void track::draw(string trackTitle){
    
    ofPushStyle(); 
    ofPushMatrix(); 

    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(0, 0, 0, alpha);    
    ofRect(clickPad);
   
    ofTranslate(clickPad.getPosition() * textDrawPercent);
    ofSetColor(altColor);
   
    trackFont.drawString(trackTitle, 0, 0);
    
    ofPopMatrix();
    ofPopStyle();
    
  
}

void track::mouseMoved(int x, int y ){

    ofVec2f mousePos;
    mousePos.set(x, y);
if (clickPad.inside(mousePos)) {
    altColor.set(0, 200, 150);
    alpha = 255;
    
    
} else {
    altColor.set(0);
    alpha = 0;
}
    
}
//--------------------------------------------------------------
void track::mousePressed(int x, int y){
    
    
    ofVec2f mousePos;
    mousePos.set(x, y);
    if (clickPad.inside(mousePos)) {
        altColor.set(ofColor::white);
        trackToggle = true;
    } 
}

//--------------------------------------------------------------
void track::mouseReleased(int x, int y){
    
    ofVec2f mousePos;
    mousePos.set(x, y);
    if (clickPad.inside(mousePos)) {
        altColor.set(0, 200, 150);
        trackToggle = false;
    } 
}

