/*
 * Gestion de la fen�tre de l'application et des variables associ�es
 * Legrand S�bastien pour Login:
 */
 
/* fichier ent�te */
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>


/* variables globales au fichier */
Display *display;	// le display de l'application
Window window;		// la fen�tre de l'application
Visual *visual;		// le visual de l'application
GC gc;			// le gc de l'application
int depth;		// profondeur de l'�cran

/* cr�ation de la fen�tre principale de l'application */
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


  /* creation de la fen�tre */
  window=XCreateSimpleWindow( display, root, 0, 0, width, height, 1, black, black );
  
  /* donne un nom � la fen�tre */
  XStoreName( display, window, name );
}

/* ferme la fen�tre de l'application */
void CloseMainWindow( void )
{
  XCloseDisplay( display );
}

/* retourne l'identificateur de la fen�tre */
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

/* retourne la profondeur de l'�cran */
int GetAppDepth( void )
{
  return depth;
}

/* retourne le visual de l'application */
Visual *GetAppVisual( void )
{
  return visual;
}
