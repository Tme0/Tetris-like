/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

typedef struct {
    int x;
    int y;
    int id;
    int orientation;
} Piece;

Piece creerPiece(int id);



#endif /* PIECE_H */