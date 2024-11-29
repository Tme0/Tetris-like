/* Ce fichier gère la logique principale du jeu.*/

#include <time.h>
#include <MLV/MLV_all.h>
#include "../headers/game.h"
#include "../headers/input.h"
#include "../headers/graphics.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"

void menu(int menuActif) {
    while (menuActif != 0) {
        afficherMenu();
    }
}

int jouer() {
    struct timespec debut, fin;
    
    MLV_Keyboard_button touche;
    MLV_Button_state etatTouche;
    MLV_Mouse_button souris;
    
    piece maPiece;
    plateau monPlateau;
    int i, j;
    int mouvementVertical = 1; /* Permet de savoir si la pièce peut se déplacer (ne touche pas le sol) */
    int frame = 0; /* Permet de compter les frames passées pour gérer la vitesse de chute et attendre quand la pièce est posée pour laisser la possibilité de la déplacer */
    int aBouge = 0; /* Permet d'empecher le déplacement des pièces en restant appuyé */
    int continuer = 1; /* Permet de savoir si le jeu est en cours */
    int niveau = 1; /* Permet de gérer la vitesse de chute des pièces */
    int score = 0;
    int combo;
    int idLigneComplete;
    long int tempsAttente;
    
    maPiece = creerPiece(nbAleatoire(1, 7));
    monPlateau = initialiserPlateau(monPlateau);
    
    while (score < 999999 && continuer == 1) {
        /*Temps au début de l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        frame++;

	fixPlateau(&monPlateau);
	
	if (estPosee(maPiece, monPlateau)) {
	  mouvementVertical = 0;
	  if (frame % (20/niveau) == 0) {
	    frame = 0;
	    majPlateau(maPiece, &monPlateau);
	    combo = 1;
	    for (i = 0 ; i < 20 ; i++){
	      for (j = 0 ; j < 10 ; j++){
		printf("%d ", monPlateau.state[i][j]);
	      }
	      printf("\n");
	    }
	    printf("\n");
	    idLigneComplete = ligneComplete(monPlateau);
	    while (idLigneComplete >= 0) {
	      supprimerLigne(&monPlateau, idLigneComplete);
	      score += 100*combo*niveau;
	      combo++;
	      idLigneComplete = ligneComplete(monPlateau);
	    }
	    maPiece = creerPiece(nbAleatoire(1, 7));
	    mouvementVertical = 1;
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
	  if (aBouge == 0 || touche == MLV_KEYBOARD_s) {
	    aBouge = 1;
	    if (touche != MLV_KEYBOARD_s){
	      maPiece = resoudreEvenement(touche, maPiece, monPlateau);
	      touche = MLV_KEYBOARD_UNKNOWN;
	    }
	    else{
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
            aBouge = 0;
        }

        /* MLV_clear_window(MLV_COLOR_BLACK); */
        afficherPlateau(monPlateau);
        afficherPiece(maPiece);
        afficherLogo();
        afficherContoursEtTextes();
        afficherScoresPendantPartie();

        /*Temps à la fin de l'image et boucle while pour completer le temps manquant (60/1 sec)*/
        clock_gettime(CLOCK_REALTIME, &fin );
        tempsAttente = 16 - (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;
        if (tempsAttente > 0) {
            MLV_wait_milliseconds(tempsAttente);
        }
        else{
            printf("%ld ", tempsAttente);
        }
        MLV_actualise_window();
    }
    return 0;
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
                if (j + maPiece.x == 9){
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
                if (j + maPiece.x == 0){
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

scores recupererScores() {
    scores mesScores;
    int score, i;
    int nb_lignes = 0;
    FILE *fichier;
    fichier = fopen("./ressources/scores.txt", "r");
    if (fichier == NULL) {
        printf("Création du fichier scores.txt\n");
        fichier = fopen("./ressources/scores.txt", "a+");
    }
    while (fscanf(fichier, "%d\n", &score) != EOF && nb_lignes < 10) {
        nb_lignes++;
        mesScores.score[nb_lignes]=score;
        printf("%d\n", mesScores.score[nb_lignes]);
    }
    for (i = 0 ; i < nb_lignes ; i++) {
        MLV_draw_text(100, 100 + 50 * i, "%d", mesScores.score[i]);
    }
    fclose(fichier);
    return mesScores;
}

int nbAleatoire(int mi, int ma) {
    return rand() % (ma - mi + 1) + mi;
}
