#pragma once

#include "ofMain.h"

class topography {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofPoint rectPos;
    ofColor alternateColor;
    int alpha;
    float rotate, sine, sendSine;
    vector<ofVec2f> points;
};