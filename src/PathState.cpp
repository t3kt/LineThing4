//
//  PathState.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "PathState.h"
#include <ofMain.h>

#include "Common.h"

StateId PathState::update(PathStateParams& params) {
  _i += params.amount;
  if (_i >= 1) {
    params.pt = _endPos;
    params.color = _endColor;
    _i = 0;
    return _nextId;
  }
  params.pt = lerp(_startPos, _endPos, _i);
  params.color = _startColor.getLerped(_endColor, _i);
  return _id;
}

void PathStateMachine::update(float amount, ofVec3f* pt, ofColor* color) {
  PathStateParams params;
  params.amount = amount;
  StateMachine<PathState, PathStateParams>::update(params);
  *pt = params.pt;
  *color = params.color;
}

PathState& PathStateMachine::addState(StateId id) {
  PathState* state = new PathState(id);
  StateMachine<PathState, PathStateParams>::addState(ofPtr<PathState>(state));
  return *state;
}
