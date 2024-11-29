/*Ce fichier gère le système de sauvegarde de parties et de score.*/

#include "../headers/save.h"
#include <stdio.h>
#include <stdlib.h>

void sauvegarderScore(int score) {
    FILE *fichier;
    if ((fichier = fopen("scores.txt", "a")) == NULL) {
        printf("Impossible d'ouvrir le fichier scores.txt\n");
    }
    fprintf(fichier, "%d\n", score);
    fclose(fichier);
}