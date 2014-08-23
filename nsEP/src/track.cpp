#include "track.h"

//--------------------------------------------------------------
void track::setup(int posX, int posY){
    
    rectW = 50;
    rectH = 20;
    clickPos.set(posX, posY);
    clickPad.setFromCenter(clickPos, rectW, rectH);
    altColor.set(250, 0, 90);
    alpha = 0;
    alphaOn = false;
    trackFont.loadFont("font/codeFont.otf", 12);


}

//--------------------------------------------------------------
void track::update(){
       
    if (alphaOn) {
        alpha += 5;
    } else if (!alphaOn) {
        alpha = 0;
    }
    
    if (alpha >= 255) {
        alpha = 255;
    }
}

//--------------------------------------------------------------
void track::draw(string trackTitle){
    
    ofPushStyle(); 
    ofPushMatrix(); 
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(0, 0, 0, alpha);
    ofTranslate(clickPos);
    
    ofRect(0, 0, rectW, rectH);
    ofPopMatrix();
    ofPopStyle();
   
    ofPushStyle(); 
    ofPushMatrix(); 
    ofSetColor(altColor);
    ofTranslate(clickPos);

    trackFont.drawString(trackTitle, 0, 0);
    
    ofPopMatrix();
    ofPopStyle();
    
  
}

void track::mouseMoved(int x, int y ){

    ofVec2f mousePos;
    mousePos.set(x, y);
if (clickPad.inside(mousePos)) {
    alphaOn = true;
    altColor.set(250, 0, 90, alpha);

    
} else {
    alphaOn = false;
    altColor.set(0);
}
    
}
//--------------------------------------------------------------
void track::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void track::mouseReleased(int x, int y, int button){
    
}

