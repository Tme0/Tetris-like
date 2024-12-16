/* Ce fichier contient les types utilisés par le programme */

#ifndef TYPES_H
#define TYPES_H

#include <MLV/MLV_all.h>

#define TAILLE_PIECE 4
#define BOUTONS 5
#define N 50

typedef struct {
    int id;
    int forme[TAILLE_PIECE][TAILLE_PIECE];
    /*
    Changement de la représentation, c'est maintenant une matrice 4x4 :

    X O O O  ---->  forme[0][0] = 1, forme[0][1] = 0, forme[0][2] = 0, forme[0][3] = 0,
    X O O O  ---->  forme[1][0] = 1, forme[1][1] = 0, forme[1][2] = 0, forme[1][3] = 0,
    X X O O  ---->  forme[2][0] = 1, forme[2][1] = 1, forme[2][2] = 0, forme[2][3] = 0,
    O O O O  ---->  forme[3][0] = 0, forme[3][1] = 0, forme[3][2] = 0, forme[3][3] = 0
    */
    int couleur;
} idPiece;

typedef struct {
    int x;
    int y;
    idPiece idPiece;
    int orientation;
} piece;

typedef struct {
    int state[20][10];
    int x;
    int y;
    int largeur;
    int hauteur;
    int taille;
    MLV_Color couleur[20][10];
    piece pieceReserve;
    int reserveOccupee;
    piece piecesSuivantes[5];
} plateau;

typedef struct {
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    int index;
} bouton;

#endif /* TYPES_H */
