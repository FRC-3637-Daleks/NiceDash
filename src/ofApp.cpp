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

    mosqpp::lib_init();

    mqtt_obj = new mqtt("NiceDash");
    std::cout << "Connecting" << std::endl;
    mqtt_obj->connect("10.36.37.2", 1180);
    std::cout << "Connected" << std::endl;
    mqtt_obj->loop_start();

}

//--------------------------------------------------------------
void ofApp::update(){
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
    mosqpp::lib_cleanup();
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){

}
