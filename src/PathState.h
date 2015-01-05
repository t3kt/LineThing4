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
#include <vector>
#include <iostream>

#include "StateMachine.h"
#include "VertexData.h"

struct PathStateParams {
  VertexData vertex;
  float amount;
};

class PathState {
public:
  PathState(StateId i) : id(i) {}

  StateId update(PathStateParams& params);
  
  PathState& setStart(VertexData v) {
    startVertex = v;
    return *this;
  }
  
  PathState& setEnd(VertexData v) {
    endVertex = v;
    return *this;
  }
  
  PathState& setNext(StateId i) {
    nextId = i;
    return *this;
  }
  const StateId id;
  VertexData startVertex;
  VertexData endVertex;
  StateId nextId;
private:
  float _i;
};

std::ostream& operator<<(std::ostream& os,
                         const PathState& state);

class PathStateChain {
public:
  PathStateChain& add(StateId id, VertexData v);
  std::vector<ofPtr<PathState> > buildStates(bool loop) const;
  
  PathStateChain getReversed() const;
private:
  struct Entry {
    StateId id;
    VertexData vertex;
    
    ofPtr<PathState> createState(const Entry& next) const;
  };
  std::vector<Entry> _states;
};

class PathStateMachine : public StateMachine<PathState, PathStateParams> {
private:
  typedef StateMachine<PathState, PathStateParams> base;
public:
  void update(float amount, VertexData* vertex);
  PathState& addState(StateId id);
  void addStates(std::vector<ofPtr<PathState> > states);
};


std::ostream& operator<<(std::ostream& os,
                         const PathStateMachine& states);

#endif /* defined(__LineThing4__PathState__) */
