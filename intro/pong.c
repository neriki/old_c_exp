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
 

/* trace une ligne */
void DrawLine(int xd,int yd,int xf,int yf,long color)
{
  XSetForeground(display,gc,color);
  XDrawLine(display,window,gc,xd,yd,xf,yf);
}

void DrawString(int x, int y, long color, char *texte, int lg)
{
  XSetForeground(display,gc,color);
  XDrawString(display,window,gc,x,y,texte,lg);
}

long couleur_rgb(int r,int g,int b)
{
	long couleur;
	couleur=b+(256*g)+(65536*r);
	/*printf("r=%d g=%d b=%d couleur=%x\n",r,g,b,couleur);*/
	return couleur;
}

void DessineBalle(int x,int y,long couleur)
{
	int i;
	/*version pleine carre*/
/*	for(i=0;i<10;i++)
		DrawLine(x+i,y,x+i,y+10,couleur);*/
	
	/*ET*/
	for(i=0;i<10;i++)
		DrawLine(x+i,y,x+i,y+10,0);
	DrawLine(x+5,y,x+10,y+5,couleur);
	DrawLine(x+10,y+5,x+5,y+10,couleur);
	DrawLine(x+5,y+10,x,y+5,couleur);
	DrawLine(x,y+5,x+5,y,couleur);
	
	
	DrawLine(x-1,y-1,x+11,y-1,0);
	DrawLine(x-1,y-1,x-1,y+11,0);
	DrawLine(x+11,y-1,x+11,y+11,0);
	DrawLine(x-1,y+11,x+11,y+11,0);
}

void Pong()
{
struct point PointA, PointB;
long c;
struct baballe bleue[NB_BALLE], jaune[NB_BALLE], blanc[NB_BALLE], planc[NB_BALLE];
int i,j,k;
long cpt;
int incrementcpt;
char txt1[]="Square is Beautifull!\0";
char txt2[]="A small Intro for Linux by Neriki.\0";
int txtx,txty;
txtx=SCREEN_WIDTH/2;
txty=SCREEN_HEIGHT/2-5;
c=couleur_rgb(255,255,255);
XSetForeground(display,gc,c);
/*XSetBackground(display,gc,0);*/
for(i=0;i<NB_BALLE;i++){
	bleue[i].y=i*20;
	bleue[i].x=i*20;
	bleue[i].incrementx=bleue[i].incrementy=TRUE;
	bleue[i].couleur=c;

	jaune[i].x=i*20;
	jaune[i].y=i*20;
	jaune[i].incrementx=FALSE;
	jaune[i].incrementy=TRUE;
	jaune[i].couleur=c;

	blanc[i].x=i*20;
	blanc[i].y=i*20;
	blanc[i].incrementx=TRUE;
	blanc[i].incrementy=FALSE;
	blanc[i].couleur=c;

	planc[i].x=i*20;
	planc[i].y=i*20;
	planc[i].incrementx=FALSE;
	planc[i].incrementy=FALSE;
	planc[i].couleur=c;
}


cpt=COULEUR_DEBUT+1;
incrementcpt=TRUE;
while(TRUE){
	for(i=0;i<NB_BALLE;i++){

		planc[i].couleur=c;/*couleur_rgb(c,c,c);*/
		blanc[i].couleur=c;/*couleur_rgb(c,c,c);*/
		jaune[i].couleur=c;/*couleur_rgb(c,c,c);*/
		bleue[i].couleur=c;/*couleur_rgb(c,c,c);*/

		bouge_baballe(&bleue[i]);
		bouge_baballe(&jaune[i]);
		bouge_baballe(&blanc[i]);
		bouge_baballe(&planc[i]);
	}
	DrawString(txtx,txty,couleur_rgb(255,255,255),txt1,21);
	DrawString(txtx-40,txty+20,couleur_rgb(255,255,255),txt2,34);

	PointA.x=50;
	PointA.y=450;
	PointB.x=150;
	PointB.y=50;
	vonKochRec(PointA, PointB, 4);

	PointA.x=350;
	PointA.y=450;
	PointB.x=150;
	PointB.y=50;
	vonKochRec(PointA, PointB, 4);

	PointA.x=350;
	PointA.y=450;
	PointB.x=50;
	PointB.y=450;
	vonKochRec(PointA, PointB, 4);
	}
}

void bouge_baballe(struct baballe *balle)
{
	int i,j,k;
	balle->ox=balle->x;
	balle->oy=balle->y;
	if(balle->incrementx)balle->x++;
	else balle->x--;
	if(balle->incrementy)balle->y++;
	else balle->y--;
	if(balle->x>(SCREEN_WIDTH-10))balle->incrementx=FALSE;
	if(balle->x<1)balle->incrementx=TRUE;
	if(balle->y>(SCREEN_HEIGHT-10))balle->incrementy=FALSE;
	if(balle->y<1)balle->incrementy=TRUE;
	DessineBalle(balle->x,balle->y,balle->couleur);
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


