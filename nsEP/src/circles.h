#pragma once

#include "ofMain.h"

class circles {
    
public:
    void setup();
    void reset();
    void draw();
    void cir(ofVec2f position, int radius, int alpha);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<ofVec2f> position;
    vector<int> radius;
    vector<int> alpha;
    float radiusReact;
    ofPoint rectPos;
    ofColor altColor;
};
