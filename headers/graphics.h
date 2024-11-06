/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../headers/input.h"
#include "../headers/game.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#define N 50
#define SCORE_MAX 10

void initialiserFenetre();
void afficherMenu();
void afficherParametres();
void afficherPlateau(plateau monPlateau);
void afficherPiece(piece maPiece);
void afficherScores(scores mesScores);
void afficherSauvegarde();
void afficherParametresControles();
void afficherParametresVideo();
void afficherParametresAudio();

#endif /* GRAPHICS_H */