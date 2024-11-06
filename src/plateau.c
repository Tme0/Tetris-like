/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/plateau.h"

plateau initPlateau(plateau monPlateau) {
    int l, h;
    for (l = 0 ; l < 10 ; l++) {
        for (h = 0 ; h < 20 ; h++) {
            monPlateau.state[l][h] = 0;
            monPlateau.couleur[l][h] = MLV_COLOR_WHITE;
        }
    }
    monPlateau.x = 0;
    monPlateau.y = 0;
    monPlateau.largeur = 10;
    monPlateau.hauteur = 20;
    return monPlateau;
}

plateau majPlateau(piece maPiece, plateau monPlateau) {
    int h, l, newY, newX;
    printf("Maj du plateau ; piece en position (%d, %d)\n", maPiece.x, maPiece.y);
    for (l = 0; l < TAILLE_PIECE; l++) {
        for (h = 0; h < TAILLE_PIECE; h++) {
            if (maPiece.idPiece.forme[l][h] == 1) {
                newY = maPiece.x + h;
                newX = maPiece.y + l;
                printf("Partie de piece en position (%d, %d)\n", newX, newY);
                monPlateau.state[newY][newX] = 1;
                monPlateau.couleur[newY][newX] = maPiece.idPiece.couleur;
            }
        }
    }
    return monPlateau;
}

int ligneComplete(plateau monPlateau) {
    int h, l;
    for (h = 0; h < monPlateau.hauteur; h++) {
        for (l = 0; l < monPlateau.largeur; l++) {
            if (monPlateau.state[l][h] == 0) {
                break;
            }
        }
        if (l == monPlateau.largeur) {
            printf("Ligne %d complète\n", h);
            return h;
        }
    }
    return -1;
}

plateau supprimerLigne(plateau monPlateau, int ligne) {
    int h, l;
    for (h = ligne; h > 0; h--) {
        for (l = 0; l < monPlateau.largeur; l++) {
            printf("Décalage de la ligne %d case %d\n", h, l);
            monPlateau.state[l][h] = monPlateau.state[l][h - 1];
            monPlateau.couleur[l][h] = monPlateau.couleur[l][h - 1];
        }
    }
    for (l = 0; l < monPlateau.largeur; l++) {
        monPlateau.state[l][0] = 0;
        monPlateau.couleur[l][0] = MLV_COLOR_WHITE;
    }
    printf("Ligne %d supprimée\n", ligne);
    return monPlateau;
}