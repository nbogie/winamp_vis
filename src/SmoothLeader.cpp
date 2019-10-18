// Tiger.cpp: implementation of the Tiger class.
//
//////////////////////////////////////////////////////////////////////

#include <gl/glut.h>
#include <stdio.h>
#include "SmoothLeader.h"
#include "NeillGLDefs.h"

   const int SmoothLeader::MAX_X_VEL = 20;
   const int SmoothLeader::MAX_Y_VEL = 20;
   const int SmoothLeader::MAX_Z_VEL = 20;
   const int SmoothLeader::WALK_STEP = 50;
   const int SmoothLeader::WALK_RATE = 20;
      
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
   SmoothLeader::SmoothLeader( const NBVector& startPos ):
   pos ( startPos ),
   dest ( startPos ), walking ( true ) 
   {
      //color = Color.magenta ;
   }
   
   void SmoothLeader::update()
   {  
      if ( walking )
      {
         //if we're at our destination, choose a new one
         if ( pos.equals (dest) )//TODO: never equal - these're floats.
         { 
            dest.x += WALK_STEP * RandFlt ( -1, 1 ) ;
            dest.y += WALK_STEP * RandFlt ( -1, 1 ) ;
            dest.z += WALK_STEP * RandFlt ( -1, 1 ) ;
            //printf ( "chose new dest: %.2f, %.2f\n", dest.x, dest.y ) ;     
         }
      }
      //take a step toward the destination
      float xStep = (dest.x - pos.x) / WALK_RATE ;
      float yStep = (dest.y - pos.y) / WALK_RATE ;
      float zStep = (dest.z - pos.z) / WALK_RATE ;
      pos.x += xStep;
      pos.y += yStep;
      pos.z += zStep;
      
      //nudge us right onto dest if x&y steps are both tiny
      if ( (xStep < 0.1) && (yStep < 0.1) && (zStep < 0.1) ){

         pos = dest ;
      }
      
   }
   const NBVector& SmoothLeader::getPos() const 
   {
      return pos ;
   }
   void SmoothLeader::draw()
   {
      glColor4f ( 1.0, 0.0, 0.0, 0.4 ) ;
      glPushMatrix();
      glTranslatef ( pos.x, pos.y, pos.z ) ;
      //glutSolidCube ( 1.0 ) ;
      glPopMatrix();
   }
   
   
   void SmoothLeader::setDest(const NBVector& givenDest)
   {
      dest = givenDest ;
   }
