#pragma once

#include "ofMain.h"

class sculpture {
    
public:
    void setup();
    void update(float rotateSpeed);
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
   
    
    ofPoint rectPos;
    ofVec2f rotate;
    float noise, sendNoise;
    void drawSculpt();
    
    int alpha;
};