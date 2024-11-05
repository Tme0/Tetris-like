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
    piece maPiece;
    plateau monPlateau;
    int mouvement = 1; /* Permet de savoir si la pièce peut se déplacer (ne touche pas le sol) */
    int frame = 0; /* Permet de compter les frames passées pour gérer la vitesse de chute et attendre quand la pièce est posée pour laisser la possibilité de la déplacer */
    int aBouge = 0; /* Permet d'empecher le déplacement des pièces en restant appuyé */
    int continuer = 1;
    int niveau = 1;
    long int tempsAttente;
    monPlateau = initPlateau(monPlateau);
    maPiece = creerPiece(nbAleatoire(1, 7),niveau);
    MLV_clear_window(MLV_COLOR_BLACK);
    afficherPlateau(monPlateau);
    MLV_actualise_window();
    while (continuer) {
        /*Temps au début l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        frame++;
        
        if (estPosee(maPiece, monPlateau)) {
            mouvement = 0;
            if (frame % 20 == 0) {
                frame = 0;
                monPlateau = majPlateau(maPiece, monPlateau);
                maPiece = creerPiece(nbAleatoire(1, 7),niveau);
                mouvement = 1;
            }
        }
        else {
            mouvement = 1; /* Permet de rendre possible la chute si la pièce est décalée entre le moment ou elle touche le sol et ou elle doit etre remplacée et qu'elle n'est plus posée */
        }

        if (frame % 20 == 0 && mouvement == 1) {
            maPiece.y++;
        }
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, &souris, &etatTouche); /*Bug a corriger : si on appuis sur s à la frame exacte ou la piece est sensée toucher le sol, celle-ci sort du plateau*/
        if (etatTouche == MLV_PRESSED && touche != MLV_KEYBOARD_UNKNOWN && souris == 0) {
            if (aBouge == 0 || touche == MLV_KEYBOARD_s) {
                aBouge = 1;
                if (touche != MLV_KEYBOARD_s) {
                    maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                    touche = MLV_KEYBOARD_UNKNOWN;
                }
                else if (mouvement == 1) {
                    maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                    frame = 0;
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

        MLV_clear_window(MLV_COLOR_DARK_GREY);
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
    int h, l;
    for (h = 0; h < TAILLE_PIECE; h++) {
        for (l = 0; l < TAILLE_PIECE; l++) {
            if (maPiece.idPiece.forme[h][l] == 1) {
                if (maPiece.y + h == monPlateau.hauteur -1) {
                    printf("La pièce est posée\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* Vérifie s'il y a une collision à droite de la pièce */
int colisionDroite(piece maPiece, plateau monPlateau) {
    int i;  /* Déclare une variable pour l'itération */
    for (i = 0 ; i < TAILLE_PIECE ; i++) {  /* Boucle à travers chaque bloc de la pièce */
        if (maPiece.idPiece.forme[i][3] == 1) {  /* Vérifie si le bloc fait partie de la pièce */
            /* Vérifie si le bloc à droite est occupé */
            if (monPlateau.state[maPiece.y] != 0) {
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
    for (i = 0; i < 10; i++) {
        mesScores.score[i] = 0;
    }
    while (fscanf(fichier, "%d\n", &score) != EOF && nb_lignes < 10) {
        nb_lignes++;
        mesScores.score[nb_lignes]=score;
        printf("%d\n", mesScores.score[nb_lignes]);
    }
    fclose(fichier);
    return mesScores;
}

int nbAleatoire(int mi, int ma) {
    return rand() % (ma - mi + 1) + mi;
}