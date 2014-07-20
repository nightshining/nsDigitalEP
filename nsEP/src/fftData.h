#pragma once

#include "ofMain.h"

class fftData {
    
public:
    void setup();
    void update();
    
    ofColor altColor;
    
    int bandRad, bandVel;
    vector<float> spectrum;
    ofSoundPlayer sound;

    
    float sendValue1, sendValue2, normValue;
    
    int cycleSpectrum;
    void selectBand(int key);
    
    //Song Analyzer
    void showLength();
    ofPoint barPos;
    
    void songAnalyzer();
    
};
