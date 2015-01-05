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
  
  ofPushStyle();
  ofSetLineWidth(2);
  ofSetColor(0, 255, 0);
  ofLine(ofVec3f(-10, 0, 0), ofVec3f(10, 0, 0));
  ofLine(ofVec3f(0, -10, 0), ofVec3f(0, 10, 0));
  ofLine(ofVec3f(0, 0, -10), ofVec3f(0, 0, 10));
//  ofFill();
//  ofSetColor(255, 0, 0);
////  ofDrawSphere(0, 0, 50);
//  ofNoFill();
//  ofSetColor(0, 255, 255);
//  ofDrawBox(ofVec3f(0, 0, 0), 20);
  ofPopStyle();
  
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
