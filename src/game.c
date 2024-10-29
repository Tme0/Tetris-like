/* Ce fichier gère la logique principale du jeu.*/

#include "../headers/game.h"
#include <MLV/MLV_all.h>
#include <time.h>
#include "../headers/input.h"
#include "../headers/graphics.h"
#include "../headers/piece.h"


void menu(int menuActif) {
    while (menuActif != 0) {
        afficherMenu();
    }
}

int jouer() {
    struct timespec debut, fin;
    MLV_Keyboard_button touche;
    int continuer = 1;
    long int tempsAttente;
    MLV_clear_window(MLV_COLOR_BLACK);
    while (continuer) {
        /*Temps au début l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        piece maPiece = creerPiece(nbAleatoire(1, 7));
        MLV_actualise_window();
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); 
        resoudreEvenement(touche);

        /*Temps à la fin de l'image et boucle while pour completer le temps manquant (60/1 sec)*/
        clock_gettime(CLOCK_REALTIME, &fin );
        tempsAttente = 16 - (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;
        if (tempsAttente > 0) {
            MLV_wait_milliseconds(tempsAttente);
        }
    }
    return 0;
}

scores recupererScores() {
    scores mesScores;
    int score, i;
    int nb_lignes = 0;
    FILE *fichier;
    fichier = fopen("./ressources/scores.txt", "r");
    if (fichier == NULL) {
        printf("Création du fichier scores.txt\n");
        fichier = fopen("./ressources/scores.txt", "a+");
    }
    while (fscanf(fichier, "%d\n", &score) != EOF && nb_lignes < 10) {
        nb_lignes++;
        mesScores.score[nb_lignes]=score;
        printf("%d\n", mesScores.score[nb_lignes]);
    }
    for (i = 0 ; i < nb_lignes ; i++) {
        MLV_draw_text(100, 100 + 50 * i, "%d", mesScores.score[i]);
    }
    fclose(fichier);
    return mesScores;
}

int nbAleatoire(int mi, int ma) {
    return rand() % (ma - mi + 1) + mi;
}