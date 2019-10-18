// Spinner.h: interface for the Spinner class.
//
//////////////////////////////////////////////////////////////////////

#ifndef NBSpinner
#define NBSpinner 1

#include "Animal.h"
#include "NeillGLDefs.h"
#include "SmoothLeader.h"
#include "Orbiter.h"
#include <vector>

using namespace std;
class Spinner : public Animal
{

public:
   Spinner ( const NBVector& startPos ) ;
   virtual ~Spinner();
   virtual void update ();
   virtual void draw () ;
   
   void updateOrbiters(const NBVector& leadPos ) ;
   void setMaxOrbitRadius(const int newHeight) ;
   void scaleOrbitRadius(const double scale) ;
   void scaleOrbitRadiusTemp(const double scale) ;
   void setCoeffs(const double givenXCoeff, const double givenYCoeff) ;
   void setDest ( const NBVector& givenDest ) ;
   void initOrbiters() ;
   void setupParticles() ;
   void handleKey(unsigned char key, int x, int y) ;
   const NBVector& getCentre() const;

   
protected:
   vec3_t _pos ; 
   static const int particleCount ;
   vector<Orbiter*> orbiters ;
   SmoothLeader* gravityLead;    //smoothLeader which random walks
                                 //and is chased by orbiters.
   
   static const int MAX_ORBITERS;
   static const short MAX_ORBIT_HEIGHT;    
   long frameNum;   

   NBPalette palette ;
   
private:
};

#endif 
