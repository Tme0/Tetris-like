/* Ce fichier gère la logique principale du jeu.*/

#ifndef GAME_H
#define GAME_H

#include "../headers/piece.h"
#include "../headers/plateau.h"

typedef struct scores {
    int score[10];
} scores;

void menu(int menuActif);
int jouer();
int estPosee(piece maPiece, plateau monPlateau);
int colisionDroite(piece maPiece, plateau monPlateau);
int colisionGauche(piece maPiece, plateau monPlateau);
void tomberPiece(piece *maPiece, plateau *monPlateau);
int finJeu(piece maPiece);
scores recupererScores();


#endif /* GAME_H */