#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#include "mqtt.h"
#include "mqtt_thread.h"
#include "uiPanel.h"
#include "uiPanelStatus.h"
#include "uiPanelPDP.h"

class ofApp : public ofBaseApp{

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
        void exit();
        void guiEvent(ofxUIEventArgs &e);

    private:
        mqtt *mqtt_obj;
        mqtt_thread *thread;
        std::vector<uiPanel *> panels;
};
