/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#include "../headers/graphics.h"
#include <MLV/MLV_all.h>

void initialiserFenetre() {
    MLV_create_full_screen_window("Tetris-like", "Tetris-like", 1920, 1080);
}

void afficherMenu() { /*Fonctionnel : A rendre beau*/
    char texte_menu_1[N] = "Nouvelle partie";
    char texte_menu_2[N] = "Charger une partie";
    char texte_menu_3[N] = "Afficher les scores";
    char texte_menu_4[N] = "Parametres";
    char texte_menu_5[N] = "Quitter";
    MLV_draw_text_box(100, 100, 200, 50, texte_menu_1, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 200, 200, 50, texte_menu_2, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 300, 200, 50, texte_menu_3, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 400, 200, 50, texte_menu_4, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 500, 200, 50, texte_menu_5, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selectionMenu();
}

void afficherParametres() { /*Fonctionnel : A rendre beau*/
    char texte_parametres_1[N] = "Controles";
    char texte_parametres_2[N] = "Video";
    char texte_parametres_3[N] = "Audio";
    char texte_parametres_4[N] = "Retour";
    MLV_draw_text_box(100, 100, 200, 50, texte_parametres_1, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 200, 200, 50, texte_parametres_2, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 300, 200, 50, texte_parametres_3, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 400, 200, 50, texte_parametres_4, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selectionParametres();
}

void afficherScores() { /*Jamais testé*/
    int score;
    int nb_lignes = 0;
    FILE *fichier = fopen("scores.txt", "r");
    if (fichier == NULL) {
        fopen("scores.txt", "w");
        fichier = fopen("scores.txt", "r");
    }
    while (fscanf(fichier, "%d\n", &score) != EOF && nb_lignes < 10) {
        nb_lignes++;
        printf("%d\n", score); /* A remplacer par un affichage in-game */
    }
    fclose(fichier);
}

void afficherSauvegarde() { /*A completer*/
    printf("Sauvegarde\n");
}

void afficherParametresControles(){ /*A completer*/
    printf("Controles\n"); 
}
void afficherParametresVideo(){ /*A completer*/
    printf("Video\n");
}
void afficherParametresAudio(){ /*A completer*/
    printf("Audio\n");
}