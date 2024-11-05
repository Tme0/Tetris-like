/*Ce fichier gère le plateau.*/

#ifndef PLATEAU_H
#define PLATEAU_H

#include <MLV/MLV_all.h>
#include "../headers/piece.h"

typedef struct {
    int state[20][10];
    int x;
    int y;
    int largeur;
    int hauteur;
    MLV_Color couleur[20][10];
} plateau;

plateau majPlateau(piece maPiece, plateau monPlateau);
plateau initPlateau(plateau monPlateau);

#endif /* PLATEAU_H */