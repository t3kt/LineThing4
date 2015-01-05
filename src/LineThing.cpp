//
//  LineThing.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "LineThing.h"
#include <ofMain.h>

static const StateId STATE_A = 1;
static const StateId STATE_B = 2;
static const StateId STATE_C = 3;
static const int POINTS_TRAIL_SIZE = 60;

LineThing::LineThing() { }

static ofVec3f scalePoint(ofVec3f pt) {
  pt.x = ofMap(pt.x, -1, 1, 0, ofGetWidth());
  pt.y = ofMap(pt.y, -1, 1, 0, ofGetHeight());
  return pt;
}

static ofVec3f makePoint(float x, float y) {
  ofVec3f pt;
  return scalePoint(ofVec3f(x, y));
}

void LineThing::setup() {
  ofColor c1(51, 0, 185);
  ofColor c2(0, 154, 168);
//  ofColor c2 = ofColor::red;
  _pathStates1.addState(STATE_A)
    .setPositions(makePoint(1, 1), makePoint(-1, 0))
    .setColors(c1, c2)
    .setNext(STATE_B);
  _pathStates1.addState(STATE_B)
    .setPositions(makePoint(0, -1), makePoint(.5, -1))
    .setColors(c2, c1)
    .setNext(STATE_C);
  _pathStates1.addState(STATE_C)
    .setPositions(makePoint(.25, -.5), makePoint(.75, -1))
    .setColors(c1, c2)
    .setNext(STATE_A);
  _pathStates1.goTo(STATE_A);
  _pathStates2.addState(STATE_A)
    .setPositions(makePoint(-1, 0), makePoint(1, 1))
    .setColors(c1, c2)
    .setNext(STATE_B);
  _pathStates2.addState(STATE_B)
    .setPositions(makePoint(.5, -1), makePoint(0, -1))
    .setColors(c2, c1)
    .setNext(STATE_A);
  _pathStates2.goTo(STATE_B);
  _pointsMesh.setMode(OF_PRIMITIVE_LINES);
}

void LineThing::update() {
  ofVec3f pt1;
  ofVec3f pt2;
  ofColor color1;
  ofColor color2;
  _pathStates1.update(0.01, &pt1, &color1);
  _pathStates2.update(0.01, &pt2, &color2);
  _pointsMesh.addVertex(pt1);
  _pointsMesh.addColor(color1);
  _pointsMesh.addVertex(pt2);
  _pointsMesh.addColor(color2);
  while (_pointsMesh.getNumVertices() > POINTS_TRAIL_SIZE * 2) {
    _pointsMesh.removeVertex(0);
    _pointsMesh.removeColor(0);
  }
}

void LineThing::draw() {
  ofPushStyle();
  ofPushMatrix();
  ofSetLineWidth(1);
  ofNoFill();
  _pointsMesh.draw();
//  if (_pointsMesh.getNumVertices() > 0) {
//    int i = _pointsMesh.getNumVertices() - 1;
//    ofVec3f pt = _pointsMesh.getVertex(i);
//    ofColor color = _pointsMesh.getColor(i);
//    ofNoFill();
//    ofSetColor(color);
//    ofDrawIcoSphere(pt, 25.0);
//  }
  ofPopMatrix();
  ofPopStyle();
}
