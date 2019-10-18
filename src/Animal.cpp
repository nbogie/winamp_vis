// Animal.cpp: implementation of the Animal class.
//
//////////////////////////////////////////////////////////////////////

#include "Animal.h"

Animal::Animal()
:animate(true), visible(true)
{
}

Animal::~Animal()
{   
}

void Animal::toggleAnim()
{
	animate = !animate ;
}

void Animal::toggleActive()
{
	if ( visible )
	{
		animate = false ;
		visible = false ;
	} 
	else
	{
		animate = true ;
		visible = true ;
	}
}

