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
        case MLV_KEYBOARD_RIGHT:
            if (colisionDroite(maPiece, monPlateau) == 0) {
                maPiece.x++;
            }
            break;
        case MLV_KEYBOARD_LEFT:
            if (colisionGauche(maPiece, monPlateau) == 0) {  
                maPiece.x--;
            }
            break;
        case MLV_KEYBOARD_DOWN:
            maPiece.y++;
            break;
        case MLV_KEYBOARD_d:
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
        case MLV_KEYBOARD_q:
	    tournerPieceGauche(&maPiece);
	    if (superRotation(&maPiece, &monPlateau, -1) == 0) {
                tournerPieceDroite(&maPiece);
	    }
	    /* Alors qu'ici, on fait d'abord la rotation, puis si on voit qu'elle était en fait impossible,
	       alors on l'annule (pour la logique, voir le commentaire de la fonction dans plateau.c) */
            break;
        case MLV_KEYBOARD_SPACE:
	    tomberPiece(&maPiece, &monPlateau); /* Drop instantané de la pièce */
	    break;
        default:
            break;
    }
    return maPiece;
}

int selectionMenuPrincipal() {
    int x, y, i;
    int menuActif = 1;
    int boutonClic = 0;
    int nbBoutons = 5;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    bouton nouvellePartie = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 1};
    bouton chargerPartie = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 2};
    bouton scores = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 3};
    bouton parametres = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 4};
    bouton quitter = {milieu, 700, milieu + largeurBouton, 700 + hauteurBouton, 5};
    bouton boutons[BOUTONS];
    boutons[0] = nouvellePartie;
    boutons[1] = chargerPartie;
    boutons[2] = scores;
    boutons[3] = parametres;
    boutons[4] = quitter;
    
    while (menuActif == 1) {
      afficherMenuPrincipal();
      MLV_wait_mouse(&x, &y);
      for (i = 0; i < nbBoutons; i++) {
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
	    boutonClic = boutons[i].index;
	    switch (boutonClic) {
	      case 1:
		jouer(0);
		break;
	      case 2:
	        selectionMenuCharger();
		break;
	      case 3:
	        selectionMenuScores();
		break;
	      case 4:
	        selectionMenuParametres();
		break;
	      case 5:
		MLV_free_window();
		menuActif = 0;
		break;
	    }
    	}
      }
    }
    return menuActif;
}

void selectionMenuPause(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int x, y, i;
    int boutonClic = 0;
    int retourFait = 0;
    int nbBoutons = 3;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    bouton reprendrePartie = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 6};
    bouton sauvegarderPartie = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 7};
    bouton menuPrincipal = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 8};
    bouton boutons[BOUTONS];
    boutons[0] = reprendrePartie;
    boutons[1] = sauvegarderPartie;
    boutons[2] = menuPrincipal;
    
    while (retourFait == 0) {  
      afficherMenuPause();
      MLV_wait_mouse(&x, &y);
      for (i = 0; i < nbBoutons; i++) {
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
	    boutonClic = boutons[i].index;
	    switch (boutonClic) {
	      case 6:
		retourFait = 1;
	        break;
	      case 7:
	        selectionMenuSauvegarder(monPlateau, maPiece, mouvementVertical, frame, continuer, niveau, score, reserveUtilisee, hardDrop);
	        break;
	      case 8:
	        *continuer = 0; /* Permet d'arrêter la partie en cours */
		*score = 0; /* Permet d'éviter d'enregistrer le score lorsqu'on quitte, pour éviter de dupliquer des scores en quittant plusieurs fois la même save */
		retourFait = 1;
	        break;
	    }
    	}
      }
    }
}

void selectionMenuSauvegarder(plateau *monPlateau, piece *maPiece, int *mouvementVertical, int *frame, int *continuer, int *niveau, int *score, int *reserveUtilisee, int *hardDrop) {
    int x, y, i;
    int boutonClic = 0;
    int retourFait = 0;
    int nbBoutons = 5;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    bouton sauvegarde1 = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 9};
    bouton sauvegarde2 = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 10};
    bouton sauvegarde3 = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 11};
    bouton sauvegarde4 = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 12};
    bouton retour = {milieu, 700, milieu + largeurBouton, 700 + hauteurBouton, 13};
    bouton boutons[BOUTONS];
    boutons[0] = sauvegarde1;
    boutons[1] = sauvegarde2;
    boutons[2] = sauvegarde3;
    boutons[3] = sauvegarde4;
    boutons[4] = retour;
    
    while (retourFait == 0) {  
      afficherMenuSauvegarder();
      MLV_wait_mouse(&x, &y);
      for (i = 0; i < nbBoutons; i++) {
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
	    boutonClic = boutons[i].index;
	    switch (boutonClic) {
	      case 9:
	        sauvegarderSave("./ressources/save1.bin", monPlateau, maPiece, mouvementVertical, frame, continuer, niveau, score, reserveUtilisee, hardDrop);
	        break;
	      case 10:
		sauvegarderSave("./ressources/save2.bin", monPlateau, maPiece, mouvementVertical, frame, continuer, niveau, score, reserveUtilisee, hardDrop);
		break;
	      case 11:
		sauvegarderSave("./ressources/save3.bin", monPlateau, maPiece, mouvementVertical, frame, continuer, niveau, score, reserveUtilisee, hardDrop);
		break;
	      case 12:
		sauvegarderSave("./ressources/save4.bin", monPlateau, maPiece, mouvementVertical, frame, continuer, niveau, score, reserveUtilisee, hardDrop);
		break;
	      case 13:
		retourFait = 1;
	        break;
	    }
    	}
      }
    }
}

void selectionMenuCharger() {
    int x, y, i;
    int boutonClic = 0;
    int retourFait = 0;
    int nbBoutons = 5;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    bouton sauvegarde1 = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 14};
    bouton sauvegarde2 = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 15};
    bouton sauvegarde3 = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 16};
    bouton sauvegarde4 = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 17};
    bouton retour = {milieu, 700, milieu + largeurBouton, 700 + hauteurBouton, 18};
    bouton boutons[BOUTONS];
    boutons[0] = sauvegarde1;
    boutons[1] = sauvegarde2;
    boutons[2] = sauvegarde3;
    boutons[3] = sauvegarde4;
    boutons[4] = retour;
    
    while (retourFait == 0) {  
      afficherMenuCharger();
      MLV_wait_mouse(&x, &y);
      for (i = 0; i < nbBoutons; i++) {
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
	    boutonClic = boutons[i].index;
	    switch (boutonClic) {
	      case 14:
		if (jouer(1) != -1){ /* Permet de rester sur le menu si la sauvegarde 1 n'existe pas (retourFait est mis à 1 si la partie a vraiment été faite) */
		    retourFait = 1;
		}
		break;
	      case 15:
		if (jouer(2) != -1){ /* Permet de rester sur le menu si la sauvegarde 2 n'existe pas (retourFait est mis à 1 si la partie a vraiment été faite) */
		    retourFait = 1;
		}
		break;
	      case 16:
		if (jouer(3) != -1){ /* Permet de rester sur le menu si la sauvegarde 3 n'existe pas (retourFait est mis à 1 si la partie a vraiment été faite) */
		    retourFait = 1;
		}
		break;
	      case 17:
		if (jouer(4) != -1){ /* Permet de rester sur le menu si la sauvegarde 4 n'existe pas (retourFait est mis à 1 si la partie a vraiment été faite) */
		    retourFait = 1;
		}
		break;
	      case 18:
		retourFait = 1;
		break;
	    }
    	}
      }
    }
}

void selectionMenuScores() {
    int x, y;
    int boutonClic = 0;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    const bouton retour = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 19};
    while (boutonClic == 0) {
      afficherMenuScores();
      MLV_wait_mouse(&x, &y);
      if (x >= retour.x_min && x <= retour.x_max &&
	  y >= retour.y_min && y <= retour.y_max) {
	boutonClic = retour.index;
      }
    }
}


void selectionMenuParametres() {
    int x, y, i;
    int boutonClic = 0;
    int retourFait = 0;
    int nbBoutons = 4;
    const int largeurBouton = 400;
    const int hauteurBouton = 100;
    const int milieu = (800 - largeurBouton) / 2;
    bouton parametresControles = {milieu, 100, milieu + largeurBouton, 100 + hauteurBouton, 20};
    bouton parametresVideo = {milieu, 250, milieu + largeurBouton, 250 + hauteurBouton, 21};
    bouton parametresAudio = {milieu, 400, milieu + largeurBouton, 400 + hauteurBouton, 22};
    bouton retour = {milieu, 550, milieu + largeurBouton, 550 + hauteurBouton, 23};
    bouton boutons[BOUTONS];
    boutons[0] = parametresControles;
    boutons[1] = parametresVideo;
    boutons[2] = parametresAudio;
    boutons[3] = retour;
    
    while (retourFait == 0) {
      afficherMenuParametres();
      MLV_wait_mouse(&x, &y);
      for (i = 0; i < nbBoutons; i++) {
        if (x >= boutons[i].x_min && x <= boutons[i].x_max &&
            y >= boutons[i].y_min && y <= boutons[i].y_max) {
	    boutonClic = boutons[i].index;
	    switch (boutonClic) {
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
		retourFait = 1;
		break;
	    }
    	}
      }
    }
}
