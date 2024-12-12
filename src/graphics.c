/* Ce fichier gère l'affichage des éléments du jeu à l'écran (plateau, pièces et menus).*/

#include "../headers/graphics.h"
#include "../headers/input.h"
#include <MLV/MLV_all.h>
#include <stdio.h>

void initialiserFenetre() {
    MLV_create_window("Tetris", "Tetris", 800, 800);
}

void afficherMenu() { /*Fonctionnel : A rendre beau*/
    int largeurBouton = 400;
    int hauteurBouton = 100;
    int milieu = (800 - largeurBouton) / 2;
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
    MLV_clear_window(MLV_COLOR_BLACK);
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
    int milieu = (800 - largeurBouton) / 2;
    bouton parametresControles = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 6};
    bouton parametresVideo = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 7};
    bouton parametresAudio = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 8};
    bouton retour = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 9};
    char texte_parametres_1[N] = "Controles";
    char texte_parametres_2[N] = "Video";
    char texte_parametres_3[N] = "Audio";
    char texte_parametres_4[N] = "Retour";
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_box(milieu, 100, largeurBouton, hauteurBouton, texte_parametres_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 250, largeurBouton, hauteurBouton, texte_parametres_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 400, largeurBouton, hauteurBouton, texte_parametres_3, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 550, largeurBouton, hauteurBouton, texte_parametres_4, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(4, (bouton[]){parametresControles, parametresVideo, parametresAudio, retour});
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

void afficherScores(scores mesScores) { /*Fonctionnel : A rendre beau*/
    int milieu = (800 - 200) / 2;
    bouton retour = {milieu, milieu + 100, 200, 250, 9};
    char texte_scores_1[N] = "Scores";
    char texte_scores_2[N] = "Retour";
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_box(milieu, 100, 200, 50, texte_scores_1, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(milieu, 200, 200, 50, texte_scores_2, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_actualise_window();
    selection(1, (bouton[]){retour}); /* A corriger : Lorsque le programme recoit un clic il se ferme (le bouton retour fonctionne dans afficherParametres())*/
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
    MLV_draw_rectangle(170, 10, 460, 120, MLV_COLOR_DEEPSKYBLUE); /* contour */
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
    MLV_draw_rectangle(250, 150, 300, 600, MLV_COLOR_DEEPSKYBLUE); /* contour de la grille */
    MLV_draw_rectangle(550, 150, 100, 600, MLV_COLOR_DEEPSKYBLUE); /* à droite, liste des prochaines pièces et score */
    MLV_draw_rectangle(150, 150, 100, 121, MLV_COLOR_DEEPSKYBLUE); /* à gauche, réserve */
    
    /* tentative de mettre des contours plus épais, à voir si on le fait après : */
    /* MLV_draw_filled_rectangle(246, 146, 310, 5, MLV_COLOR_DEEPSKYBLUE); */
    
    /* prochaines pièces */
    MLV_draw_text_box(
        550, 150,
        100, 25,
        "NEXT",
        1,
        MLV_COLOR_DEEPSKYBLUE, MLV_COLOR_BLACK, MLV_COLOR_DEEPSKYBLUE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );

    /* score */
    MLV_draw_text_box(
        550, 530,
        100, 25,
        "SCORE",
        1,
        MLV_COLOR_DEEPSKYBLUE, MLV_COLOR_BLACK, MLV_COLOR_DEEPSKYBLUE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    
    /* réserve */
    MLV_draw_text_box(
        150, 150,
        100, 25,
        "RESERVE",
        1,
        MLV_COLOR_DEEPSKYBLUE, MLV_COLOR_BLACK, MLV_COLOR_DEEPSKYBLUE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
}

int afficherScoresPendantPartie(){
    int i = 1;
    int decal_hauteur = 345;
    int decal_largeur = 30;
    int score;
    char score_char[7];
    char i_char[10];
    FILE * fichier;
    MLV_draw_text_box(25, 300, 200, 35, "Meilleurs scores", 0, MLV_COLOR_DEEPSKYBLUE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_rectangle(25, 334, 200, 115, MLV_COLOR_DEEPSKYBLUE);
    if ((fichier = fopen("./ressources/scores.txt", "r")) == NULL){
        fichier = fopen("./ressources/scores.txt", "a+");
    }
    while ((fscanf(fichier, "%d", &score)) == 1){
        if (i == 6){
            decal_largeur += 100;
            decal_hauteur = 345;
        }
        sprintf(score_char, "%d", score);
        sprintf(i_char, "%d", i);
        strcat(i_char, ". ");
        strcat(i_char, score_char);
        MLV_draw_text(decal_largeur, decal_hauteur, i_char, MLV_COLOR_WHITE);
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
