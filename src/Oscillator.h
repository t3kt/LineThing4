//
//  Oscillator.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef __LineThing4__Oscillator__
#define __LineThing4__Oscillator__

#include "Common.h"
#include <utility>
#include <ofRange.h>

class Oscillator {
public:
  enum Mode {
    MODE_CONSTANT,
    MODE_RAMP,
    MODE_SINE
  };
  typedef float Value;
  typedef ofRange_<Value> ValuePair;
  
  Value getRaw(float t) const;
  Value getScaled(float t) const;
private:
  const ValuePair& getRawRange() const;
  
  Mode _mode;
  Value _constant;
  ValuePair _outRange;
  float _frequency;
};

#endif /* defined(__LineThing4__Oscillator__) */
