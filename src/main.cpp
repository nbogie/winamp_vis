#include "vis.h" 
#include "Spinner.h" 
#include "TextBoy.h" 

// initial window size
//DO NOT DELETE THIS. if you want you can change it
int width = 512 , height = 300 ; 
Spinner* spinner; 
TextBoy* textboy; 
int* spectrumDataPeaks = new int[512];
int* spectrumDataPeakAge = new int[512];

int maxPeak = 0;
char* myTitle;
//Use this function to 'write' your information in the configuration dialog box
char* putConfigInfo(void)
{
	return "Neill's second." ;
}

//Use this function to 'write' your information in the windows title bar
char* putTitleInfo(void)
{
	//init once only
	if (myTitle==NULL)
	{
		myTitle = new char[50];
	}
	sprintf(myTitle, "Neill's 2nd plug-in peak: %d.", maxPeak);
	return  myTitle;
}

char* putVisName(void)
{
	return "Neill's  Second Winamp Vis!";
}
//this is the resize function
//used when the window is resized!
// REMEMBER TO UPDATE THE variables width and height here!!!

void resizeGL(GLsizei w, GLsizei h)	
{
	//this makes sure that the rest of the application knows that our window has changed size
	width = w ;
	height = h ;

	//protects from divide by zero
	if (h==0)								
	{
		h = 1;						
	}

	//viewport covers the whole window
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);					
	glLoadIdentity();							

	//orthographic viewing equal to the window of our program
	//means that the origin is at the lower left corner of the window
	//and that there is a 1 to 1 mapping between our (world) coordinates and the pixels on the screen
	//eg: to make a sphere 100 pixels wide you would write
	//		gluSphere(gluNewQuadric(),  100  ,20,20) ;
	//
	//the depth is 200 'pixels' wide
	//from -100 to 100
    glOrtho(0.0,w, 0.0, h, -100.0,100.0) ;

	glMatrixMode(GL_MODELVIEW);						
	glLoadIdentity();						
}



void neillObjInit()
{
   spinner = new Spinner(NBVector(width/2, height/2, 0));
   textboy = new TextBoy();
   
}

//opengl's initialisation function
int initGL(GLvoid)							
{
	//set opengl to smooth shade objects
	glShadeModel(GL_SMOOTH);						

	//background color is black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					

	//enable opengl's depth testing facilities
	glEnable(GL_DEPTH_TEST);					
 
	neillObjInit();
	return TRUE ;
}


//This the render function
//Changing this function results in different visualizations!!!
int render(struct winampVisModule *this_mod)
{
	//clear the scrren and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			
	//make opengl to draw polygons instead of points
	glPolygonMode(GL_FRONT,GL_FILL) ;
	
	//left channel, use random low band's strength to scale
	int amp  = this_mod->spectrumData[0][10];
	if (amp > maxPeak)
	{
		maxPeak = amp;
	}

    spinner->scaleOrbitRadiusTemp((4* amp/255.0) + 0.5);

    spinner->update();
    spinner->draw();

	for (int p = 1;  p < 512; p++)
	{
		int age = spectrumDataPeakAge[p];
		int peak = spectrumDataPeaks[p];
		int curr = this_mod->spectrumData[0][p];
		
		if (curr>peak)
		{
			spectrumDataPeaks[p] = curr;
			spectrumDataPeakAge[p] = 0;
		}
		else
		{   //decay the peak
			spectrumDataPeaks[p] -= age;
			if (spectrumDataPeaks[p] < 0 )
			{
				spectrumDataPeaks[p] = 0;
			}
		}
		spectrumDataPeakAge[p]++;

	}


	sprintf(myTitle, "Neill's 2nd plug-in peak: %d.", maxPeak);
	textboy->printString(myTitle);
	textboy->update();
    textboy->draw();
	//save the modelview matrix
    glPushMatrix() ;


	//start a points based opengl object
	//color the line orange
    glColor3f(1.0,0.0,0.0) ;

	//at each interval, draw a line from base to frequencies value.
	glBegin(GL_LINES) ;
	for (int x = 1;  x < 512; x++)
	{
		glVertex2f((float)x, 0.0) ;
		glVertex2f((float)x, this_mod->spectrumData[0][x]) ;
	}
    glEnd() ;


	glColor3f(1.0,1.0,1.0) ;
	//at each interval, draw a line from base to frequencies value.
	glBegin(GL_POINTS) ;
	for (int pk= 1;  pk < 512; pk++)
	{
		glVertex2f((float)pk, spectrumDataPeaks[pk]) ;
	}
    glEnd() ;

	//restore the ransformation matrix
	glPopMatrix() ;

	//swap the buffers to draw the scene on the monitor
	SwapBuffers(memDC);
	
	return 0;
}
