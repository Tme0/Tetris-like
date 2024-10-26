/* Ce fichier gère les entrées utilisateur.*/

#include "../headers/input.h"
#include <MLV/MLV_all.h>

void selectionParametres() { /* Fonctionnel mais très peu pratique pour changer la disposition du menu (coordonées en dur)*/
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

void selectionMenu() { /* Fonctionnel mais très peu pratique pour changer la disposition du menu (coordonées en dur)*/
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

void selectionSauvegarde() { /* A completer */
    printf("Choix de la sauvegarde...\n");
}

void resoudreEvenement(MLV_Keyboard_button touche) { /* A completer */
    switch (touche) {
        case MLV_KEYBOARD_d:
            /*Déplacer le bloc à droite*/
            break;
        case MLV_KEYBOARD_q:
            /*Déplacer le bloc à gauche*/
            break;
        case MLV_KEYBOARD_s:
            /*Déplacer le bloc vers le bas*/
            break;
        case MLV_KEYBOARD_e:
            /*Faire tourner le bloc à droite*/
            break;
        case MLV_KEYBOARD_a:
            /*Faire tourner le bloc à gauche*/
            break;
        case MLV_KEYBOARD_ESCAPE:
            afficherMenu();
            break;
        default:
            break;
    }
}