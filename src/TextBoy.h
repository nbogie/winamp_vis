// TextBoy.h: interface for the TextBoy class.
//
//////////////////////////////////////////////////////////////////////

#ifndef NBTextBoy
#define NBTextBoy 1

#include "Animal.h"
#include "NeillGLDefs.h"
#include <vector>

using namespace std;

class TextBoy : public Animal
{


public:
   TextBoy () ;
   virtual ~TextBoy();
   virtual void update ();
   virtual void draw () ;
   void makeRasterFont(void);
   void printString(char *s);

void handleKey(unsigned char key, int x, int y) ;
   
protected:
   vec3_t _pos ; 
   long frameNum;   
   
private:
};

#endif 
