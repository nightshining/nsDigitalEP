#pragma once

#include "ofMain.h"
#include "circles.h"
#include "triangle.h"
#include "ring.h"
#include "bar.h"
#include "sculpture.h"
#include "cube.h"

#include "fftData.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
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
		
    circles cir;
    triangle tri;
    ring r; //use with sequencer type song
    bar b; //use with bass arp sounding song
    sculpture sculpt; //use with tribal sounding
    cube c; //use with last song
    
    ofVec2f size, pos;
    ofVec2f sPos1, sPos2, sPos3, sPos4, sPos5, sPos6;
    bool object1, object2, object3, object4, object5, object6;
    float timeline;
    fftData audioReactiveData;
    
    //Text
    ofTrueTypeFont font;
};
