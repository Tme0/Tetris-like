/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/plateau.h"

plateau initialiserPlateau(plateau monPlateau){
    int i, j;
    for (i=0 ; i<20 ; i++) {
        for (j=0 ; j<10 ; j++) {
            monPlateau.state[i][j] = 0;
            monPlateau.couleur[i][j] = MLV_COLOR_BLACK;
        }
    }
    monPlateau.x = 0;
    monPlateau.y = 0;
    monPlateau.largeur = 10;
    monPlateau.hauteur = 20;
    return monPlateau;
}

void majPlateau(piece maPiece, plateau *monPlateau) {
    int i, j;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        for (j = 0 ; j < TAILLE_PIECE ; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                monPlateau->state[maPiece.y + i][maPiece.x + j] = 1;
                monPlateau->couleur[maPiece.y + i][maPiece.x + j] = maPiece.idPiece.couleur;
            }
        }
    }
}

void majApresChute(piece maPiece, plateau *monPlateau) { /* Permet d'effacer la pièce à la frame précédente (actualisation) */
    int i, j;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        for (j = 0 ; j < TAILLE_PIECE ; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                monPlateau->state[maPiece.y + i][maPiece.x + j] = 0;
                monPlateau->couleur[maPiece.y + i][maPiece.x + j] = MLV_COLOR_BLACK;
            }
        }
    }
}

int ligneComplete(plateau monPlateau) {
    int i, j, complet;
    i = 0;
    complet = 0;
    while (complet != 10 && i < 20){
        complet = 0;
        for (j = 0 ; j < 10 ; j++){
            if (monPlateau.state[i][j] == 1){
                complet++;
            }
        }
        i++;
    }
    if (complet == 10) {
        printf("Ligne %d complète\n", i-1);
        return i-1;
    }
    return -1;
}

void supprimerLigne(plateau *monPlateau, int ligne) {
    int j;
    for (j = 0 ; j < 10 ; j++) {
        monPlateau->state[ligne][j] = 0;
        monPlateau->couleur[ligne][j] = MLV_COLOR_BLACK;
    }
    descendreLignes(monPlateau, ligne);
    printf("Ligne %d supprimée\n", ligne);
}

void descendreLignes(plateau *monPlateau, int ligne) {
    int i, j;
    for (i = ligne ; i > 0 ; i--) {
        for (j = 0 ; j < 10 ; j++) {
            monPlateau->state[i][j] = monPlateau->state[i-1][j];
            monPlateau->couleur[i][j] = monPlateau->couleur[i-1][j];
        }
    }
}

void fixPlateau (plateau *monPlateau) {
  /* Le plateau fait souvent apparaître 255 dans les cases [19][7], [19][8] et [19][9],
     on utilise donc sa couleur pour savoir s'il y avait un 1 ou un 0 avant à la place.
     A voir si on appelle la fonction sur toute la ligne ou même tout le plateau
     si jamais d'autres cases peuvent se mettre à 255. */
  int j;
  for (j = 7 ; j < 10 ; j++){
    if (monPlateau->couleur[19][j] == MLV_COLOR_BLACK) {
      monPlateau->state[19][j] = 0;
    }
    else {
      monPlateau->state[19][j] = 1;
    }
  }
}

int validerRotation(piece *maPiece, plateau *monPlateau) {
  /* Fonction temporaire, ici on annule la rotation si elle est impossible,
     au lieu de tester d'autres emplacements.
     Ce n'est pas très optimisé car si la rotation est impossible
     alors on tourne la pièce 4 fois en tout.
     Pourra peut-être être modif et appelée pour vérifier les murs. */
  int i, j, x, y;
  x = maPiece->x;
  y = maPiece->y;
  for (i = 0; i < TAILLE_PIECE; i++) {
    for (j = 0; j < TAILLE_PIECE; j++) {
      if (maPiece->idPiece.forme[i][j] == 1) {
	if (y + i >= 20 || x + j >= 10 || x + j < 0) { /* Vérifie le sol et les murs (avant l'autre if sinon ça sort de la matrice) */
	  return 0;
	}
	if (monPlateau->state[y+i][x+j] == 1) { /* Vérifie si une case est déjà occupée */
	  return 0;
	}
      }
    }
  }
  return 1;
}

int verifRotation(piece *maPiece, plateau *monPlateau, int droite) {
  /* Sera appelé avec droite = 1 si rotation droite, droite = -1 si rotation gauche.
     On appelle la fonction avant la rotation si c'est vers la droite, après si vers la gauche,
     car cela permet de juste inverser les kicktables avec le paramètre droite.
     Par exemple la kicktable 0->1 vérifie avec les coordonnées (x-1,y-1) pour le test 3,
     et celle de 1->0 vérifie avec les coordonnées (x+1, y+1) pour ce même test */
  
  int i, j;
  int x, y; /* Coordonnées de base de la pièce */
  int ok;
  i = 0;
  j = 0;
  x = maPiece->x;
  y = maPiece->y;
  ok = 1;

  if (maPiece->idPiece.id != 2 && maPiece->idPiece.id != 4){

    if (maPiece->orientation == 1) {
      /* Test 1, avec les coordonnées de base */
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 1;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 2 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y;
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 2;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 3 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y + (-1 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 3;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 4 */
      x = maPiece->x;
      y = maPiece->y + (2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 4;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 5 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y + (2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 5;
      }

      return 0;
    
    }
    

    if (maPiece->orientation == 2) {
      /* Test 1, avec les coordonnées de base */
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 1;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 2 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y;
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 2;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 3 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y + (1 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 3;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 4 */
      x = maPiece->x;
      y = maPiece->y + (-2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 4;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 5 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y + (-2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 5;
      }

      return 0;
    
    }


    if (maPiece->orientation == 3) {
      /* Test 1, avec les coordonnées de base */
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 1;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 2 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y;
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 2;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 3 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y + (-1 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 3;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 4 */
      x = maPiece->x;
      y = maPiece->y + (2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 4;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 5 */
      x = maPiece->x + (1 * droite);
      y = maPiece->y + (2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 5;
      }

      return 0;
    
    }


    if (maPiece->orientation == 4) {
      /* Test 1, avec les coordonnées de base */
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 1;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 2 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y;
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 2;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 3 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y + (1 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 3;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 4 */
      x = maPiece->x;
      y = maPiece->y + (-2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 4;
      }

      i = 0;
      j = 0;
      ok = 1;

      /* Test 5 */
      x = maPiece->x + (-1 * droite);
      y = maPiece->y + (-2 * droite);
      while (ok == 1 && i < 4 && j < 4){
	if (maPiece->idPiece.forme[i][j] == 1 && monPlateau->state[y+i][x+j] == 1) {
	  ok = 0;
	}
	i++;
	j++;
      }
      if (ok == 1){
	return 5;
      }

      return 0;
    
    }
    
  }


  if (maPiece->idPiece.id == 2){ /* La barre a une kicktable différente */
    /* juste un truc inutile le temps que je finisse la fonction */
    return 0;
  }
  return 0;
}
