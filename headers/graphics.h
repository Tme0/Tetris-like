/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../headers/input.h"
#include "../headers/game.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#define N 50

void initialiserFenetre();
int afficherMenu();
void afficherMenuPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop);
void afficherMenuSauvegarder();
void afficherMenuCharger();
void afficherMenuParametres();
void afficherPlateau(plateau monPlateau);
void afficherPiece(piece maPiece);
void afficherMenuScores();
void afficherLogo();
void afficherContoursEtTextes();
int afficherScoresPendantPartie();
void afficherScoreActuel(int score);
void afficherPiecesSuivantes(plateau monPlateau);
void afficherReserve(plateau monPlateau);
void actualiserJeu(plateau monPlateau, piece maPiece, int score);
void afficherSauvegarde();
void afficherParametresControles();
void afficherParametresVideo();
void afficherParametresAudio();

#endif /* GRAPHICS_H */
