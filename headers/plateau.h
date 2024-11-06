/*Ce fichier gère le plateau.*/

#ifndef PLATEAU_H
#define PLATEAU_H

#include <MLV/MLV_all.h>
#include "../headers/piece.h"

typedef struct {
    int state[10][20];
    int x;
    int y;
    int largeur;
    int hauteur;
    MLV_Color couleur[10][20];
} plateau;

plateau majPlateau(piece maPiece, plateau monPlateau);
plateau initPlateau(plateau monPlateau);
int ligneComplete(plateau monPlateau);
plateau supprimerLigne(plateau monPlateau, int ligne);

#endif /* PLATEAU_H */