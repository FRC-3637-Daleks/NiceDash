#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(65.0f);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();

    uiPanelStatus *status = new uiPanelStatus();
    status->setLocation(10, 10);
    panels.push_back(status);

    uiPanelPDP *pdp = new uiPanelPDP();
    pdp->setLocation(panels.back()->getLowerLeftX(), panels.back()->getLowerLeftY() + 10);
    panels.push_back(pdp);

    mosqpp::lib_init();

    mqtt_obj = new mqtt();
    std::cout << "Connecting..." << std::endl;
    mqtt_obj->connect_async("10.36.37.2", 1180);

    thread = new mqtt_thread(mqtt_obj);
    thread->startThread(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(vector<uiPanel *>::iterator panel = panels.begin(); panel != panels.end(); panel++) {
        (*panel)->update(mqtt_obj);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
void ofApp::exit(){
    thread->stopThread();
    mosqpp::lib_cleanup();
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){

}
