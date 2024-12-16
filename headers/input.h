/* Ce fichier gère les entrées utilisateur.*/

#ifndef INPUT_H
#define INPUT_H

#include <MLV/MLV_all.h>
#include "./types.h"

piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau);
void mettreEnPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
int selectionMenuPrincipal(int nbBoutons, bouton boutons[BOUTONS]);
void selectionMenuPause(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuSauvegarder(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuCharger(int nbBoutons, bouton boutons[BOUTONS]);
void selectionMenuScores(bouton retour);
void selectionMenuParametres(int nbBoutons, bouton boutons[BOUTONS]);

#endif /* INPUT_H */
