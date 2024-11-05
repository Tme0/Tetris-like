/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/piece.h"
#include <time.h>

piece creerPiece(int id, int vit) {
    int h, l;
    piece maPiece;
    maPiece.x = 0;
    maPiece.y = 0;
    maPiece.idPiece.id = id;
    maPiece.orientation = 0;
    maPiece.vitesse = vit;
    maPiece.idPiece.couleur = MLV_COLOR_RED;

    for (h = 0; h < TAILLE_PIECE; h++) {
        for (l = 0; l < TAILLE_PIECE; l++) {
            maPiece.idPiece.forme[h][l] = 0;
        }
    }

    switch (id) {
        case 1:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[1][0] = 1;
            maPiece.idPiece.forme[2][0] = 1;
            maPiece.idPiece.forme[2][1] = 1;
            break;

        case 2:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[1][0] = 1;
            maPiece.idPiece.forme[2][0] = 1;
            maPiece.idPiece.forme[3][0] = 1;
            break;

        case 3:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[0][1] = 1;
            maPiece.idPiece.forme[1][0] = 1;
            maPiece.idPiece.forme[2][0] = 1;
            break;

        case 4:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[0][1] = 1;
            maPiece.idPiece.forme[1][0] = 1;
            maPiece.idPiece.forme[1][1] = 1;
            break;
            
        case 5:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[0][1] = 1;
            maPiece.idPiece.forme[1][1] = 1;
            maPiece.idPiece.forme[1][2] = 1;
            break;

        case 6:
            maPiece.idPiece.forme[0][1] = 1;
            maPiece.idPiece.forme[0][2] = 1;
            maPiece.idPiece.forme[1][0] = 1;
            maPiece.idPiece.forme[1][1] = 1;
            break;

        case 7:
            maPiece.idPiece.forme[0][0] = 1;
            maPiece.idPiece.forme[0][1] = 1;
            maPiece.idPiece.forme[0][2] = 1;
            maPiece.idPiece.forme[1][1] = 1;
            break;
    }   
    return maPiece;
}


