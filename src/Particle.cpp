#include <gl/glut.h>
#include "Particle.h"
#include "NeillGLDefs.h"
#include <iostream.h>
Particle::Particle(NBPalette* pal)
{
   palette = pal; //don't take ownership
   Create(); 
}
Particle::Particle()
{
   Create(); 
}

Particle::~Particle()
{
}

void Particle::Create()
{
   
   GenerateMass( mass );
   GenerateColor( color );
   pos.x = 0 ;
   pos.y = 0 ;
   pos.z = 0 ;
   GenerateVelocity( vel );  
   age = 0;
   oldpos = pos;
}
//like create, but particle doesn't get age reset.
void Particle::Respot()
{
   GenerateMass( mass );
   GenerateColor( color );
   GenerateVertex( pos );
   GenerateVelocity( vel );  
   oldpos = pos;
}

void Particle::RandomiseAge ()
{
   age = (float) RandInt ( 0, 200 ) ;
}
//update with gravity

void Particle::update()
{
   oldpos = pos ;
   pos.increment( vel) ;
   age++ ;
   vel.increment(NBVector(0.0f, -0.02f, 0.0));
   
   //if out of bounds, regenerate.
   //if ( pos.z < 10 || 
   //     pos.z > 10 ||
   //     fabs( pos.x / pos.z ) > 5 ||
   //     fabs( pos.y / pos.z ) > 10 )
   
   if (age>100)
   {
      Create();     
   }
}


/*
//update with a random walk
void Particle::update()
{
oldpos = pos ;
pos.increment( vel) ;
age++ ;
GenerateVelocity(vel);
//no gravity
//vel.increment(NBVector(0.0f, -0.02f, 0.0));
}*/


void Particle::Render()
{
   glBegin( GL_LINES );
   
   const NBVector& c = palette->atMod(age/2);
   c.glColor( );
   
   oldpos.glVertex();
   pos.glVertex( );
   glEnd();
   
   
   
}

void Particle::GenerateColor(NBVector & color)
{
/*for (int i=0; i< 100; i++)
{
color = NBVector( RandFlt(), RandFlt(), RandFlt() );
if (color.Length() > 1.0f)
break;
}*/
   color = NBVector (1.0f, 0.1f, 0.3f) ;
}

void Particle::GenerateVertex(NBVector & vertex)
{
   vertex = NBVector(
      RandFlt( 0.0f, 1.0f ), 
      RandFlt( 0.0f, 1.0f ), 
      RandFlt( 0.0f, 1.0f ) );
}

void Particle::GenerateVelocity(NBVector & vertex)
{
   vertex = NBVector(
      RandFlt( -1.0f, 1.0f ), 
      RandFlt( -1.0f, 1.0f ), 
      RandFlt( -1.0f, 1.0f ) ).Normalize();
   vertex.multiply ( RandFlt ( -2.0, 2.0 ) ) ;
}

void Particle::GenerateMass(float & mass)
{
   mass = 1.0;
}
void Particle::incVel(const NBVector& inc)
{
   vel.increment(inc);
}
