#pragma once

#include "ofMain.h"


class track {
    
public:
    void setup(int posX, int posY);
    void update();
    void draw(string trackTitle);
    
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    //Text
    ofTrueTypeFont trackFont;
    ofRectangle clickPad;
    ofPoint clickPos;
    ofColor altColor;
    int alpha, rectW, rectH;
    bool alphaOn;
};
