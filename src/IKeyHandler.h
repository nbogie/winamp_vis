// Animal.h: interface for the Animal class.
//
//////////////////////////////////////////////////////////////////////

#ifndef NB_ANIMAL
#define NB_ANIMAL 1
class Animal  
{
public:
   Animal();
   virtual ~Animal();
   virtual void update () = 0 ;
   virtual void draw () = 0 ;
   virtual void toggleAnim() ;
   virtual void toggleActive() ;

   virtual void handleKey(unsigned char key, int x, int y) = 0;
   
protected:
   bool animate;
   bool visible;
private:
   
};

#endif
