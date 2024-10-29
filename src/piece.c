/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/piece.h"
#include <time.h>

piece creerPiece(int id) {
    piece maPiece;
    maPiece.x = 0;
    maPiece.y = 0;
    maPiece.idPiece.id = id;
    maPiece.orientation = 0;
    return maPiece;
}