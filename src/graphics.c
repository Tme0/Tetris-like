/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#include "../headers/graphics.h"
#include "../headers/input.h"
#include <MLV/MLV_all.h>
#include <stdio.h>

void initialiserFenetre() {
    MLV_create_full_screen_window("Tetris-like", "Tetris-like", 1920, 1080);
}

void afficherMenu() { /*Fonctionnel : A rendre beau*/
    bouton nouvellePartie = {100, 100, 300, 150, 1};
    bouton chargerPartie = {100, 200, 300, 250, 2};
    bouton scores = {100, 300, 300, 350, 3};
    bouton parametres = {100, 400, 300, 450, 4};
    bouton quitter = {100, 500, 300, 550, 5};
    char texte_menu_1[N] = "Nouvelle partie";
    char texte_menu_2[N] = "Charger une partie";
    char texte_menu_3[N] = "Afficher les scores";
    char texte_menu_4[N] = "Parametres";
    char texte_menu_5[N] = "Quitter";
    MLV_draw_text_box(100, 100, 200, 50, texte_menu_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 200, 200, 50, texte_menu_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 300, 200, 50, texte_menu_3, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 400, 200, 50, texte_menu_4, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 500, 200, 50, texte_menu_5, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(5, (bouton[]){nouvellePartie, chargerPartie, scores, parametres, quitter});
}

void afficherParametres() { /*Fonctionnel : A rendre beau*/
    bouton parametresControles = {100, 100, 300, 150, 6};
    bouton parametresVideo = {100, 200, 300, 250, 7};
    bouton parametresAudio = {100, 300, 300, 350, 8};
    bouton retour = {100, 400, 300, 450, 9};
    char texte_parametres_1[N] = "Controles";
    char texte_parametres_2[N] = "Video";
    char texte_parametres_3[N] = "Audio";
    char texte_parametres_4[N] = "Retour";
    MLV_draw_text_box(100, 100, 200, 50, texte_parametres_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 200, 200, 50, texte_parametres_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 300, 200, 50, texte_parametres_3, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 400, 200, 50, texte_parametres_4, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(4, (bouton[]){parametresControles, parametresVideo, parametresAudio, retour});
}

void afficherScores(scores mesScores) { /*Fonctionnel : A rendre beau*/
    int milieu = (1920 - 200) / 2;
    bouton retour = {milieu, milieu + 100, 200, 250, 9};
    printf("%d\n", milieu);
    char texte_scores_1[N] = "Scores";
    char texte_scores_2[N] = "Retour";
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_box(milieu, 100, 200, 50, texte_scores_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 200, 200, 50, texte_scores_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(1, (bouton[]){retour});
}

void afficherSauvegarde() { /*A completer*/
    printf("Charger une partie\n");
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