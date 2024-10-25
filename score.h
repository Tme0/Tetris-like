#include <stdio.h>
#include <stdlib.h>

void sauvegarderScore(int score) {
    FILE *fichier = fopen("scores.txt", "a");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier scores.txt\n");
        exit(1);
    }
    fprintf(fichier, "%d\n", score);
    fclose(fichier);
}

void afficherScores() {
    int score;
    int nb_lignes = 0;
    FILE *fichier = fopen("scores.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier scores.txt\n");
        exit(1);
    }
    while (fscanf(fichier, "%d\n", &score) != EOF && nb_lignes < 10) {
        nb_lignes++;
        printf("%d\n", score);
    }
    fclose(fichier);
}