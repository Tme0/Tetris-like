/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "./types.h"

void initialiserFenetre();
void afficherMenuPrincipal();
void afficherMenuPause();
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
