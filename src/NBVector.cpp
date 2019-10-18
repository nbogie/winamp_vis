/*
#include <gl/glut.h>
#include <m*thisth.h>
#include <stdlib.h>
*/
#include "NBVector.h"
#include "NeillGLDefs.h"
#include <stdio.h>
NBVector::NBVector() {
   x = 0;
   y = 0;
   z = 0;
}

NBVector::NBVector(float _x, float _y, float _z) 
{
   x = _x; 
   y = _y; 
   z = _z;
}
NBVector::~NBVector() 
{
}

void NBVector::glColor() const
{
   glColor3f( x, y, z );
}

void NBVector::glColor(float a) const
{
   glColor4f( x, y, z, a );
}

void NBVector::glNormal() const
{
   glNormal3f( x, y, z );
}

void NBVector::glVertex() const
{
   glVertex3f ( x, y, z ) ;
}

NBVector NBVector::plus(const NBVector & b) const
{
   return NBVector( x + b.x, y + b.y, z + b.z );
}

bool NBVector::equals(const NBVector & b) 
{
   return x==b.x && y==b.y && z==b.z ;
}


NBVector & NBVector::increment(const NBVector & b)
{
   x += b.x;
   y += b.y;
   z += b.z;
   return *this;
}


NBVector NBVector::minus(const NBVector & b) const
{
   return NBVector( x - b.x, y - b.y, z - b.z );
}

NBVector & NBVector::decrement(const NBVector & b)
{
   x -= b.x;
   y -= b.y;
   z -= b.z;
   return *this;
}

NBVector NBVector::multiply(float s)
{
   return NBVector( x * s, y * s, z * s );
}

float NBVector::DotProd(const NBVector & b)
{
   return x * b.x + y * b.y + z * b.z;
}
NBVector NBVector::CrossProduct ( const NBVector& other )
{
   	NBVector prod ;
      prod.x = (*this).y * other.z - (*this).z * other.y ;
		prod.y = (*this).z * other.x - (*this).x * other.z ;
		prod.z = (*this).x * other.y - (*this).y * other.x ;
      return prod ;
}


float NBVector::Length2()
{
   return DotProd( *this );
}

float NBVector::Length()
{
   return (float)sqrt( Length2( ) );
}

float NBVector::Distance(const NBVector & b)
{
   return ((*this).minus(b)).Length( );
}

NBVector NBVector::Normalize()
{
   return (*this).multiply (1.0f / Length( ));
}
NBVector NBVector::random()
{
   return NBVector( RandFlt(-1, 1), RandFlt(-1, 1), RandFlt(-1, 1) );
}

NBVector NBVector::random( float least, float most )
{
   return NBVector( RandFlt(least, most), RandFlt(least, most), RandFlt(least, most) );
}

char* NBVector::toString() const 
{
   char* msg = new char[200];
   sprintf(msg, "vector [%f, %f, %f]", x, y, z);
   return msg;
}
void NBVector::operator=(const NBVector& other)
{
   x = other.x;
   y = other.y;
   z = other.z;
}


//static data
const NBVector NBVector::black = NBVector(0.0, 0.0, 0.0);
const NBVector NBVector::red= NBVector(1.0, 0.0, 0.0);
const NBVector NBVector::green = NBVector(0.0, 1.0, 0.0);
const NBVector NBVector::yellow = NBVector(1.0, 1.0, 0.0);
const NBVector NBVector::blue = NBVector(0.0, 0.0, 1.0);                             
const NBVector NBVector::magenta = NBVector(1.0, 0.0, 1.0);                             
const NBVector NBVector::cyan = NBVector(0.0, 1.0, 1.0);                             
const NBVector NBVector::white = NBVector(1.0, 1.0, 1.0);                             

