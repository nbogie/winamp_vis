// NBPalette.cpp: implementation of the NBPalette class.
//
//////////////////////////////////////////////////////////////////////

#include "NBPalette.h"
#include <iostream.h>  //just for debugging while developing.
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int NBPalette::PALETTE_SIZE = 256;
NBPalette::NBPalette()
{
   colors = new NBVector [ PALETTE_SIZE ] ;
   for (int i=0; i< PALETTE_SIZE; i++)
   {
      colors[i] = NBVector((PALETTE_SIZE-i)/(float)PALETTE_SIZE, i/(float)PALETTE_SIZE, 0.0f);
      //char* report = colors[i].toString();
      //cout << "creating color into array: " << report << endl ;
      //delete report;
   }
}

NBPalette::~NBPalette()
{
}
const NBVector& NBPalette::atMod(int index) const
{
   return colors[index%PALETTE_SIZE];
}
