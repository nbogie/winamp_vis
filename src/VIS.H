// Original Project (No OpenGL Support)
// Winamp test visualization library v1.0
// Copyright (C) 1997-1998, Justin Frankel/Nullsoft
// Feel free to base any plugins on this "framework"...

// OpenGL Support, Tutorial, and Code
// Copyright (C) 2001, Fotis Hadginikos/The Developers Gallery
// Feel free to base any pluggins on this code
// It would be nice though if you refer to the Developers Gallery
// www.dev-gallery.com , when doing so...


//needed include files
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <stdio.h>


//this is the definition of winamp's structure. All information from
//winamp is arriving in the form of this structure

typedef struct winampVisModule {
  char *description; // description of module
  HWND hwndParent;   // parent window (filled in by calling app)
  HINSTANCE hDllInstance; // instance handle to this DLL (filled in by calling app)
  int sRate;		 // sample rate (filled in by calling app)
  int nCh;			 // number of channels (filled in...)
  int latencyMs;     // latency from call of RenderFrame to actual drawing
                     // (calling app looks at this value when getting data)
  int delayMs;       // delay between calls in ms

  // the data is filled in according to the respective Nch entry
  int spectrumNch;
  int waveformNch;
  unsigned char spectrumData[2][576];
  unsigned char waveformData[2][576];

  void (*Config)(struct winampVisModule *this_mod);  // configuration dialog
  int (*Init)(struct winampVisModule *this_mod);     // 0 on success, creates window, etc
  int (*Render)(struct winampVisModule *this_mod);   // returns 0 if successful, 1 if vis should end
  void (*Quit)(struct winampVisModule *this_mod);    // call when done

  void *userData; // user data, optional
} winampVisModule;

typedef struct {
  int version;       // VID_HDRVER
  char *description; // description of library
  winampVisModule* (*getModule)(int); 
} winampVisHeader;

// exported symbols
typedef winampVisHeader* (*winampVisGetHeaderType)();

//function definitions
void config_read(struct winampVisModule *this_mod) ;
void config_getinifn(struct winampVisModule *this_mod, char *ini_file) ;
void config_write(struct winampVisModule *this_mod) ;
GLvoid shutDownGL(struct winampVisModule *this_mod, HGLRC hRC) ;

//YOU MUST IMPLEMENT THE FOLLOWING FUNCTION FOR THE PLUGGIN TO WORK
GLvoid resizeGL(GLsizei w, GLsizei h) ;
int initGL(GLvoid) ;
int render(struct winampVisModule *this_mod) ;

//USE (IMPLEMENT) THESE THREE FUNCTIONS TO INSERT YOUR INFORMATION IN THE PLUGGIN
char* putConfigInfo(void) ;
char* putTitleInfo(void) ;
char* putVisName(void) ;


//YOU MUST DEFINE AND USE THE FOLLOWING THREE VARIABLES FOR THE PLUGGIN TO WORK
extern int width, height ;
extern HDC memDC;

// version of current module (0x101 == 1.01)
#define VIS_HDRVER 0x101

