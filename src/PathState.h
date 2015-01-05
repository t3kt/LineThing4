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

class PathStateChain {
public:
  PathStateChain& start(StateId id,
                        VertexData v1,
                        VertexData v2);
  PathStateChain& add(StateId id, VertexData v);
  PathStateChain& loop();
  std::vector<ofPtr<PathState> >& states() { return _states; }
private:
  std::vector<ofPtr<PathState> > _states;
};

class PathStateMachine : public StateMachine<PathState, PathStateParams> {
public:
  void update(float amount, VertexData* vertex);
  PathState& addState(StateId id);
  void addStates(PathStateChain& chain);
};

#endif /* defined(__LineThing4__PathState__) */
