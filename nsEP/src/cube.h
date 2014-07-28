#pragma once

#include "ofMain.h"

class cube {
    
public:
    void setup();
    void update(float rotateSpeed, float sineSpeed, float sineSize);
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofPoint rectPos;
    ofColor alternateColor;
    void drawCube(ofColor c, float scale);
    int alpha;
    float rotate, sine, sendSine;
};