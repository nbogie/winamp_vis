//
// NBVector.h
// 3D NBVector & plane class

#ifndef __NBVector_h__
#define __NBVector_h__

// Includes

#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <string>

// NBVector

class NBVector {
public:
   float x, y, z;
   
   NBVector() ;  
   NBVector(float _x, float _y, float _z) ;
   virtual ~NBVector() ;  
   void operator= ( const NBVector& other );
   
   void glVertex() const;
   void glColor() const;
   void glColor(float a) const;
   void glNormal() const;
   bool equals(const NBVector & b) ;
   NBVector plus(const NBVector & b) const ;
   NBVector & increment(const NBVector & b);
   NBVector minus(const NBVector & b) const ;
   NBVector & decrement(const NBVector & b);
   NBVector multiply(float s);
   float DotProd(const NBVector & b);
   NBVector CrossProduct ( const NBVector& other ) ;
   float Length2();
   float Length();
   float Distance(const NBVector & b);
   NBVector Normalize();
   static NBVector random();
   static NBVector random( float least, float most );
   char* toString() const ;
   

static const NBVector black ;
static const NBVector red ;
static const NBVector green ;
static const NBVector yellow ;
static const NBVector blue ;
static const NBVector magenta ;
static const NBVector cyan ;
static const NBVector white ;
};

// Utility


#endif
