/* Ce fichier gère les entrées utilisateur.*/

#ifndef INPUT_H
#define INPUT_H

#include <MLV/MLV_all.h>
#include "./types.h"

piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau);
int selectionMenuPrincipal();
void selectionMenuPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuSauvegarder(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuCharger();
void selectionMenuScores();
void selectionMenuParametres();

#endif /* INPUT_H */
