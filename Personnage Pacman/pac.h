#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "libTableauNoir.h"

typedef struct {double x; double y;} coord_t;

typedef struct {coord_t p; coord_t v;} mobile_t;
typedef struct {mobile_t pacman; }pac_t;

typedef struct { double a; double b; } score;

typedef struct {pac_t modele; int fini; }etat_t;

typedef struct {int numero; coord_t pbille;} bonbon_t;
typedef struct {bonbon_t bonbon[67]; int nb;} paquet_t;
//void terrain();
void afficher_pacman();
pac_t initiale();
etat_t maj ( etat_t etat, EtatSourisClavier esc, double dt);
int fini(etat_t);
void effacer_pacman(etat_t pacman);
void manger(paquet_t (*paquet));
/*void terrain();
void t1(coord_t x1, coord_t x2);
void t2(coord_t x1, coord_t x2);
void t3(coord_t x1, coord_t x2);
*/
