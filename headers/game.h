/* Ce fichier gère la logique principale du jeu.*/

#ifndef GAME_H
#define GAME_H

#include "./types.h"

int menu(int menuActif);
int jouer();
int estPosee(piece maPiece, plateau monPlateau);
int collisionDroite(piece maPiece, plateau monPlateau);
int collisionGauche(piece maPiece, plateau monPlateau);
void tomberPiece(piece *maPiece, plateau *monPlateau);
int finJeu(piece maPiece);


#endif /* GAME_H */
