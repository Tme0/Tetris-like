/* Ce fichier gère les entrées utilisateur.*/

#ifndef INPUT_H
#define INPUT_H

#include <MLV/MLV_all.h>/*Nécessaire */
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include "../headers/game.h"

#define BOUNTONS 9

typedef struct {
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    int index;
} bouton;

void selection(int nbBoutons, bouton boutons[BOUNTONS]);
void selectionParametres();
void selectionMenu();
void selectionSauvegarde();
piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau);

#endif /* INPUT_H */
