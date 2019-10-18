#ifndef NEILL_GL_DEFS
#define NEILL_GL_DEFS 1

typedef float vec3_t [ 3 ] ; 
#include <stdlib.h>
//#include <math.h>

inline float RandFlt(float min=0, float max=1)
{
   return min + (max - min) * rand () / ( float ) RAND_MAX;
}

inline int RandInt(int min, int max)
{
   return min + (max - min) * rand () / RAND_MAX ;
}

#endif
