#ifndef __PARTICLE_H__
#define __PARTICLE_H__

// Includes

#include "NBVector.h"
#include "NBPalette.h"

class Particle : public NBVector {
public: 
   Particle(NBPalette* pal);
   Particle();
   
   virtual ~Particle();
   virtual void Create();
   virtual void Render();
   virtual void update();
   virtual void incVel(const NBVector& inc);
   void RandomiseAge () ;
   void Respot();

   static void GenerateMass(float & mass);
   static void GenerateColor(NBVector & color);
   static void GenerateVertex(NBVector & vertex);
   static void GenerateVelocity(NBVector & vertex);
protected:
   NBVector pos;
   NBVector oldpos;
   NBVector vel;
   NBVector color;
   float mass;
   float age;
   NBPalette* palette ;
};



#endif

