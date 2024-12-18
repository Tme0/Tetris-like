/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#include "../headers/types.h"
#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include <stdio.h>

void initialiserFenetre() {
    MLV_create_window("Tetris", "Tetris", 800, 800);
}

void afficherMenuPrincipal() {
    char texte_menu_1[N] = "Nouvelle partie";
    char texte_menu_2[N] = "Charger une partie";
    char texte_menu_3[N] = "Afficher les scores";
    char texte_menu_4[N] = "Parametres";
    char texte_menu_5[N] = "Quitter";

    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 200, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_1, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 300, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_2, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 400, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_3, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 500, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_4, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 600, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_5, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

void afficherMenuPause() {
    char texte_menu_pause_1[N] = "Reprendre la partie";
    char texte_menu_pause_2[N] = "Sauvegarder la partie";
    char texte_menu_pause_3[N] = "Menu principal";
    
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 200, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_pause_1, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 300, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_pause_2, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 400, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_pause_3, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

void afficherMenuSauvegarder() {
    char texte_menu_sauvegarder_1[N] = "Sauvegarde 1";
    char texte_menu_sauvegarder_2[N] = "Sauvegarde 2";
    char texte_menu_sauvegarder_3[N] = "Sauvegarde 3";
    char texte_menu_sauvegarder_4[N] = "Sauvegarde 4";
    char texte_menu_sauvegarder_5[N] = "Retour";
    
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 200, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_sauvegarder_1, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 300, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_sauvegarder_2, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 400, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_sauvegarder_3, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 500, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_sauvegarder_4, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 600, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_sauvegarder_5, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

void afficherMenuCharger() {
    char texte_menu_charger_1[N] = "Sauvegarde 1";
    char texte_menu_charger_2[N] = "Sauvegarde 2";
    char texte_menu_charger_3[N] = "Sauvegarde 3";
    char texte_menu_charger_4[N] = "Sauvegarde 4";
    char texte_menu_charger_5[N] = "Retour";
    
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 200, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_charger_1, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 300, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_charger_2, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 400, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_charger_3, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 500, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_charger_4, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 600, LARGEURBOUTON, HAUTEURBOUTON, texte_menu_charger_5, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

void afficherMenuParametres() {
    char texte_parametres_1[N] = "Controles";
    char texte_parametres_2[N] = "Video";
    char texte_parametres_3[N] = "Audio";
    char texte_parametres_4[N] = "Retour";

    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 200, LARGEURBOUTON, HAUTEURBOUTON, texte_parametres_1, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 300, LARGEURBOUTON, HAUTEURBOUTON, texte_parametres_2, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 400, LARGEURBOUTON, HAUTEURBOUTON, texte_parametres_3, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(MILIEU, 500, LARGEURBOUTON, HAUTEURBOUTON, texte_parametres_4, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
}

void afficherPlateau(plateau monPlateau) {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            MLV_draw_filled_rectangle(250+30*j, 150+30*i, 30, 30, monPlateau.couleur[i][j]);
            MLV_draw_rectangle(250+30*j, 150+30*i, 30, 30, MLV_COLOR_GREY50);
        }
    }
}

void afficherPiece(piece maPiece) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                MLV_draw_filled_rectangle(250 + (maPiece.x + j) * 30, 150 + (maPiece.y + i) * 30, 30, 30, maPiece.idPiece.couleur);
                MLV_draw_rectangle(250 + (maPiece.x + j) * 30, 150 + (maPiece.y + i) * 30, 30, 30, MLV_COLOR_GREY50);
            }
        }
    }
}

void afficherMenuScores() {
    char score[10];
    FILE *fichier;
    int i = 1;
    char i_char[3];
    char texte_scores[N] = "Retour";

    fichier = fopen("./ressources/scores.txt", "r");
    if (fichier == NULL) {
        printf("Création du fichier scores.txt\n");
        fichier = fopen("./ressources/scores.txt", "a+");
    }
    
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherLogo();
    MLV_draw_text_box(MILIEU, 600, LARGEURBOUTON, HAUTEURBOUTON, texte_scores, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    while (fscanf(fichier, "%s\n", score) != EOF && i < 11) {
        snprintf(i_char, 3, "%d", i);
        MLV_draw_text_box(275, 120+40*i, 40, 40, i_char, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
        MLV_draw_text_box(325, 120+40*i, 200, 40, score, 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
	i++;
    }
    fclose(fichier);
    MLV_actualise_window();
}

void afficherLogo(){
    int coordonnee1_x[4] = {260, 315, 330, 260};
    int coordonnee1_y[4] = {80, 80, 60, 60};
    int coordonnee2_x[4] = {260, 355, 340, 260};
    int coordonnee2_y[4] = {119, 119, 95, 95};
    int coordonnee3_x[4] = {445, 475, 500, 470};
    int coordonnee3_y[4] = {70, 119, 119, 70};
    int coordonnee4_x[4] = {445, 470, 500, 475};
    int coordonnee4_y[4] = {70, 70, 20, 20};
    int coordonnee5_x[4] = {525, 580, 605, 550};
    int coordonnee5_y[4] = {20, 119, 119, 20};
    /* cadre */
    MLV_draw_filled_rectangle(170, 10, 460, 120, MLV_COLOR_DARKBLUE); /* arrière-plan */
    MLV_draw_rectangle(170, 10, 460, 120, CONTOURS); /* contour */
    /* T */
    MLV_draw_filled_rectangle(180, 20, 80, 25, MLV_COLOR_RED); /* barre horizontale */
    MLV_draw_filled_rectangle(180+25, 20, 30, 100, MLV_COLOR_RED); /* barre verticale */
    /* E */
    MLV_draw_filled_rectangle(180+80, 20, 30, 100, MLV_COLOR_ORANGE_RED); /* barre verticale */
    MLV_draw_filled_rectangle(180+80, 20, 80, 25, MLV_COLOR_ORANGE_RED); /* haut */
    MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 4, MLV_COLOR_ORANGE_RED); /* milieu */
    MLV_draw_filled_polygon(coordonnee2_x, coordonnee2_y, 4, MLV_COLOR_ORANGE_RED); /* bas */
    /* T */
    MLV_draw_filled_rectangle(260+80, 20, 80, 25, MLV_COLOR_YELLOW); /* barre horizontale */
    MLV_draw_filled_rectangle(260+80+25, 20, 30, 100, MLV_COLOR_YELLOW); /* barre verticale */
    /* R */
    MLV_draw_filled_rectangle(340+80, 20, 25, 100, MLV_COLOR_GREEN); /* barre verticale */
    MLV_draw_filled_rectangle(340+80, 20, 60, 25, MLV_COLOR_GREEN); /* barre horizontale */
    MLV_draw_filled_polygon(coordonnee3_x, coordonnee3_y, 4, MLV_COLOR_GREEN); /* barre diagonale basse */
    MLV_draw_filled_polygon(coordonnee4_x, coordonnee4_y, 4, MLV_COLOR_GREEN); /* barre diagonale haute */
    /* I */
    MLV_draw_filled_rectangle(420+80, 20, 25, 100, MLV_COLOR_DEEPSKYBLUE);
    /* S */
    MLV_draw_filled_rectangle(500+25+20, 20, 60, 25, MLV_COLOR_PURPLE); /* haut */
    MLV_draw_filled_rectangle(500+25, 95, 60, 25, MLV_COLOR_PURPLE); /* bas */
    MLV_draw_filled_polygon(coordonnee5_x, coordonnee5_y, 4, MLV_COLOR_PURPLE); /* diagonale */
    /* ® */
    MLV_draw_text(613, 33, "®", MLV_COLOR_PURPLE);
}

void afficherContoursEtTextes(){
    MLV_draw_rectangle(250, 150, 300, 600, CONTOURS); /* contour de la grille */
    MLV_draw_rectangle(550, 150, 100, 600, CONTOURS); /* à droite, liste des prochaines pièces et score */
    MLV_draw_rectangle(150, 150, 100, 121, CONTOURS); /* à gauche, réserve */
    
    /* prochaines pièces */
    MLV_draw_text_box(
        550, 150,
        100, 25,
        "NEXT",
        1,
        CONTOURS, MLV_COLOR_BLACK, CONTOURS,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );

    /* score */
    MLV_draw_text_box(
        550, 530,
        100, 25,
        "SCORE",
        1,
        CONTOURS, MLV_COLOR_BLACK, CONTOURS,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    
    /* réserve */
    MLV_draw_text_box(
        150, 150,
        100, 25,
        "RESERVE",
        1,
        CONTOURS, MLV_COLOR_BLACK, CONTOURS,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
}

int afficherScoresPendantPartie(){
    int i = 1;
    int decal_hauteur = 345;
    int decal_largeur = 30;
    char score[10];
    char i_score[15];
    FILE * fichier;
    MLV_draw_text_box(25, 300, 200, 35, "Meilleurs scores", 0, CONTOURS, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_rectangle(25, 334, 200, 115, CONTOURS);
    if ((fichier = fopen("./ressources/scores.txt", "r")) == NULL){
        fichier = fopen("./ressources/scores.txt", "a+");
    }
    while (fscanf(fichier, "%s\n", score) != EOF && i < 11) {
        if (i == 6){
            decal_largeur += 100;
            decal_hauteur = 345;
        }
	snprintf(i_score, sizeof(i_score), "%d", i);
	strcat(i_score, ". ");
        strcat(i_score, score);
	MLV_draw_text(decal_largeur, decal_hauteur, i_score, MLV_COLOR_WHITE);
        i++;
        decal_hauteur += 20;
    }
    fclose(fichier);
    return 1;
}

void afficherScoreActuel(int score) {
    char score_char[7];
    sprintf(score_char, "%d", score);
    MLV_draw_text(560, 560, score_char, MLV_COLOR_WHITE);
}

void afficherPiecesSuivantes(plateau monPlateau) {
    int k, i, j;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (monPlateau.piecesSuivantes[k].idPiece.forme[i][j] == 1) {
                    MLV_draw_filled_rectangle(560 + j*20, 190 + i*20 + k*70, 20, 20, monPlateau.piecesSuivantes[k].idPiece.couleur);
                    MLV_draw_rectangle(560 + j*20, 190 + i*20 + k*70, 20, 20, MLV_COLOR_GREY50);
                }
            }
        }
    }
}

void afficherReserve(plateau monPlateau) {
    int i, j;
    if (monPlateau.reserveOccupee == 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (monPlateau.pieceReserve.idPiece.forme[i][j] == 1) {
                    MLV_draw_filled_rectangle(160 + j*20, 190 + i*20, 20, 20, monPlateau.pieceReserve.idPiece.couleur);
                    MLV_draw_rectangle(160 + j*20, 190 + i*20, 20, 20, MLV_COLOR_GREY50);
                }
            }
        }
    }
}

void actualiserJeu(plateau monPlateau, piece maPiece, int score){
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherPlateau(monPlateau);
    afficherPiece(maPiece);
    /* Permet de cacher les pièces juste au-dessus du plateau : */
    MLV_draw_filled_rectangle(250, 130, 300, 20, MLV_COLOR_BLACK);
    afficherLogo();
    afficherContoursEtTextes();
    afficherScoresPendantPartie();
    afficherPiecesSuivantes(monPlateau);
    afficherReserve(monPlateau);
    afficherScoreActuel(score);
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
