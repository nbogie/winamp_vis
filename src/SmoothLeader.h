#ifndef __SMOOTHLEADER_H__
#define __SMOOTHLEADER_H__

#include "NBVector.h"
#include "NBPalette.h"
#include "SmoothLeader.h"

class SmoothLeader {
   
public:

   SmoothLeader(const NBVector& startPos) ;
   void update() ;
   void draw() ;
   void SmoothLeader::setDest(const NBVector& givenDest);
   const NBVector& getPos () const ;
protected:

private:

   static const int MAX_X_VEL ;
   static const int MAX_Y_VEL ;
   static const int MAX_Z_VEL ;
   static const int WALK_STEP ;
   static const int WALK_RATE ;
   
   //instance variables
   NBVector pos ;
   NBVector dest ;
   //Color color;
   bool walking ;
   };
#endif