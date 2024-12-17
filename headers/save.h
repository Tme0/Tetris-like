/*Ce fichier gère le système de sauvegarde de parties et de score.*/

#ifndef SAVE_H
#define SAVE_H

#include "./types.h"

void sauvegarderScore(int score);
int sauvegarderSave(char nom[23], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
int chargerSave(char nom[23], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);

#endif /* SAVE_H */
