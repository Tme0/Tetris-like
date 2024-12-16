/*Ce fichier gère la création et le mouvement des pièces.*/

#ifndef PIECE_H
#define PIECE_H

#include <./types.h>

int nbAleatoire(int mi, int ma);
piece creerPiece(int id);
void tournerPieceGauche(piece *maPiece);
void tournerPieceDroite(piece *maPiece);


#endif /* PIECE_H */
