/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/types.h"
#include "../headers/piece.h"

int nbAleatoire(int mi, int ma) {
    return rand() % (ma - mi + 1) + mi;
}

piece creerPiece(int id) {
    int i, j;
    piece maPiece;
    maPiece.x = 3;
    maPiece.y = -2;
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
                    if (i == 1) {
                        maPiece.idPiece.forme[i][j] = 1;
                    } 
                    else {
                        maPiece.idPiece.forme[i][j] = 0;
                    }
                }
            }
            maPiece.idPiece.couleur = MLV_COLOR_TURQUOISE2;
            break;

        /* J */
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

        /* O */
        case 4:
            for (i = 0; i < TAILLE_PIECE; i++) {
                for (j = 0; j < TAILLE_PIECE; j++) {
                    if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
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
                    if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)) {
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

void tournerPieceGauche(piece *maPiece) {
  int i, j;
  int tmp[3][3];
  
  if (maPiece->idPiece.id != 2 && maPiece->idPiece.id != 4){ /* On va ici si la pièce n'est ni un bloc, ni une barre */
    for (i = 0; i < 3; i++){
      for (j = 0 ; j < 3; j++){
        tmp[i][j] = maPiece->idPiece.forme[j][2-i];
      }
    }
    for (i = 0; i < 3; i++){
      for (j = 0 ; j < 3; j++){
	maPiece->idPiece.forme[i][j] = tmp[i][j];
      }
    }
  }
  
  if (maPiece->idPiece.id == 2){ /* On va ici si la pièce est une barre */
    switch (maPiece->orientation) {
      case 0 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (j == 1) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
	
      case 1 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (i == 1) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
	
      case 2 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (j == 2) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;

      case 3 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (i == 2) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
    }
  }
  maPiece->orientation = (maPiece->orientation + 3) % 4;
}


void tournerPieceDroite(piece *maPiece) {
  int i, j;
  int tmp[3][3];
  
  if (maPiece->idPiece.id != 2 && maPiece->idPiece.id != 4){ /* On va ici si la pièce n'est ni un bloc, ni une barre */
    for (i = 0; i < 3; i++){
      for (j = 0 ; j < 3; j++){
        tmp[i][j] = maPiece->idPiece.forme[2-j][i];
      }
    }
    for (i = 0; i < 3; i++){
      for (j = 0 ; j < 3; j++){
	maPiece->idPiece.forme[i][j] = tmp[i][j];
      }
    }
  }
  
  if (maPiece->idPiece.id == 2){ /* On va ici si la pièce est une barre */
    switch (maPiece->orientation) {
      case 0 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (j == 2) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
	
      case 1 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (i == 2) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
	
      case 2 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (j == 1) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;

      case 3 :
	for (i = 0; i < TAILLE_PIECE; i++) {
	  for (j = 0; j < TAILLE_PIECE; j++) {
	    if (i == 1) {
	      maPiece->idPiece.forme[i][j] = 1;
	    } 
	    else {
	      maPiece->idPiece.forme[i][j] = 0;
	    }
	  }
	}
	break;
    }
  }
  maPiece->orientation = (maPiece->orientation + 1) % 4;
}
