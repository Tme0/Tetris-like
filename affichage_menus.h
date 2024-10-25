#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "score.h"
#define N 50


void selectionMenu();
void afficherMenu();
void selectionParametres();
void afficherParametres();
void choisirSauvegarde();
void afficherScores();
void parametresControles();
void parametresVideo();
void parametresAudio();


void initialiserFenetre() {
    MLV_create_window("Tetris-like", "Tetris-like", 1920, 1080);
}

void selectionMenu() {
    int x, y;
    MLV_wait_mouse(&x, &y);
    if (x >= 100 && x <= 300 && y >= 100 && y <= 150) {
        jouer();
    } else if (x >= 100 && x <= 300 && y >= 200 && y <= 250) {
        choisirSauvegarde();
    } else if (x >= 100 && x <= 300 && y >= 300 && y <= 350) {
        afficherScores();
    } else if (x >= 100 && x <= 300 && y >= 400 && y <= 450) {
        afficherParametres();
    } else if (x >= 100 && x <= 300 && y >= 500 && y <= 550) {
        exit(EXIT_SUCCESS);
    }
}

void afficherMenu() {
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

void selectionParametres() {
    int x, y;
    MLV_wait_mouse(&x, &y);
    if (x >= 100 && x <= 300 && y >= 100 && y <= 150) {
        parametresControles();
    } else if (x >= 100 && x <= 300 && y >= 200 && y <= 250) {
        parametresVideo();
    } else if (x >= 100 && x <= 300 && y >= 300 && y <= 350) {
        parametresAudio();
    } else if (x >= 100 && x <= 300 && y >= 400 && y <= 450) {
        afficherMenu();
    }
}

void afficherParametres() {
    char texte_parametres_1[N] = "Taille de la grille";
    char texte_parametres_2[N] = "Vitesse de chute";
    char texte_parametres_3[N] = "Couleur des blocs";
    char texte_parametres_4[N] = "Retour";
    MLV_draw_text_box(100, 100, 200, 50, texte_parametres_1, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 200, 200, 50, texte_parametres_2, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 300, 200, 50, texte_parametres_3, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(100, 400, 200, 50, texte_parametres_4, 0, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selectionParametres();
}