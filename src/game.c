/* Ce fichier gère la logique principale du jeu.*/

#include <time.h>
#include "../headers/game.h"
#include <MLV/MLV_all.h>
#include "../headers/input.h"
#include "../headers/graphics.h"
#include "../headers/piece.h"


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
    piece maPiece = creerPiece(nbAleatoire(1, 7), 1);
    plateau monPlateau;
    int frame = 0;
    int aBouge = 0;
    int continuer = 1;
    int niveau = 1;
    long int tempsAttente;
    monPlateau = initPlateau(monPlateau);
    afficherPlateau(monPlateau);
    MLV_clear_window(MLV_COLOR_BLACK);
    while (continuer) {
        /*Temps au début l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        frame++;
        
        if (frame % 20 == 0) {
            maPiece.y++;
        }
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, &souris, &etatTouche); 
        if (etatTouche == MLV_PRESSED && touche != MLV_KEYBOARD_UNKNOWN && souris == 0) {
            if (aBouge == 0  || touche == MLV_KEYBOARD_s) {
                maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                touche = MLV_KEYBOARD_UNKNOWN;
                aBouge = 1;
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
            }
            aBouge = 0;
        }

        MLV_clear_window(MLV_COLOR_DARK_GREY);

        if (estPosee(maPiece, monPlateau)) {
            majPlateau(maPiece, &monPlateau);
            maPiece = creerPiece(nbAleatoire(1, 7),niveau);
            
        }

        afficherPlateau(monPlateau);
        afficherPiece(maPiece);

        /*Temps à la fin de l'image et boucle while pour completer le temps manquant (60/1 sec)*/
        clock_gettime(CLOCK_REALTIME, &fin );
        tempsAttente = 16 - (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;
        if (tempsAttente > 0) {
            MLV_wait_milliseconds(tempsAttente);
        }
        MLV_actualise_window();
    }
    return 0;
}

int estPosee(piece maPiece, plateau monPlateau) {
    int i;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        if (maPiece.idPiece.forme[i] == 1) {
            if (monPlateau.state[maPiece.y * monPlateau.largeur + maPiece.x + i % 4 + i / 4 * monPlateau.largeur] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

/* Vérifie s'il y a une collision à droite de la pièce */
int colisionDroite(piece maPiece, plateau monPlateau) {
    int i;  /* Déclare une variable pour l'itération */
    for (i = 0 ; i < TAILLE_PIECE ; i++) {  /* Boucle à travers chaque bloc de la pièce */
        if (maPiece.idPiece.forme[i] == 1) {  /* Vérifie si le bloc fait partie de la pièce */
            /* Vérifie si le bloc à droite est occupé */
            if (monPlateau.state[maPiece.y * monPlateau.largeur + maPiece.x + i % 4 + i / 4 + 1] != 0) {
                return 1;  /* Retourne 1 s'il y a une collision */
            }
        }
    }
    return 0;  /* Retourne 0 s'il n'y a pas de collision */
}

int colisionGauche(piece maPiece, plateau monPlateau) {
    int i;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        if (maPiece.idPiece.forme[i] == 1) {
            /* Vérifie si le bloc à gauche est occupé */
            if (monPlateau.state[maPiece.y * monPlateau.largeur + maPiece.x + i % 4 + i / 4 - 1] != 0) {
                return 1;  /* Retourne 1 s'il y a une collision */
            }
        }
    }
    return 0;  /* Retourne 0 s'il n'y a pas de collision */
}

void majPlateau(piece maPiece, plateau *monPlateau) {
    int i;
    for (i = 0 ; i < TAILLE_PIECE ; i++) {
        if (maPiece.idPiece.forme[i] == 1) {
            monPlateau->state[maPiece.y * monPlateau->largeur + maPiece.x + i % 4 + i / 4 * monPlateau->largeur -1] = 1;
            monPlateau->couleur[maPiece.y * monPlateau->largeur + maPiece.x + i % 4 + i / 4 * monPlateau->largeur] = maPiece.idPiece.couleur;
        }
    }
    return ;
}

plateau initPlateau(plateau monPlateau) {
    int i;
    for (i = 0 ; i < 10 * 20 ; i++) {
        monPlateau.state[i] = 0;
        monPlateau.couleur[i] = MLV_COLOR_BLUE;
    }
    monPlateau.x = 0;
    monPlateau.y = 0;
    monPlateau.largeur = 10;
    monPlateau.hauteur = 20;
    return monPlateau;
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