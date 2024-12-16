/*Ce fichier gère le système de sauvegarde de parties et de score.*/

#include "../headers/types.h"
#include "../headers/save.h"
#include <stdio.h>
#include <stdlib.h>

void sauvegarderScore(int score) {
    /* int i; */
    FILE *fichier;
    if ((fichier = fopen("./ressources/scores.txt", "a")) == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier scores.txt\n");
    }
    /* à finir */
    /* while (i < 10 && score <= score_fichier) { */
    /* } */
    fprintf(fichier, "%d\n", score);
    fclose(fichier);
}

int sauvegarderSave(char nom[18], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int i, j;
    FILE *fichier;
    printf("continuer : %d\n", *continuer);
    printf("niveau : %d\n", *niveau);
    printf("score : %d\n", *score);
    printf("reserveUtilisee : %d\n", *reserveUtilisee);
    printf("hardDrop : %d\n", *hardDrop);

    for (i=0;i<20;i++){
      for (j=0;j<10;j++){
	printf("%d ", monPlateau->state[i][j]);
      }
      printf("\n");
    }
    
    if ((fichier = fopen(nom, "wb+")) == NULL) {
        printf("Erreur\n");
        return -1;
    }

    /* ---------- SAVE DU PLATEAU ---------- */

    /* Save de la grille */
    for (i = 0 ; i < monPlateau->hauteur ; i++) {
        if (fwrite(monPlateau->state[i], sizeof(int), (size_t)monPlateau->largeur, fichier) != (size_t)monPlateau->largeur) {
	    fprintf(stderr, "Erreur : écriture matrice à la ligne %d \n", i);
            fclose(fichier);
            return -1;
        }
    }

    /* Save des couleurs de la grille */
    for (i = 0 ; i < monPlateau->hauteur ; i++) {
        if (fwrite(monPlateau->couleur[i], sizeof(MLV_Color), (size_t)monPlateau->largeur, fichier) != (size_t)monPlateau->largeur) {
            fprintf(stderr, "Erreur lors de l'écriture des couleurs du plateau.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Save de reserveOccupee */
    if (fwrite(&monPlateau->reserveOccupee, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de reserveOccupee.\n");
        fclose(fichier);
        return -1;
    }

    /* Save de la réserve, si elle est occupée */
    if (monPlateau->reserveOccupee == 1){
        if (fwrite(&monPlateau->pieceReserve, sizeof(piece), 1, fichier) != 1) {
            fprintf(stderr, "Erreur lors de l'écriture de la réserve.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Save du tableau des pièces suivantes */
    for (i = 0 ; i < 5 ; i++) {
        if (fwrite(&monPlateau->piecesSuivantes[i], sizeof(piece), 1, fichier) != 1) {
            fprintf(stderr, "Erreur lors de l'écriture des pièces suivantes.\n");
            fclose(fichier);
            return -1;
        }
    }
    

    /* ---------- SAVE DE LA PIECE ACTIVE ---------- */

    /* Save de l'id de la pièce */
    if (fwrite(&maPiece->idPiece.id, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de l'id de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Save de la couleur de la pièce */
    if (fwrite(&maPiece->idPiece.couleur, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de la couleur de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Save de la forme de la pièce */
    for (i = 0 ; i < 4 ; i++) {
        if (fwrite(maPiece->idPiece.forme[i], sizeof(int), 4, fichier) != 4) {
            fprintf(stderr, "Erreur lors de l'écriture de la forme de la pièce.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Save du x de la pièce */
    if (fwrite(&maPiece->x, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture du x de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Save du y de la pièce */
    if (fwrite(&maPiece->y, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture du y de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Save de l'orientation de la pièce */
    if (fwrite(&maPiece->orientation, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de l'orientation de la pièce.\n");
        fclose(fichier);
        return -1;
    }


    /* ---------- SAVE DES DIFFERENTES VARIABLES ---------- */

    if (fwrite(&mouvementVertical, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de mouvementVertical.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&frame, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de frame.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&aBouge, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de aBouge.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&continuer, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de continuer.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&niveau, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de niveau.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&score, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de score.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&reserveUtilisee, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de reserveUtilisee.\n");
        fclose(fichier);
        return -1;
    }

    if (fwrite(&hardDrop, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de l'écriture de hardDrop.\n");
        fclose(fichier);
        return -1;
    }
    fclose(fichier);
    return 1;
}


int chargerSave(char nom[18], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int i;
    FILE *fichier;
    
    if ((fichier = fopen(nom, "rb")) == NULL) {
        printf("Erreur\n");
        return -1;
    }

    /* ---------- CHARGE DU PLATEAU ---------- */

    /* Charge de la grille */
    for (i = 0 ; i < monPlateau->hauteur ; i++) {
        if (fread(monPlateau->state[i], sizeof(int), (size_t)monPlateau->largeur, fichier) != (size_t)monPlateau->largeur) {
	  /*fprintf(stderr, "Erreur lors de l'écriture de la grille.\n");*/
	    fprintf(stderr, "Erreur : lecture matrice à la ligne %d \n", i);
            fclose(fichier);
            return -1;
        }
    }

    /* Charge des couleurs de la grille */
    for (i = 0 ; i < monPlateau->hauteur ; i++) {
        if (fread(&monPlateau->couleur[i], sizeof(MLV_Color), (size_t)monPlateau->largeur, fichier) != (size_t)monPlateau->largeur) {
            fprintf(stderr, "Erreur lors de la lecture des couleurs du plateau.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Charge de reserveOccupee */
    if (fread(&monPlateau->reserveOccupee, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de reserveOccupee.\n");
        fclose(fichier);
        return -1;
    }

    /* Charge de la réserve, si elle est occupée */
    if (monPlateau->reserveOccupee == 1){
        if (fread(&monPlateau->pieceReserve, sizeof(piece), 1, fichier) != 1) {
            fprintf(stderr, "Erreur lors de la lecture de la réserve.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Charge du tableau des pièces suivantes */
    for (i = 0 ; i < 5 ; i++) {
        if (fread(&monPlateau->piecesSuivantes[i], sizeof(piece), 1, fichier) != 1) {
            fprintf(stderr, "Erreur lors de la lecture des pièces suivantes.\n");
            fclose(fichier);
            return -1;
        }
    }
    

    /* ---------- CHARGE DE LA PIECE ACTIVE ---------- */

    /* Charge de l'id de la pièce */
    if (fread(&maPiece->idPiece.id, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de l'id de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Charge de la couleur de la pièce */
    if (fread(&maPiece->idPiece.couleur, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de la couleur de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Charge de la forme de la pièce */
    for (i = 0 ; i < 4 ; i++) {
        if (fread(maPiece->idPiece.forme[i], sizeof(int), 4, fichier) != 4) {
            fprintf(stderr, "Erreur lors de la lecture de la forme de la pièce.\n");
            fclose(fichier);
            return -1;
        }
    }

    /* Charge du x de la pièce */
    if (fread(&maPiece->x, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture du x de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Charge du y de la pièce */
    if (fread(&maPiece->y, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture du y de la pièce.\n");
        fclose(fichier);
        return -1;
    }

    /* Charge de l'orientation de la pièce */
    if (fread(&maPiece->orientation, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de l'orientation de la pièce.\n");
        fclose(fichier);
        return -1;
    }


    /* ---------- CHARGE DES DIFFERENTES VARIABLES ---------- */

    if (fread(&mouvementVertical, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de mouvementVertical.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&frame, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de frame.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&aBouge, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de aBouge.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&continuer, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de continuer.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&niveau, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de niveau.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&score, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de score.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&reserveUtilisee, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de reserveUtilisee.\n");
        fclose(fichier);
        return -1;
    }

    if (fread(&hardDrop, sizeof(int), 1, fichier) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de hardDrop.\n");
        fclose(fichier);
        return -1;
    }
    fclose(fichier);
    return 1;
}
