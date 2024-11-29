/*Ce fichier gère la création du plateau.*/

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

plateau initialiserPlateau(plateau monPlateau);
void majPlateau(piece maPiece, plateau *monPlateau);
void majApresChute(piece maPiece, plateau *monPlateau);
int ligneComplete(plateau monPlateau);
void supprimerLigne(plateau *monPlateau, int ligne);
void descendreLignes(plateau *monPlateau, int ligne);

#endif /* PLATEAU_H */
