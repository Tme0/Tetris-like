/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/piece.h"
#include <time.h>

piece creerPiece(int id) {
    int i, j;
    piece maPiece;
    maPiece.x = 3;
    maPiece.y = -1;
    maPiece.idPiece.id = id;
    maPiece.orientation = 0;
    switch (id) {
        /* L */
        case 1:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_ORANGERED;
            break;

        /* | */
        case 2:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if (i == 0) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_TURQUOISE2;
            break;

        /* L inversé */
        case 3:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_BLUE;
            break;

        /* bloc */
        case 4:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_GOLD;
            break;

        /* Z */
        case 5:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_rgba(220,20,60,MLV_ALPHA_OPAQUE);
            break;

        /* S */ 
        case 6:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 1)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_GREEN;
            break;

        /* T */
        case 7:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 1)) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_PURPLE2;
            break;
    }   
    return maPiece;
}

/* J'allais le faire mais jsp comment le faire */
/* piece tournerPiece(int id){ */
/*     int i; */
/*     piece maPiece; */
/*     maPiece.idPiece.id = id; */
/*     maPiece.orientation = 1; */
/*     maPiece.vitesse = vit; */
/*     switch (id) { */
/*         /\* L *\/ */
/*         case 1: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 2 || i == 4 || i == 5 || i == 6) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_ORANGERED; */
/*             break; */

/*         /\* | *\/ */
/*         case 2: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 0 || i == 1 || i == 2 || i == 3) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_TURQUOISE2; */
/*             break; */

/*         /\* L inversé *\/ */
/*         case 3: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 0 || i == 4 || i == 5 || i == 6) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_BLUE; */
/*             break; */

/*         /\* bloc *\/ */
/*         case 4: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 0 || i == 1 || i == 4 || i == 5) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_GOLD; */
/*             break; */

/*         /\* Z *\/ */
/*         case 5: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 0 || i == 1 || i == 5 || i == 6) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_rgba(220,20,60,MLV_ALPHA_OPAQUE); */
/*             break; */

/*         /\* S *\/  */
/*         case 6: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 1 || i == 2 || i == 4 || i == 5) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_GREEN; */
/*             break; */

/*         /\* T *\/ */
/*         case 7: */
/*             for (i = 0; i < TAILLE_PIECE; i++) { */
/*                 if (i == 0 || i == 1 || i == 2 || i == 5) { */
/*                     maPiece.idPiece.forme[i] = 1; */
/*                 }  */
/*                 else { */
/*                     maPiece.idPiece.forme[i] = 0; */
/*                 } */
/*             } */
/*             maPiece.idPiece.couleur = MLV_COLOR_PURPLE2; */
/*             break; */
/*     }    */
/*     return maPiece; */
/* } */
