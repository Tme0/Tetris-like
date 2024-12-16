/* Ce fichier gère les entrées utilisateur.*/

#include "../headers/types.h"
#include "../headers/input.h"
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include "../headers/save.h"

piece resoudreEvenement(MLV_Keyboard_button touche, piece maPiece, plateau monPlateau) {
    switch (touche) {
        case MLV_KEYBOARD_d:
            if (colisionDroite(maPiece, monPlateau) == 0) {
                maPiece.x++;
            }
            break;
        case MLV_KEYBOARD_q:
            if (colisionGauche(maPiece, monPlateau) == 0) {  
                maPiece.x--;
            }
            break;
        case MLV_KEYBOARD_s:
            maPiece.y++;
            break;
        case MLV_KEYBOARD_e:
	    tournerPieceDroite(&maPiece);
	    /* On va faire croire à la fonction que l'orientation n'a pas changé, comme ça ça va utiliser la bonne kicktable : */
	    maPiece.orientation = (maPiece.orientation + 3) % 4; /* (tournerPieceDroite augmente de 1, ici de 3, donc de 4, donc ça revient à l'orientation de base */
	    if (superRotation(&maPiece, &monPlateau, 1) == 0) {
                maPiece.orientation = (maPiece.orientation + 1) % 4; /* On remet l'orientation à la bonne valeur */
                tournerPieceGauche(&maPiece); /* On remet la pièce dans son état original */
	    }
	    else {
                maPiece.orientation = (maPiece.orientation + 1) % 4; /* On remet l'orientation à la bonne valeur */
	    }
            break;
        case MLV_KEYBOARD_a:
	    tournerPieceGauche(&maPiece);
	    if (superRotation(&maPiece, &monPlateau, -1) == 0) {
                tournerPieceDroite(&maPiece);
	    }
	    /* Alors qu'ici, on fait d'abord la rotation, puis si on voit qu'elle était en fait impossible,
	       alors on l'annule (pour la logique, voir le commentaire de la fonction dans plateau.c) */
            break;
        case MLV_KEYBOARD_SPACE:
	    tomberPiece(&maPiece, &monPlateau);
	    break;
        default:
            break;
    }
    return maPiece;
}

void mettreEnPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherMenuPause(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
}

int selectionMenuPrincipal(int nbBoutons, bouton boutons[BOUTONS]) {
    int x, y, i;
    int quitterJeu = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
            switch (boutons[i].index) {
                case 1:
                    jouer(0);
                    break;
                case 2:
                    afficherMenuCharger();
                    break;
                case 3:
                    afficherMenuScores();
                    break;
                case 4:
                    afficherMenuParametres();
                    break;
                case 5:
                    MLV_free_window();
                    quitterJeu = 1;
                    break;
	        default:
	            break;
            }
        }
    }
    return quitterJeu;
}

void selectionMenuPause(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int x, y, i;
    int dansBouton = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
	    dansBouton = 1;
            switch (boutons[i].index) {
                case 6:
                    break;
                case 7:
                    afficherMenuSauvegarder(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
                case 8:
		    *continuer = 0;
		    afficherMenu();
                    break;
	        default:
	            break;
	    }
	}
    }
    if (dansBouton == 0) { /* Permet de réafficher la fenêtre si on clique en dehors d'un bouton */
        afficherMenuPause(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
    }
}

void selectionMenuSauvegarder(int nbBoutons, bouton boutons[BOUTONS], plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *aBouge, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int x, y, i;
    int dansBouton = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
	    dansBouton = 1;
            switch (boutons[i].index) {
                case 9:
		    sauvegarderSave("./saves/save1.bin", monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
                case 10:
		    sauvegarderSave("./saves/save2.bin", monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
                case 11:
		    sauvegarderSave("./saves/save3.bin", monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
		case 12:
		    sauvegarderSave("./saves/save4.bin", monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
		case 13:
		    mettreEnPause(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
                    break;
	        default:
		    break;
	    }
	}
    }
    if (dansBouton == 0) { /* Permet de réafficher la fenêtre si on clique en dehors d'un bouton */
        afficherMenuSauvegarder(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
    }
    else{
        afficherMenuPause(monPlateau, maPiece, mouvementVertical, frame, aBouge, continuer, niveau, score, reserveUtilisee, hardDrop);
    }
}

void selectionMenuCharger(int nbBoutons, bouton boutons[BOUTONS]) {
    int x, y, i;
    int dansBouton = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
	    dansBouton = 1;
            switch (boutons[i].index) {
	        case 14:
	            jouer(1);
	            break;
	        case 15:
	            jouer(2);
	            break;
	        case 16:
	            jouer(3);
	            break;
	        case 17:
	            jouer(4);
	            break;
	        case 18:
	            afficherMenu();
	            break;
	        default:
		    break;
	    }
	}
    }
    if (dansBouton == 0) { /* Permet de réafficher la fenêtre si on clique en dehors d'un bouton */
        afficherMenuCharger();
    }
}

void selectionMenuScores(bouton retour) {
    int x, y;
    int dansBouton = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    if (x >= retour.x_min && x <= retour.x_max &&
        y >= retour.y_min && y <= retour.y_max) {
        MLV_clear_window(MLV_COLOR_BLACK);
	dansBouton = 1;
        afficherMenu();
    }
    if (dansBouton == 0) { /* Permet de réafficher la fenêtre si on clique en dehors d'un bouton */
        afficherMenuScores();
    }
}


void selectionMenuParametres(int nbBoutons, bouton boutons[BOUTONS]) {
    int x, y, i;
    int dansBouton = 0;
    MLV_wait_mouse(&x, &y);
    printf("x = %d, y = %d\n", x, y); 
    for (i = 0; i < nbBoutons; i++) {
        printf ("x_min = %d, x_max = %d, y_min = %d, y_max = %d\n", boutons[i].x_min, boutons[i].x_max, boutons[i].y_min, boutons[i].y_max);
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
            MLV_clear_window(MLV_COLOR_BLACK);
	    dansBouton = 1;
            switch (boutons[i].index) {
	        case 20:
	            afficherParametresControles();
	            break;
	        case 21:
		    afficherParametresVideo();
		    break;
	        case 22:
	            afficherParametresAudio();
	            break;
	        case 23:
	            afficherMenu();
	            break;
	        default:
		    break;
	    }
	}
    }
    if (dansBouton == 0) { /* Permet de réafficher la fenêtre si on clique en dehors d'un bouton */
        afficherMenuParametres();
    }
}
