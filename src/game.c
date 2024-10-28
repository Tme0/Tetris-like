/* Ce fichier gère la logique principale du jeu.*/

#include "../headers/game.h"
#include <MLV/MLV_all.h>
#include <time.h>
#include "../headers/input.h"
#include "../headers/graphics.h"


void menu(int menu) {
    while (menu) {
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
        MLV_actualise_window();
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); 
        /*get_event à completer; Je ne sais pas comment ça marche.*/
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

scores recupererScores() { /*Probablement a l'origine d'une seg fault que je ne comprends pas*/
    scores mesScores;
    int score;
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
    fclose(fichier);
    return mesScores;
}