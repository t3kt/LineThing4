//
//  VertexData.h
//  LineThing4
//
//  Created by tekt on 1/4/15.
//
//

#ifndef __LineThing4__VertexData__
#define __LineThing4__VertexData__

#include <ofTypes.h>
#include <iostream>

class ofMesh;

struct VertexData {
  ofVec3f position;
  ofColor color;
  
  VertexData() { }
  VertexData(ofVec3f pos, ofColor col)
  : position(pos), color(col) { }
  
  VertexData getLerped(const VertexData& other,
                       float amount) const;
  VertexData getXFlipped() const;
  
  void addToMesh(ofMesh* mesh);
};

std::ostream& operator<<(std::ostream& os,
                         const VertexData& vertex);

#endif /* defined(__LineThing4__VertexData__) */
