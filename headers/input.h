/* Ce fichier gère les entrées utilisateur.*/

#ifndef INPUT_H
#define INPUT_H

#include <MLV/MLV_all.h>/*Nécessaire */

typedef struct {
    int x_min; 
    int y_min;
    int x_plus_hauteur;
    int y_plus_largeur;
    int index;
} bouton;

void selection(int nbBoutons, bouton* boutons);
void selectionParametres();
void selectionMenu();
void selectionSauvegarde();
void resoudreEvenement(MLV_Keyboard_button touche);

#endif /* INPUT_H */