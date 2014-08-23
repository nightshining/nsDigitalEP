#pragma once

#include "ofMain.h"


class track {
    
public:
    void setup(int posX, int posY, float textPos);
    void update();
    void draw(string trackTitle);
    
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y);
    void mouseReleased(int x, int y);

    //Text
    ofTrueTypeFont trackFont;
    ofRectangle clickPad;
    ofPoint clickPos;
    ofColor altColor;
    int alpha, rectW, rectH;
    float textDrawPercent;
    bool trackToggle;
};
