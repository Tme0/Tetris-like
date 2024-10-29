/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

#include <MLV/MLV_all.h>

#define TAILLE_PIECE 16

typedef struct {
    int id;
    int forme[TAILLE_PIECE];
    /*
    C'est une propossition de représentation des pièces mais j'y ai pas vraiment réfléchi, il y a peut-être plus optimisé / efficace :

    X O O O  ---->  forme[1] = 1, forme[2] = 0, forme[3] = 0, forme[4] = 0,
    X O O O  ---->  forme[5] = 1, forme[6] = 0, forme[7] = 0, forme[8] = 0,
    X X O O  ---->  forme[9] = 1, forme[10] = 1, forme[11] = 0, forme[12] = 0,
    O O O O  ---->  forme[13] = 0, forme[14] = 0, forme[15] = 0, forme[16] = 0
    */
    int couleur;
} idPiece;

typedef struct {
    int x;
    int y;
    idPiece idPiece;
    int orientation;
    int vitesse;
} piece;

typedef struct {
    int state[10*20];
    int x;
    int y;
    int largeur;
    int hauteur;
    MLV_Color couleur[10*20];
} plateau;

piece creerPiece(int id, int vit);

#endif /* PIECE_H */