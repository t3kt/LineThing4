//
//  Common.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "Common.h"
#include <ofMath.h>

ofVec3f lerp(const ofVec3f& start, const ofVec3f& stop, float amt) {
  return start + (stop-start) * amt;
}
