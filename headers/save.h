/*Ce fichier gère le système de sauvegarde de parties et de score.*/

#ifndef SAVE_H
#define SAVE_H

#include <MLV/MLV_all.h>
#include "../headers/piece.h"
#include "../headers/plateau.h"


void sauvegarderScore(int score);
int sauvegarderSave(char nom[10], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
int chargerSave(char nom[10], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);

#endif /* SAVE_H */