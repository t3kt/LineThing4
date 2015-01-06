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

std::ostream& operator<<(std::ostream& os,
                         const PathState& state) {
  os << "PathState{id:" << state.id;
  os << ", start:" << state.startVertex;
  os << ", end:" << state.endVertex;
  os << ", next:" << state.nextId;
  os << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os,
                         const PathStateMachine& states) {
  os << "PathStateMachine{";
  os << "current:" << states.currentId() << "," << std::endl;
  os << "states:" << std::endl;
  for (const auto& state : states.states()) {
    os << *(state.second) << std::endl;
  }
  os << "}" << std::endl;
  return os;
}

void PathStateMachine::update(float amount, VertexData* vertex) {
  PathStateParams params;
  params.amount = amount;
  StateMachine<PathState, PathStateParams>::update(params);
  *vertex = params.vertex;
}

PathState& PathStateMachine::addState(StateId id) {
  PathState* state = new PathState(id);
  base::addState(ofPtr<PathState>(state));
  return *state;
}

ofPtr<PathState>
PathStateChain::Entry::createState(const Entry& next) const {
  ofPtr<PathState> state(new PathState(id));
  state->setStart(vertex);
  state->setEnd(next.vertex);
  state->setNext(next.id);
  return state;
}

void PathStateMachine::addStates(std::vector<ofPtr<PathState> > states) {
  for (auto& state : states) {
    base::addState(state);
  }
}

PathStateChain PathStateChain::getReversed() const {
  PathStateChain reversed;
  reversed._states = _states;
  std::reverse(reversed._states.begin(),
               reversed._states.end());
  return reversed;
}

std::vector<ofPtr<PathState> >
PathStateChain::buildStates(bool loop) const {
  std::vector<ofPtr<PathState> > states;
  int count = _states.size();
  for (int i = 1; i < count; i++) {
    const Entry& prev = _states[i - 1];
    const Entry& cur = _states[i];
    states.push_back(prev.createState(cur));
  }
  if (loop) {
    states.push_back(_states.back().createState(_states.front()));
  }
  return states;
}

PathStateChain& PathStateChain::add(StateId id, VertexData vertex) {
  Entry entry;
  entry.id = id;
  entry.vertex = vertex;
  _states.push_back(entry);
  return *this;
}
