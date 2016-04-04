/*
 * Gestion de la fenêtre de l'application et des variables associées
 * Legrand Sébastien pour Login:
 */
 
/* fichier entête */
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>


/* variables globales au fichier */
Display *display;	// le display de l'application
Window window;		// la fenêtre de l'application
Visual *visual;		// le visual de l'application
GC gc;			// le gc de l'application
int depth;		// profondeur de l'écran

/* création de la fenêtre principale de l'application */
void CreateMainWindow( int width, int height, char *name )
{
  Window root;
  unsigned long black;
  int screen;
  
  /* ouverture du display */
  display=XOpenDisplay( NULL );
  if( display == NULL )
  {
    puts("Impossible d'ouvrir le display !");
    exit(1);
  }
  
  /* initialisation des variables */
  screen=DefaultScreen( display );
  root=DefaultRootWindow( display );
  visual=DefaultVisual( display, screen );
  depth=DefaultDepth( display, screen );
  black=BlackPixel( display, screen );
  gc=DefaultGC( display, screen );


  /* creation de la fenêtre */
  window=XCreateSimpleWindow( display, root, 0, 0, width, height, 1, black, black );
  
  /* donne un nom à la fenêtre */
  XStoreName( display, window, name );
}

/* ferme la fenêtre de l'application */
void CloseMainWindow( void )
{
  XCloseDisplay( display );
}

/* retourne l'identificateur de la fenêtre */
Window GetAppWindow( void )
{
  return window;
}

/* retourne le display de l'application */
Display *GetAppDisplay( void )
{
  return display;
}

/* retourne le GC de l'application */
GC GetAppGC( void )
{
  return gc;
}

/* retourne la profondeur de l'écran */
int GetAppDepth( void )
{
  return depth;
}

/* retourne le visual de l'application */
Visual *GetAppVisual( void )
{
  return visual;
}
