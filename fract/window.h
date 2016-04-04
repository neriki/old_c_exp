/*
 * fichier entête de WINDOW.C
 * Legrand Sébastien pour Login:
 */

#ifndef _H_WINDOW
#define _H_WINDOW

/* 
 * prototypes des fonctions
 */

/* création de la fenêtre principale de l'application */
void CreateMainWindow( int width, int height, char *name );

/* ferme la fenêtre de l'application */
void CloseMainWindow( void );

/* retourne l'identificateur de la fenêtre */
Window GetAppWindow( void );

/* retourne le display de l'application */
Display *GetAppDisplay( void );

/* retourne le GC de l'application */
GC GetAppGC( void );

/* retourne la profondeur de l'écran */
int GetAppDepth( void );

/* retourne le visual de l'application */
Visual *GetAppVisual( void );

#endif /* WINDOW.H */
