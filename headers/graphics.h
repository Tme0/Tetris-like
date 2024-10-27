/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../headers/input.h"
#include "../headers/game.h"
#define N 50

void initialiserFenetre();
void afficherMenu();
void afficherParametres();
void afficherScores(scores mesScores);
void afficherSauvegarde();
void afficherParametresControles();
void afficherParametresVideo();
void afficherParametresAudio();

#endif /* GRAPHICS_H */