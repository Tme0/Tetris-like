/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

#include <MLV/MLV_all.h>

#define TAILLE_PIECE 4

typedef struct {
    int id;
    int forme[TAILLE_PIECE][TAILLE_PIECE];
    /*
    C'est une proposition de représentation des pièces mais j'y ai pas vraiment réfléchi, il y a peut-être plus optimisé / efficace / simple
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



piece creerPiece(int id, int vit);

#endif /* PIECE_H */