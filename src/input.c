/* Ce fichier gère les entrées utilisateur.*/

#include "../headers/input.h"
#include "../headers/graphics.h"
#include "../headers/game.h"
#include "../headers/piece.h"
/*#include <MLV/MLV_all.h> déjà inclus dans input.h*/
/*#define BOUNTONS 9 déjà définis dans input.h*/
/*
void selectionParametres() { / * Fonctionnel mais très peu pratique pour changer la disposition du menu (coordonées en dur)* /
    int x, y;
    MLV_wait_mouse(&x, &y);
    if (x >= 100 && x <= 300 && y >= 100 && y <= 150) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherParametresControles();
    } else if (x >= 100 && x <= 300 && y >= 200 && y <= 250) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherParametresVideo();
    } else if (x >= 100 && x <= 300 && y >= 300 && y <= 350) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherParametresAudio();
    } else if (x >= 100 && x <= 300 && y >= 400 && y <= 450) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherMenu();
    }
    else {
        selectionParametres();
    }
}
*/
/*
void selectionMenu() { / * Fonctionnel mais très peu pratique pour changer la disposition du menu (coordonées en dur)* /
    int x, y;
    MLV_wait_mouse(&x, &y);
    if (x >= 100 && x <= 300 && y >= 100 && y <= 150) {
        jouer();
    } else if (x >= 100 && x <= 300 && y >= 200 && y <= 250) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherSauvegarde();
    } else if (x >= 100 && x <= 300 && y >= 300 && y <= 350) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherScores(recupererScores());
    } else if (x >= 100 && x <= 300 && y >= 400 && y <= 450) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherParametres();
    } else if (x >= 100 && x <= 300 && y >= 500 && y <= 550) {
        MLV_free_window();
        exit(EXIT_SUCCESS);
    }
    else {
        selectionMenu();
    }
}
*/

void selectionSauvegarde() { /* A completer */
    printf("Choix de la sauvegarde...\n");
}

piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau) { /* A completer */
    switch (touche) {
        case MLV_KEYBOARD_d:
            if (colisionDroite(maPiece, monPlateau) == 0) {
                maPiece.x++;
            }
            return maPiece;
        case MLV_KEYBOARD_q:
            if (colisionGauche(maPiece, monPlateau) == 0) {  
                maPiece.x--;
            }
            return maPiece;
        case MLV_KEYBOARD_s:
            maPiece.y++;
            return maPiece;
        case MLV_KEYBOARD_e:
            /*Faire tourner le bloc à droite*/
            return maPiece;
        case MLV_KEYBOARD_a:
            /*Faire tourner le bloc à gauche*/
            return maPiece;
        case MLV_KEYBOARD_ESCAPE:
            MLV_clear_window(MLV_COLOR_BLACK);
            afficherMenu();
            return maPiece;
        default:
            return maPiece;
    }
}
/*
void selectionScores() { / * Fonctionnel mais très peu pratique pour changer la disposition du menu (coordonées en dur)* /
    int x, y;
    MLV_wait_mouse(&x, &y);
    if (x >= (1920 - 200) / 2 && x <= (1920 - 200) / 2 + 200 && y >= 200 && y <= 250) {
        MLV_clear_window(MLV_COLOR_BLACK);
        afficherMenu();
    }
    else {
        selectionScores();
    }
}
*/




void selection(int nbBoutons, bouton boutons[BOUNTONS]) {
    int x, y, i;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
            switch (boutons[i].index) {
                case 1:
                    jouer();
                    break;
                case 2:
                    afficherSauvegarde();
                    break;
                case 3:
                    afficherScores(recupererScores());
                    break;
                case 4:
                    afficherParametres();
                    break;
                case 5:
                    MLV_free_window();
                    exit(EXIT_SUCCESS);
                    break;
                case 6:
                    afficherParametresControles();
                    break;
                case 7:
                    afficherParametresVideo();
                    break;
                case 8:
                    afficherParametresAudio();
                    break;
                case 9:
                    afficherMenu();
                    break;
                default:
                    break;
            }
        }
    }
}
