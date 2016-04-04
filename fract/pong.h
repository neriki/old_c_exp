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
#define SCREEN_WIDTH	750
#define SCREEN_HEIGHT	500

/* definition du nombre de cellules */
#define NB_CELL_X	16
#define NB_CELL_Y	16

/* definition de la taille d'une cellule */
#define CELL_SIZE	64

/* definition de la vision du joueur */
#define PLAYER_FOV	60

/* maximum des tangentes */
#define MAX_TAN		1921

/* definition de la constante PI */
#define PI		3.14159265359

/* definition des angles dans la table */
#define ANGLE_0		0
#define ANGLE_30	160
#define ANGLE_45	240
#define ANGLE_60	320
#define ANGLE_90	480
#define ANGLE_120	640
#define ANGLE_180	960
#define ANGLE_270	1440
#define ANGLE_360	1920

/* definition des couleurs */
#define WALL_COLOR	0x00aaaaaa
#define SKY_COLOR	0x00000000
#define GROUND_COLOR	0x00808080

/* definition des constantes du plan de vision */
#define PLANE_CENTER_Y	SCREEN_HEIGHT/2

#define NB_BALLE 15
/* nouveau type */
typedef unsigned char byte;

struct point{
	double x;
	double y;
	};

/*
 * PROTOTYPES
 */

void DrawLine(int, int, int, int, long);

long couleur_rgb(int, int, int);

void vonKochRec(struct point, struct point, int);

struct point rot(struct point, double, struct point);

void DragonFractRec(struct point, struct point, int, int);

#endif /* PONG_H */
