/* Ce fichier gère la logique principale du jeu.*/

#ifndef GAME_H
#define GAME_H

#include "../headers/piece.h"

typedef struct scores {
    int score[10];
} scores;

int nbAleatoire(int mi, int ma);
void menu(int menuActif);
int jouer();
int estPosee(piece maPiece, plateau monPlateau);
void majPlateau(piece maPiece, plateau *monPlateau);
plateau initPlateau(plateau monPlateau);
scores recupererScores();


#endif /* GAME_H */