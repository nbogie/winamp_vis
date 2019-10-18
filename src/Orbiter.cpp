#include <gl/glut.h>
#include <float.h> //ms-specific (for _copysign)
#include "Orbiter.h"
#include "NeillGLDefs.h"

//Orbiter constructor (x, y, xv, yv)
Orbiter::Orbiter ( const NBVector& givenPos, double gOrbit )
: color ( 1.0, 0.0, 0.0 ), 
alpha ( 0.8 ) 
{
   pos = givenPos;
   
   orbitHeight = gOrbit;
   orbitHeightOriginal = orbitHeight;
   
   phase = RandFlt(0, 359) ;
   speedFraction =  RandFlt(0.0, 1.0);
   
   xCoeff = 1.0;
   yCoeff = 1.0;
   zCoeff = 1.0;
   
   //colour (WAS) related to how fast the pixel is orbiting
   //todo: also relate colour to orbit height
   //color.x = speedFraction ;
   color.x = speedFraction;
   color.y = 0; //(((int)pos.x)%256)/256.0 ;
   color.z = 0; //(((int)orbitHeight) %256 ) /256.0;
   alpha = __min(speedFraction, 0.8);
}     

void Orbiter::update ( const NBVector& leadPos, const double frameVal )
{
   //todo: if speed of orbit detected as 0, set it to a min 1
   //store old pos
   oldPos = pos;
   
   double frameValAdjusted = frameVal ;
   //offset rotation according to individual phase
   frameValAdjusted = frameVal + phase;
   //offset rotation according to individual speed
   frameValAdjusted = frameVal * speedFraction;
   
   //_copysign( __min ( abs(tan(frameValAdjusted)), 0.3), tan(frameValAdjusted))
   //compute new location of orbiter
   pos.x = leadPos.x + orbitHeight * xCoeff * sin(frameValAdjusted) ;
   pos.y = leadPos.y + orbitHeight * yCoeff * cos(frameValAdjusted ) ;
   pos.z = leadPos.z + orbitHeight * zCoeff * tanh(frameValAdjusted ) ;
}

void Orbiter::scaleOrbitHeight ( const double scale ) 
{
   orbitHeight *= scale;
   if (orbitHeight==0){
      orbitHeight = 1;
   }
}

void Orbiter::scaleOrbitHeightTemp ( const double scale ) 
{
   orbitHeight = orbitHeightOriginal * scale;
   if (orbitHeight==0){
      orbitHeight = 1;
   }
}

void Orbiter::setXCoeff ( const double givenCoeff ) 
{
   xCoeff = givenCoeff;
}

void Orbiter::setYCoeff ( const double givenCoeff )
{
   yCoeff = givenCoeff;
}

void Orbiter::draw()
{
   color.glColor ( alpha ) ;
   glBegin ( GL_LINES ) ;
   oldPos.glVertex();
   pos.glVertex();
   glEnd () ;
}
