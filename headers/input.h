/* Ce fichier gère les entrées utilisateur.*/

#ifndef INPUT_H
#define INPUT_H

#include <MLV/MLV_all.h>
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include "../headers/game.h"

#define BOUTONS 5

typedef struct {
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    int index;
} bouton;

int selection(int nbBoutons, bouton boutons[BOUTONS]);
void selectionMenu();
piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau);
void mettreEnPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuPause(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuSauvegarder(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void selectionMenuCharger(int nbBoutons, bouton boutons[BOUTONS]);
void selectionMenuScores(bouton retour);
void selectionMenuParametres(int nbBoutons, bouton boutons[BOUTONS]);

#endif /* INPUT_H */
