#ifndef __ORBITER_H__
#define __ORBITER_H__

// Includes

#include "NBVector.h"
#include "NBPalette.h"

class Orbiter 
{
public:
      Orbiter ( const NBVector& givenPos, double gOrbit );
      void update ( const NBVector& leadPos, const double frameVal ) ;
      void scaleOrbitHeight ( const double scale ) ;
      void scaleOrbitHeightTemp ( const double scale ) ;
      void setXCoeff ( const double givenCoeff ) ;
      void setYCoeff ( const double givenCoeff );
      void draw() ;
      
protected:
   //static float whichOrbiter = 0;
   
   //instance variables
   NBVector pos ;
   NBVector oldPos ;
   double orbitHeight; //dist ORBITER orbits at.  Use double so that precision is
   //preserved if orbit is scaled down and back up again.
   double orbitHeightOriginal; //created, but never changed.

   double xCoeff;  //Coefficient of x=  a*Sin()
   double yCoeff;  //Coefficient of y=  b*Cos()
   double zCoeff;  //Coefficient of z=  ???
   
   float phase;      //phase with normal orbit
   //between 0 and 359
   double speedFraction; //fraction of speed of normal orbit rate
   NBVector color ;
   float alpha ;
private:
};

#endif
