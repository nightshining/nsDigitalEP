#include "fftData.h"


//--------------------------------------------------------------
void fftData::setup(){
    
    const int numBands = 256; //Number of bands in spectrum
    spectrum.resize(numBands);

    sound.loadSound( "songs/ep.aif" );
    sound.setLoop( true );
    sound.play();
    
    for (int i = 0; i < spectrum.size(); i++) {
        
        spectrum[i] = 0.0f;
        //cout << "Spectrum Array: " << spectrum[i] << endl;
    }
    
    bandRad = 2; //Band index in spectrum, affecting Rad value
    bandVel = 100; //Band index in spectrum, affecting Vel value
    
    cycleSpectrum = 0;
    
    //Analyzer
    altColor.set(250, 0, 90);
    barPos.set(50, ofGetHeight() - 100);
    
}

//--------------------------------------------------------------
void fftData::update(){
 
    ofSoundUpdate();
    
    float *val = ofSoundGetSpectrum(spectrum.size());
    
    for (int i = 0; i < spectrum.size(); i++) {
        
        spectrum[i] *= 0.97;
        spectrum[i] = max( spectrum[i], val [i] );
        //cout << "Refreshing Sound Spectrum: " << spectrum[i] << endl;
    }
    
    
    /// Some FFT values to use ///
    
    sendValue1 = ofMap(spectrum[1], 1, 3, 0.0, 1.0, true); //Normalized Value
    
    sendValue2 = ofMap(spectrum[bandVel], 0, 0.1, 0.05, 0.5);
    
    normValue = ofMap(spectrum[1], 1.0, 2.0, 0.0, 1.0);
    normValue = roundf(normValue); // Rounded value 0 / 1, off / on
    
    //cout << "Selected Band Value: " + ofToString()) << endl;
    
    /// Cycle Spectrum ///
    
    if (cycleSpectrum >= spectrum.size()) {
        
        cycleSpectrum == 0;
    
    } else if (cycleSpectrum <= 0) {
        
        cycleSpectrum == 0;

    }
    
}

//--------------------------------------------------------------
void fftData::songAnalyzer(){
   
    ofPushStyle();
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofTranslate(barPos.x, barPos.y + 100);
    
     for (int i = 0; i < 10; i++) {
        
        ofSetColor(altColor, 200);
        ofFill();
        ofRect(i * 7, 0, 4, -spectrum[i] * 50);

    }
        
    ofPopMatrix();
    ofPopStyle();
    
    /*
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(barPos.x + 25, barPos.y);
    ofSetCircleResolution(100);
    ofSetColor(altColor, 200);
    ofFill();
    ofCircle(0, 0, spectrum[cycleSpectrum] * 20);
    ofPopMatrix();
    ofPopStyle();
     */
}

void fftData::showLength() {
    
    float barSize = ofMap(sound.getPosition(), 0.0, 1.0, 10, 500);
    ofPushStyle();
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofTranslate(barPos);
    ofSetColor(ofColor::black);
    ofFill();
    ofRect(0, 0, barSize, 25);
    ofPopMatrix();
    ofPopStyle();
    
}

void fftData::selectBand(int key) {
    
    if (key == OF_KEY_UP) {
        
        cycleSpectrum++;
    } else if (key == OF_KEY_DOWN) {
        
        cycleSpectrum--;
    }
    
    
    
}

