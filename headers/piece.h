/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

#include <MLV/MLV_all.h>

#define TAILLE_PIECE 4 /*Une taille 4*4 est necessaire pour permettre la rotation de la barre*/
#define NB_PIECES 9 /*Nombre de pièces différentes*/

typedef struct {
    int id;
    int forme[TAILLE_PIECE][TAILLE_PIECE];
    /*
    C'est une proposition de représentation des pièces mais j'y ai pas vraiment réfléchi, il y a peut-être plus optimisé / efficace / simple
    Bon courage pour changer maintenant cela dit x)
    */
    int couleur;
} idPiece;

typedef struct {
    int x;
    int y;
    idPiece idPiece;
    int orientation;
} piece;



piece creerPiece(int id);

#endif /* PIECE_H */