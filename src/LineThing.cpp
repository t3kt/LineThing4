//
//  LineThing.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "LineThing.h"
#include <ofMain.h>
#include <iostream>

static const StateId STATE_A = 1;
static const StateId STATE_B = 2;
static const StateId STATE_C = 3;
static const int POINTS_TRAIL_SIZE = 200;

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

static ofVec3f reflectX(ofVec3f pt) {
  return ofVec3f(ofGetWidth() - pt.x, pt.y, pt.z);
}

static VertexData makeVertex(float x, float y, ofColor c) {
  return VertexData(makePoint(x, y), c);
}

void LineThing::setup() {
  PathStateChain chain = PathStateChain()
    .add(STATE_A,
         makeVertex(1, -0.25, ofColor(51, 0, 185, 127)))
    .add(STATE_B,
         makeVertex(-.5, 0.25, ofColor(0, 170, 102, 255)))
    .add(STATE_C,
         makeVertex(0.75, -1, ofColor(0, 170, 102, 127)));
  
  _pathStates1.addStates(chain.buildStates(true));
  _pathStates1.goTo(STATE_A);
  
  _pathStates2.addStates(chain.buildStates(true));
  _pathStates2.goTo(STATE_B);
  
  std::cout << "PathStates1:" << std::endl;
  std::cout << _pathStates1 << std::endl;
  
  
  _pointsMesh.setMode(OF_PRIMITIVE_LINES);
}

void LineThing::update() {
  VertexData v1;
  VertexData v2;
  _pathStates1.update(0.01, &v1);
  _pathStates2.update(0.01, &v2);
  v1.addToMesh(&_pointsMesh);
  v2.addToMesh(&_pointsMesh);
  v1.getXFlipped().addToMesh(&_pointsMesh);
  v2.getXFlipped().addToMesh(&_pointsMesh);
  while (_pointsMesh.getNumVertices() > POINTS_TRAIL_SIZE * 4) {
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
