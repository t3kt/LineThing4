//
//  Common.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef __LineThing4__Common__
#define __LineThing4__Common__

#include <ofTypes.h>

template<typename T>
ofVec3f lerp(const T& start, const T& stop, float amt) {
  return start + (stop-start) * amt;
}

#endif /* defined(__LineThing4__Common__) */
