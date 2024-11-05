/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#include "../headers/graphics.h"
#include "../headers/input.h"
#include <MLV/MLV_all.h>
#include <stdio.h>

void initialiserFenetre() {
    MLV_create_full_screen_window("Tetris-like", "Tetris-like", 1920, 1080);
}

void afficherMenu() { /*Fonctionnel : A rendre beau*/
    int largeurBouton = 400;
    int hauteurBouton = 100;
    int milieu = (1920 - largeurBouton) / 2;
    bouton nouvellePartie = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 1};
    bouton chargerPartie = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 2};
    bouton scores = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 3};
    bouton parametres = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 4};
    bouton quitter = {milieu, 700, milieu + largeurBouton, 700 + hauteurBouton, 5};
    char texte_menu_1[N] = "Nouvelle partie";
    char texte_menu_2[N] = "Charger une partie";
    char texte_menu_3[N] = "Afficher les scores";
    char texte_menu_4[N] = "Parametres";
    char texte_menu_5[N] = "Quitter";
    MLV_clear_window(MLV_COLOR_DARK_GREY);
    MLV_draw_text_box(milieu, 100, largeurBouton, hauteurBouton, texte_menu_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 250, largeurBouton, hauteurBouton, texte_menu_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 400, largeurBouton, hauteurBouton, texte_menu_3, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 550, largeurBouton, hauteurBouton, texte_menu_4, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 700, largeurBouton, hauteurBouton, texte_menu_5, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(5, (bouton[]){nouvellePartie, chargerPartie, scores, parametres, quitter});
}

void afficherParametres() { /*Fonctionnel : A rendre beau*/
    int largeurBouton = 400;
    int hauteurBouton = 100;
    int milieu = (1920 - largeurBouton) / 2;
    bouton parametresControles = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 6};
    bouton parametresVideo = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 7};
    bouton parametresAudio = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 8};
    bouton retour = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 9};
    char texte_parametres_1[N] = "Controles";
    char texte_parametres_2[N] = "Video";
    char texte_parametres_3[N] = "Audio";
    char texte_parametres_4[N] = "Retour";
    MLV_clear_window(MLV_COLOR_DARK_GREY);
    MLV_draw_text_box(milieu, 100, largeurBouton, hauteurBouton, texte_parametres_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 250, largeurBouton, hauteurBouton, texte_parametres_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 400, largeurBouton, hauteurBouton, texte_parametres_3, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 550, largeurBouton, hauteurBouton, texte_parametres_4, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(4, (bouton[]){parametresControles, parametresVideo, parametresAudio, retour});
}

void afficherPlateau(plateau monPlateau) {
    int h, l;
    int offsetX = (1920 - monPlateau.largeur * 40) / 2;
    int offsetY = (1080 - monPlateau.hauteur * 40) / 2;
    for (l = 0; l < monPlateau.hauteur; l++) {
        for (h = 0; h < monPlateau.largeur; h++) {
            if (monPlateau.state[h][l] != 0) {
                MLV_draw_filled_rectangle(offsetX + h * 40, offsetY + l * 40, 40, 40, MLV_COLOR_BLUE);
            }
            else {
                MLV_draw_filled_rectangle(offsetX + h * 40, offsetY + l * 40, 40, 40, MLV_COLOR_WHITE);
            }
        }
    }
}

void afficherPiece(piece maPiece) {
    int h, l;
    int offsetX = (1920 - 10 * 40) / 2;
    int offsetY = (1080 - 20 * 40) / 2;
    for (h = 0; h < TAILLE_PIECE; h++) {
        for (l = 0; l < TAILLE_PIECE; l++) {
            if (maPiece.idPiece.forme[h][l] != 0) {
                MLV_draw_filled_rectangle(offsetX + (maPiece.x + l) * 40, offsetY + (maPiece.y + h) * 40, 40, 40, maPiece.idPiece.couleur);
            }
        }
    }
}

void afficherScores(scores mesScores) { /*Fonctionnel : A rendre beau*/
    int milieu = (1920 - 200) / 2;
    int i;
    bouton retour = {milieu, milieu + 100, 200, 250, 9};
    char texte_scores_1[N] = "Retour";
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_box(milieu, 100, 200, 50, texte_scores_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    for (i = 0; i < 10; i++) {
        MLV_draw_text_box(milieu, 200 + i * 50, 200, 50, "", 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    }
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