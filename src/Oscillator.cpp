//
//  Oscillator.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "Oscillator.h"
#include <ofMain.h>
#include <math.h>

static const Oscillator::ValuePair zeroToOne(0, 1);
static const Oscillator::ValuePair negOneToOne(-1, 1);

const Oscillator::ValuePair& Oscillator::getRawRange() const {
  switch (_mode) {
    case MODE_SINE:
      return negOneToOne;
    case MODE_CONSTANT:
    case MODE_RAMP:
    default:
      return zeroToOne;
  }
}

Oscillator::Value Oscillator::getRaw(float t) const {
  switch (_mode) {
    case MODE_RAMP:
      return std::fmod(t, _frequency);
    case MODE_SINE:
      return std::sin(std::fmod(t, _frequency));
    case MODE_CONSTANT:
    default:
      return _constant;
  }
}
Oscillator::Value Oscillator::getScaled(float t) const {
  Value raw = getRaw(t);
  const auto& rawRange = getRawRange();
  return ofMap(raw, rawRange.min, rawRange.max,
               _outRange.min, _outRange.max);
}
