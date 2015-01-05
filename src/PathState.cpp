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
    params.vertex = endVertex;
    _i = 0;
    return nextId;
  }
  params.vertex = startVertex.getLerped(endVertex, _i);
  return id;
}

void PathStateMachine::update(float amount, VertexData* vertex) {
  PathStateParams params;
  params.amount = amount;
  StateMachine<PathState, PathStateParams>::update(params);
  *vertex = params.vertex;
}

PathState& PathStateMachine::addState(StateId id) {
  PathState* state = new PathState(id);
  StateMachine<PathState, PathStateParams>::addState(ofPtr<PathState>(state));
  return *state;
}

void PathStateMachine::addStates(PathStateChain &chain) {
  for (auto& state : chain.states()) {
    StateMachine<PathState, PathStateParams>::addState(state);
  }
}

PathStateChain& PathStateChain::start(StateId id,
                                      VertexData v1,
                                      VertexData v2) {
  PathState* state = new PathState(id);
  state->setStart(v1)
        .setEnd(v2);
  _states.push_back(ofPtr<PathState>(state));
  return *this;
}

PathStateChain& PathStateChain::add(StateId id, VertexData vertex) {
  ofPtr<PathState>& prevState = _states.back();
  PathState* state = new PathState(id);
  state->setStart(prevState->endVertex)
        .setEnd(vertex);
  prevState->nextId = id;
  _states.push_back(ofPtr<PathState>(state));
  return *this;
}

PathStateChain& PathStateChain::loop() {
  _states.back()->nextId = _states.front()->id;
  return *this;
}
