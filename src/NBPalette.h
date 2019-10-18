// NBPalette.h: interface for the NBPalette class.
//
//////////////////////////////////////////////////////////////////////

#ifndef NB_PALETTE
#define NB_PALETTE 1

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NBVector.h"
class NBPalette  
{
public:
	NBPalette();
	virtual ~NBPalette();
   NBVector* colors;
   static const int PALETTE_SIZE;
   const NBVector& atMod(int index) const;
};

#endif
