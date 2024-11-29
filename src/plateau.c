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
