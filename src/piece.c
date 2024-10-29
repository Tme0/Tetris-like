/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/piece.h"
#include <time.h>

piece creerPiece(int id, int vit) {
    int i;
    piece maPiece;
    maPiece.x = 0;
    maPiece.y = 0;
    maPiece.idPiece.id = id;
    maPiece.orientation = 0;
    maPiece.vitesse = vit;
    maPiece.idPiece.couleur = MLV_COLOR_RED;
    switch (id) {
        case 1:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 4 || i == 8 || i == 9) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;

        case 2:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 4 || i == 8 || i == 12) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;

        case 3:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 1 || i == 4 || i == 8) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;

        case 4:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 1 || i == 4 || i == 5) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;
            
        case 5:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 1 || i == 5 || i == 6) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;
        case 6:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 1 || i == 2 || i == 4 || i == 5) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;
        case 7:
            for (i = 0; i < TAILLE_PIECE; i++) {
                if (i == 0 || i == 1 || i == 2 || i == 5) {
                    maPiece.idPiece.forme[i] = 1;
                } 
                else {
                    maPiece.idPiece.forme[i] = 0;
                }
            }
            break;
    }   
    return maPiece;
}


