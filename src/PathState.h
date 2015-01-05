//
//  PathState.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef __LineThing4__PathState__
#define __LineThing4__PathState__

#include <ofTypes.h>

#include "StateMachine.h"

struct PathStateParams {
  ofVec3f pt;
  ofColor color;
  float amount;
};

class PathState {
public:
  PathState(StateId id) : _id(id) {}

  StateId update(PathStateParams& params);
  
  StateId id() const { return _id; }
  
  PathState& setColors(ofColor start, ofColor end) {
    _startColor = start;
    _endColor = end;
    return *this;
  }
  
  PathState& setPositions(ofVec3f start, ofVec3f end) {
    _startPos = start;
    _endPos = end;
    return *this;
  }
  
  PathState& setNext(StateId nextId) {
    _nextId = nextId;
    return *this;
  }
private:
  const StateId _id;
  ofVec3f _startPos;
  ofVec3f _endPos;
  ofColor _startColor;
  ofColor _endColor;
  StateId _nextId;
  float _i;
};

class PathStateMachine : public StateMachine<PathState, PathStateParams> {
public:
  void update(float amount, ofVec3f* pt, ofColor* color);
  PathState& addState(StateId id);
};

#endif /* defined(__LineThing4__PathState__) */
