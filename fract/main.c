/* 
 * Moteur de rendu en Raycasting - fichier principal
 *
 * LEGRAND Sébastien - Login Avril 2000
 */
 
/* fichier entete */
#include <X11/Xlib.h> 
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "pong.h"
#include "window.h"

/* variables globales */
extern byte FishbowlEffect;
extern int PlaneCenterY;
extern int param;

/* fonction principale */
int main(int argc,char *argv[])
{
  int i,n;
  struct point PointA, PointB;
  Window window;
  Display *display;
  Visual *visual;
  XEvent event;
  XImage *ximage;
  GC gc;
  int process_fils;
  int depth,done;
  long event_mask;
  char buffer;

  PointA.x=450;
  PointA.y=250;
  PointB.x=150;
  PointB.y=350;
  
  /* creation de la fenetre de l'application */
  CreateMainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  
  /* recuperation des variables */
  window=GetAppWindow();
  display=GetAppDisplay();
  
  
  /* affichage de la fenetre */
  XMapWindow(display,window);
  
  
		while(TRUE){
			for(n=18;n<22;n++){
				DragonFractRec(PointA, PointB, n, TRUE);
				DragonFractRec(PointA, PointB, n, FALSE);
			}
			
		}

  return 0;
}
