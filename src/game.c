/* Ce fichier gère la logique principale du jeu.*/

#include <time.h>
#include "../headers/types.h"
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include "../headers/save.h"

int menu(int menuActif) {
    while (menuActif != 0) {
        menuActif = selectionMenuPrincipal();
    }
    return 0;
}

int jouer(int save) {
    /* On lance le jeu avec 0 sans save, sinon avec 1, 2, 3 ou 4 */
    struct timespec debut, fin;
    
    MLV_Keyboard_button touche;
    MLV_Button_state etatTouche;
    MLV_Mouse_button souris;
    
    piece maPiece;
    plateau monPlateau;
    int mouvementVertical; /* Permet de savoir si la pièce peut se déplacer (ne touche pas le sol) */
    int frame; /* Permet de compter les frames passées pour gérer la vitesse de chute et attendre quand la pièce est posée pour laisser la possibilité de la déplacer */
    int continuer; /* Permet de savoir si le jeu est en cours */
    int niveau; /* Permet de gérer la vitesse de chute des pièces */
    int score;
    int combo; /* Permet de gérer le nombre de lignes détruites en un seul coup, et gérer le score en fonction */
    int idLigneComplete;
    int reserveUtilisee; /* Permet de savoir si la réserve a été utilisée pendant le tour, car on peut l'utiliser une seule fois par tour */
    int hardDrop; /* Permet de savoir si on a "hard drop" (touche espace) et d'empêcher une autre action */
    long int tempsAttente;

    char nom_save[23];

    if (save == 1) {
        strcpy(nom_save, "./ressources/save1.bin");
    }
    if (save == 2) {
        strcpy(nom_save, "./ressources/save2.bin");
    }
    if (save == 3) {
        strcpy(nom_save, "./ressources/save3.bin");
    }
    if (save == 4) {
        strcpy(nom_save, "./ressources/save4.bin");
    }
    
    maPiece = creerPiece(nbAleatoire(1, 7));
    monPlateau = initialiserPlateau(monPlateau);

    if (save != 0) {
        if (chargerSave(nom_save, &monPlateau, &maPiece, &mouvementVertical, &frame, &continuer, &niveau, &score, &reserveUtilisee, &hardDrop) != 1){
	    return -1;
        }
    }
    else{
        mouvementVertical = 1;
        frame = 0;
	continuer = 1;
	niveau = 1;
	score = 0;
	reserveUtilisee = 0;
	hardDrop = 0;
    }
    
    while (score < 999999 && continuer == 1) {
        /*Temps au début de l'image*/
        clock_gettime(CLOCK_REALTIME, &debut);
        frame++;

	fixPlateau(&monPlateau); /* Permet de corriger des valeurs autres que 0 et 1 qui se mettent parfois dans le plateau */
	
	if (estPosee(maPiece, monPlateau)) {
            mouvementVertical = 0;
            if (finJeu(maPiece) == 1) {
                continuer = 0;
            }
            if (frame % 20 == 0 || hardDrop == 1) { /* J'ai enlevé le frame % (20/niveau) pour garder le même temps d'attente avant de bloquer la pièce, même quand le niveau change */
                frame = 0;
                hardDrop = 0;
                majPlateau(maPiece, &monPlateau);
                combo = 0;
                idLigneComplete = ligneComplete(monPlateau);
                while (idLigneComplete >= 0) {
                    supprimerLigne(&monPlateau, idLigneComplete);
                    combo++;
                    idLigneComplete = ligneComplete(monPlateau);
                }
                if (combo == 4) {
                    score += 600; /* Un TETRIS rapporte plus de points */
                }
                else {
                    score += 100*combo*niveau;
                }
                majPiecesSuivantes(&maPiece, &monPlateau);
                mouvementVertical = 1;
                reserveUtilisee = 0;
                if (niveau < 8) {
                    niveau = 1 + score/5000; /* Augmente la vitesse de chute des pièces jusqu'au niveau 8 */
                }
            }
	}
	else {
            mouvementVertical = 1; /* Permet de rendre possible la chute si la pièce est décalée entre le moment où elle touche le sol et ou elle doit être remplacée et qu'elle n'est plus posée */
	}

        if (frame % (20/niveau) == 0 && mouvementVertical == 1) {
            majApresChute(maPiece, &monPlateau);
            maPiece.y++;
        }
        
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, &souris, &etatTouche); 
        if (etatTouche == MLV_PRESSED && touche != MLV_KEYBOARD_UNKNOWN && souris == 0) {
	    if (touche == MLV_KEYBOARD_ESCAPE) {
		selectionMenuPause(&monPlateau, &maPiece, &mouvementVertical, &frame, &continuer, &niveau, &score, &reserveUtilisee, &hardDrop);
	    }
            if (touche == MLV_KEYBOARD_SPACE) { /* On met hardDrop à 1 pour indiquer qu'on l'a utilisé */
                hardDrop = 1;
            }
            if (touche != MLV_KEYBOARD_DOWN && touche != MLV_KEYBOARD_z) {
                maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                touche = MLV_KEYBOARD_UNKNOWN;
            }
            else{
                if (touche == MLV_KEYBOARD_z) {
                    if (reserveUtilisee == 0) {
                        mettreEnReserve(&maPiece, &monPlateau);
                        reserveUtilisee = 1; /* On met reserveUtilisee à 1 pour indiquer qu'on l'a utilisée */
                    }
                }
                else {
                    if (mouvementVertical == 1) {
                        maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                        frame = 0;
                    }
                }
            }
        }
        
        if (etatTouche == MLV_RELEASED) {
            switch (souris) {
            case MLV_BUTTON_LEFT:{
                souris = 0;                     
            }
                break;
            case MLV_BUTTON_RIGHT:{
                souris = 0;
            }
                break;
            case MLV_BUTTON_MIDDLE:{
                souris = 0;
            }
            default:
                break;
            }
        }

        clock_gettime(CLOCK_REALTIME, &fin);
        tempsAttente = 16 - (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;
        if (tempsAttente > 0) {
            MLV_wait_milliseconds(tempsAttente);
        }
        else{
            printf("Temps attente : %ld\n", tempsAttente);
        }

	if (continuer == 1) { /* Permet de ne pas réafficher la fenêtre un bref instant quand on clique sur menu principal */
	    actualiserJeu(monPlateau, maPiece, score);
            MLV_actualise_window();
	}
    }
    if (score != 0) {
        sauvegarderScore(score);
    }
    return score;
}

int estPosee(piece maPiece, plateau monPlateau) {
    int i, j;
    for (i = TAILLE_PIECE - 1 ; i >= 0 ; i--) { /* Boucle en partant du bas */
        for (j = 0 ; j < TAILLE_PIECE ; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                if (i + maPiece.y == 19){ /* Vérifie si la pièce est en bas du plateau */
                    return 1;
                }
                if (monPlateau.state[maPiece.y + i + 1][maPiece.x + j] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* Vérifie s'il y a une collision à droite de la pièce */
int colisionDroite(piece maPiece, plateau monPlateau) {
    int i, j;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        for (j = TAILLE_PIECE - 1 ; j >= 0 ; j--) { /* Boucle en partant de la droite */
            if (maPiece.idPiece.forme[i][j] == 1) {  /* Vérifie si le bloc fait partie de la pièce */
                if (j + maPiece.x == 9) {
                    return 1;
                }
                /* Vérifie si le bloc à droite est occupé */
                if (monPlateau.state[maPiece.y + i][maPiece.x + j + 1] == 1) {
                    return 1;  /* Retourne 1 s'il y a une collision */
                }
            }
        }
    }
    return 0;  /* Retourne 0 s'il n'y a pas de collision */
}

int colisionGauche(piece maPiece, plateau monPlateau) {
    int i, j;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        for (j = 0 ; j < TAILLE_PIECE ; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                if (j + maPiece.x == 0) {
                    return 1;
                }
                /* Vérifie si le bloc à gauche est occupé */
                if (monPlateau.state[maPiece.y + i][maPiece.x + j - 1] == 1) {
                    return 1;  /* Retourne 1 s'il y a une collision */
                }
            }
        }
    }
    return 0;  /* Retourne 0 s'il n'y a pas de collision */
}

void tomberPiece(piece *maPiece, plateau *monPlateau) {
    int posee;
    posee = 0;
    while (posee == 0) {
        if (estPosee(*maPiece, *monPlateau) == 1) {
            posee = 1;
            maPiece->y--; /* pour éviter d'aller un cran trop bas */
        }
        maPiece->y++;
    }
}

int finJeu(piece maPiece) {
    int i, j;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        for (j = 0 ; j < TAILLE_PIECE ; j++) {
            if (maPiece.idPiece.forme[i][j] == 1) {
                if (i + maPiece.y < 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
