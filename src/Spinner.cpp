// Spinner.cpp: implementation of the Spinner class.
//
//////////////////////////////////////////////////////////////////////
//TODO: don't have spinner's orbiters moving.  have them translated at display time.  or at least, have the old points move when the front points do, so that you don't get a long straight line during a fast move.
#include "Spinner.h"
#include "SmoothLeader.h"
#include "Orbiter.h"
#include <gl/glut.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int Spinner::MAX_ORBITERS = 300 ;

const short Spinner::MAX_ORBIT_HEIGHT = 20 ;   

//app's constructor
Spinner::Spinner( const NBVector& startPos)
{
	frameNum = 0;
	gravityLead = new SmoothLeader ( startPos ) ;
	initOrbiters();
	setDest(NBVector ( startPos.x + 20, startPos.y + 20, startPos.z + 20) );
}

Spinner::~Spinner()
{
	for (int i=0; i<orbiters.size();  i++)
	{
		delete orbiters[i] ;
	}
}

void Spinner::update()
{
	if (!animate)
		return;
	gravityLead -> update();
	updateOrbiters ( gravityLead -> getPos() );
	frameNum++;
}

//update the list of orbiters
void Spinner::updateOrbiters(const NBVector& leadPos)
{
	
	for (int i=0; i < orbiters.size();  i++)
	{
		double f = frameNum / 10.0;// frameNum/ Math.PI;
		
		orbiters[i] -> update(leadPos, f);
	}
	
}

void Spinner::draw( )
{
	if (!visible)
		return ;
	//paint centre, then paint each orbiter
	gravityLead -> draw() ;
	for (int i=0; i < orbiters.size();  i++)
	{
		orbiters[i] -> draw();
	}
}


void Spinner::setMaxOrbitRadius(const int newHeight){
	//safeguard against bad input height
	int height = newHeight ;
	if (height > MAX_ORBIT_HEIGHT)
	{
		height = MAX_ORBIT_HEIGHT ;
	}
	double scale = height/MAX_ORBIT_HEIGHT;
	scaleOrbitRadius(scale);
}

void Spinner::scaleOrbitRadius(const double scale){
	//scale each orbiter's height
	
	for (int i=0; i<MAX_ORBITERS;  i++)
	{
		orbiters[i]->scaleOrbitHeight(scale);
	}
	
}
void Spinner::scaleOrbitRadiusTemp(const double scale){
	//scale each orbiter's height
	
	for (int i=0; i<MAX_ORBITERS;  i++)
	{
		orbiters[i]->scaleOrbitHeightTemp(scale);
	}
	
}

void Spinner::setCoeffs(const double givenXCoeff, const double givenYCoeff)
{
	
	for (int i=0; i<MAX_ORBITERS;  i++)
	{
		orbiters[i]->setXCoeff(givenXCoeff);
		orbiters[i]->setYCoeff(givenYCoeff);
	}
	
}

//method to set the destination of the spinner
void Spinner::setDest(const NBVector& givenDest ){
	gravityLead -> setDest(givenDest);
}

//initialise the list of orbiters (randomly)
void Spinner::initOrbiters()
{
	for (int i=0; i<MAX_ORBITERS;  i++)
	{
		double orbit = MAX_ORBIT_HEIGHT * RandFlt(0.2, 1);
		NBVector startPos (0,0,0);
		//orbiter with rand position, initial vel (0-9) (accel 1-10)
		orbiters.push_back ( new Orbiter( startPos, orbit) ) ;
	}
}


const NBVector& Spinner::getCentre() const
{
	return gravityLead->getPos () ;
}

void Spinner::handleKey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p': animate=!animate ; break;         //p for sPinner stops animation
	case 'P': visible=!visible; break;         //P for sPinner hides spinner
	}    
}

