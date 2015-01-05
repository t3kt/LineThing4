//
//  LineThing.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef __LineThing4__LineThing__
#define __LineThing4__LineThing__

#include "PathState.h"
#include "TurntableCam.h"
#include "Common.h"

class LineThing {
public:
  LineThing();
  void setup();
  void update();
  void draw();
private:
  PathStateMachine _pathStates1;
  PathStateMachine _pathStates2;
  ofMesh _pointsMesh;
};

#endif /* defined(__LineThing4__LineThing__) */
