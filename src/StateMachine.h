//
//  StateMachine.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef LineThing4_StateMachine_h
#define LineThing4_StateMachine_h

#include <map>
#include <memory>

typedef int StateId;

template<typename TState, typename UpdateParam>
class StateMachine {
public:
  void goTo(StateId id) { _currentId = id; }
  void update(UpdateParam& param) {
    auto currentState = _states.find(_currentId);
    if (currentState == _states.end())
      return;
    goTo(currentState->second->update(param));
  }
  void addState(ofPtr<TState> state) {
    _states.insert(std::make_pair(state->id, state));
  }
  ofPtr<TState> getState(StateId id) {
    return _states[id];
  }
  StateId currentId() const { return _currentId; }
  std::map<StateId, ofPtr<TState> >& states() { return _states; }
  const std::map<StateId, ofPtr<TState> >& states() const { return _states; }
private:
  std::map<StateId, ofPtr<TState> > _states;
  StateId _currentId;
};

#endif
