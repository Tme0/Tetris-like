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
    int taille;
    MLV_Color couleur[20][10];
    piece pieceReserve;
    int reserveOccupee;
    piece piecesSuivantes[5];
} plateau;

plateau initialiserPlateau(plateau monPlateau);
void majPlateau(piece maPiece, plateau *monPlateau);
void mettreEnReserve(piece *maPiece, plateau *monPlateau);
void majPiecesSuivantes(piece *maPiece, plateau *monPlateau);
void majApresChute(piece maPiece, plateau *monPlateau);
int ligneComplete(plateau monPlateau);
void supprimerLigne(plateau *monPlateau, int ligne);
void descendreLignes(plateau *monPlateau, int ligne);
void fixPlateau(plateau *monPlateau);
int validerRotation(piece *maPiece, plateau *monPlateau, int x, int y);
int superRotation(piece *maPiece, plateau *monPlateau, int droite);

#endif /* PLATEAU_H */
