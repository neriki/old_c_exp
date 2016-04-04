/*
 * RAYCASTER.H - header pour le moteur de Ray Casting
 *
 * LEGRAND Sébastien pour Login
 */
 
/* directive de compilation */
#ifndef PONG_H
#define PONG_H

/* constantes booleenes */
#define TRUE	1
#define FALSE	0

/* dimension de l'écran */
#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

/* definition des couleurs */
/*#define COULEUR_DEBUT 1000
#define COULEUR_FIN   1884*/

#define COULEUR_DEBUT  16777100
#define COULEUR_FIN    16777200

/*#define COULEUR_DEBUT 1010
#define COULEUR_FIN   1030*/

/* definition de la constante PI */
#define PI		3.14159265359

#define NB_BALLE 30
/* nouveau type */
typedef unsigned char byte;

struct baballe{
	int x,y,ox,oy;
	int incrementx, incrementy;
	long couleur;
	} ;/*baballe*/

struct point{
	double x;
	double y;
	};

/*
 * PROTOTYPES
 */


void Pong();

void DessineBalle(int,int,long);

void bouge_baballe(struct baballe *);

void DrawLine(int, int, int, int, long);

long couleur_rgb(int, int, int);

void vonKochRec(struct point, struct point, int);

struct point rot(struct point, double, struct point);

#endif /* PONG_H */
