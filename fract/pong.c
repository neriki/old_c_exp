/*
 * fichier entete
 */
#include <stdio.h>
#include <X11/Xlib.h>
#include <math.h>
#include "window.h"
#include "pong.h"


/*
 * variables globales 
 */

/* variable concernant la fenetre de dessin */
Display *display;
Window window;
GC gc;
long couleurdiff;

/* trace une ligne */
void DrawLine(int xd,int yd,int xf,int yf,long color)
{
  XSetForeground(display,gc,color);
  XDrawLine(display,window,gc,xd,yd,xf,yf);
}

long couleur_rgb(int r,int g,int b)
{
	long couleur;
	couleur=b+(256*g)+(65536*r);
	/*printf("r=%d g=%d b=%d couleur=%x\n",r,g,b,couleur);*/
	return couleur;
}

struct point rot(struct point P, double theta, struct point Centre)
{
	struct point NewP;
	struct point Temp;

	Temp.x=P.x-Centre.x;
	Temp.y=P.y-Centre.y;
	
	NewP.x=Temp.x * cos(theta) - Temp.y * sin(theta);
	NewP.y=Temp.x * sin(theta) + Temp.y * cos(theta);

	NewP.x=NewP.x+Centre.x;
	NewP.y=NewP.y+Centre.y;

	return NewP;
}

void vonKochRec(struct point A, struct point B, int n)
{
long c;
struct point C,D,E;
double angle;

if(n==0)DrawLine(A.x,A.y,B.x,B.y,couleur_rgb(255,255,255));
else
	{
	C.x=A.x+((B.x-A.x)/3);
	C.y=A.y+((B.y-A.y)/3);
	
	D.x=C.x+((B.x-A.x)/3);
	D.y=C.y+((B.y-A.y)/3);

	angle=(2*PI)/3;

	E=rot(B, angle, D);
	

	vonKochRec(A, C, n-1);
	vonKochRec(C, E, n-1);
	vonKochRec(E, D, n-1);
	vonKochRec(D, B, n-1);

	}

}


void DragonFractRec(struct point A, struct point B, int n, int action)
{
	struct point C;
	struct point centre;
	long couleur;
	if(action)couleur=(++couleurdiff);
	else couleur=0;

	if(n==0)DrawLine(A.x,A.y,B.x,B.y,couleur);
	else
	{
	centre.x=(A.x+B.x)/2;
	centre.y=(A.y+B.y)/2;
	C=rot(B,PI/2,centre);
	DragonFractRec(A,C,n-1,action);
	DragonFractRec(B,C,n-1,action);

	}
}

