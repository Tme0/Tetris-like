/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

#include <MLV/MLV_all.h>

#define TAILLE_PIECE 4

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

int nbAleatoire(int mi, int ma);
piece creerPiece(int id);
void tournerPieceGauche(piece *maPiece);
void tournerPieceDroite(piece *maPiece);


#endif /* PIECE_H */
