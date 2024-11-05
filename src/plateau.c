/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/plateau.h"

plateau initPlateau(plateau monPlateau) {
    int i,j;
    for (i = 0 ; i < 20 ; i++) {
        for (j = 0 ; j < 10 ; j++) {
            monPlateau.state[i][j] = 0;
            monPlateau.couleur[i][j] = MLV_COLOR_BLUE;
        }
    }
    monPlateau.x = 0;
    monPlateau.y = 0;
    monPlateau.largeur = 10;
    monPlateau.hauteur = 20;
    return monPlateau;
}

plateau majPlateau(piece maPiece, plateau monPlateau) {
    int h, l;
    for (h = TAILLE_PIECE-1 ; h > -1 ; h--) {
        for (l = TAILLE_PIECE-1 ; l > -1 ; l--) {
            if (maPiece.idPiece.forme[h][l] == 1) {
                monPlateau.state[maPiece.y + h][maPiece.x + l] = 1;
                monPlateau.couleur[maPiece.y + h][maPiece.x + l] = maPiece.idPiece.couleur;
                printf("ajout de la pièce\n");
            }
        }
    }
    return monPlateau;
}