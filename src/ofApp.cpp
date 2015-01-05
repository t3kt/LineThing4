#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//  _cam.setTarget(ofVec3f(0.0, 0.0, 0.0));
//  _cam.setRotation(0.0, 0.2);
//  _cam.setupPerspective(false);
//  _cam.setFov(60);
//  _cam.setPosition(0, 0, -10);
  _lineThing.setup();
  ofDisableLighting();
  ofSetFrameRate(60);
  ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
  _lineThing.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  //_cam.setDistance(10);
//  _cam.begin();
  
  _lineThing.draw();
  
//  _cam.end();
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
//  _cam.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//  _cam.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//  _cam.mouseReleased(x, y, button);
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
