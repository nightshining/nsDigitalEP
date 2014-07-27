#pragma once

#include "ofMain.h"

class cube {
    
public:
    void setup();
    void update(float rotateSpeed);
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofPoint rectPos;
    ofColor alternateColor;
    void drawCube(ofColor c, float scale);
    int alpha;
    float rotate;
};