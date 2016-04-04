/*
 * fichier ent�te de WINDOW.C
 * Legrand S�bastien pour Login:
 */

#ifndef _H_WINDOW
#define _H_WINDOW

/* 
 * prototypes des fonctions
 */

/* cr�ation de la fen�tre principale de l'application */
void CreateMainWindow( int width, int height, char *name );

/* ferme la fen�tre de l'application */
void CloseMainWindow( void );

/* retourne l'identificateur de la fen�tre */
Window GetAppWindow( void );

/* retourne le display de l'application */
Display *GetAppDisplay( void );

/* retourne le GC de l'application */
GC GetAppGC( void );

/* retourne la profondeur de l'�cran */
int GetAppDepth( void );

/* retourne le visual de l'application */
Visual *GetAppVisual( void );

#endif /* WINDOW.H */
