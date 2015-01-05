//
//  VertexData.cpp
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#include "VertexData.h"
#include <ofMain.h>

VertexData VertexData::getLerped(const VertexData& other,
                                 float amount) const {
  VertexData v(position.getInterpolated(other.position, amount),
               color.getLerped(other.color, amount));
  return v;
}

VertexData VertexData::getXFlipped() const {
  return VertexData(ofVec3f(ofGetWidth() - position.x,
                            position.y,
                            position.z),
                    color);
}

void VertexData::addToMesh(ofMesh *mesh) {
  mesh->addVertex(position);
  mesh->addColor(color);
}


std::ostream& operator<<(std::ostream& os,
                         const VertexData& vertex) {
  os << "VertexData{";
  os << "position:" << vertex.position;
  os << ", color:" << vertex.color;
  os << "}";
  return os;
}
