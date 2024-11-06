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

    int h, l;

    struct timespec debut, fin;
    MLV_Keyboard_button touche;
    MLV_Button_state etatTouche;
    MLV_Mouse_button souris;
    piece maPiece;
    plateau monPlateau;
    int mouvementVertical = 1; /* Permet de savoir si la pièce peut se déplacer (ne touche pas le sol) */
    int frame = 0; /* Permet de compter les frames passées pour gérer la vitesse de chute et attendre quand la pièce est posée pour laisser la possibilité de la déplacer */
    int aBouge = 0; /* Permet d'empecher le déplacement des pièces en restant appuyé */
    int continuer = 1; /* Permet de savoir si le jeu est en cours */
    int niveau = 1; /* Permet de gérer la vitesse de chute des pièces */
    int score = 0; 
    int combo, idLigneComplete;
    long int tempsAttente;
    char charScore[SCORE_MAX];
    monPlateau = initPlateau(monPlateau);
    maPiece = creerPiece(nbAleatoire(1, NB_PIECES));
    MLV_clear_window(MLV_COLOR_DARK_GREY);
    while (score < 9999999999 && continuer == 1) {
        /*Temps au début l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        frame++;
        if (estPosee(maPiece, monPlateau)) {
            mouvementVertical = 0;
            if (frame % (20/niveau) == 0) {
                frame = 0;
                monPlateau = majPlateau(maPiece, monPlateau);
                combo = 1;
                idLigneComplete = ligneComplete(monPlateau);
                while (idLigneComplete >= 0) { /*Bug : buffer overflow lorsqu'une ligne est pleine*/
                    monPlateau = supprimerLigne(monPlateau, idLigneComplete);
                    score += 100*combo*niveau;
                    combo++;
                    idLigneComplete = ligneComplete(monPlateau);
                    printf("idLigneComplete = %d\n", idLigneComplete);
                    printf("État du plateau après suppression de la ligne %d :\n", idLigneComplete);
                    for (h = 0; h < monPlateau.hauteur; h++) {
                        for (l = 0; l < monPlateau.largeur; l++) {
                            printf("%d ", monPlateau.state[l][h]);
                        }
                        printf("\n");
                    }
                }
                maPiece = creerPiece(nbAleatoire(1, NB_PIECES));
                mouvementVertical = 1;
            }
        }
        else {
            mouvementVertical = 1; /* Permet de rendre possible la chute si la pièce est décalée entre le moment ou elle touche le sol et ou elle doit etre remplacée et qu'elle n'est plus posée */
        }
        if (frame % (20/niveau) == 0 && mouvementVertical == 1) {
            maPiece.y++;
        }
        MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, &souris, &etatTouche); /*Bug a corriger : si on appuis sur s à la frame exacte ou la piece est sensée toucher le sol, celle-ci passe à travers le sol*/
        if (etatTouche == MLV_PRESSED && touche != MLV_KEYBOARD_UNKNOWN && souris == 0) {
            if (aBouge == 0 || touche == MLV_KEYBOARD_s) {
                aBouge = 1;
                if (touche != MLV_KEYBOARD_s) {
                    maPiece = resoudreEvenement(touche, maPiece, monPlateau);
                    touche = MLV_KEYBOARD_UNKNOWN;
                }
                else if (mouvementVertical == 1) {
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
        sprintf(charScore, "Score : %d", score);
        MLV_draw_text_box(100, 100, 200, 50, charScore, 0, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);


        /*Temps à la fin de l'image et boucle while pour completer le temps manquant (60/1 sec)*/
        clock_gettime(CLOCK_REALTIME, &fin );
        tempsAttente = 16 - (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;
        if (tempsAttente > 0) {
            MLV_wait_milliseconds(tempsAttente);
        }
        MLV_actualise_window();
    }
    return score;
}

int estPosee(piece maPiece, plateau monPlateau) {
    int h, l;
    for (h = 0; h < TAILLE_PIECE; h++) {
        for (l = 0; l < TAILLE_PIECE; l++) {
            if (maPiece.idPiece.forme[h][l] == 1) {
                if (maPiece.y + h == monPlateau.hauteur -1 || monPlateau.state[maPiece.x + l][maPiece.y + h + 1] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int colisionDroite(piece maPiece, plateau monPlateau) {
    int l, h;
    for (l = 0; l < TAILLE_PIECE; l++) {
        for (h = 0; h < TAILLE_PIECE; h++) {
            if (maPiece.idPiece.forme[l][h] == 1) {
                if (monPlateau.state[maPiece.x + h + 1][maPiece.y + l] == 1 || maPiece.x + h + 1 >= monPlateau.largeur) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int colisionGauche(piece maPiece, plateau monPlateau) {
    int l, h;
    for (l = 0; l < TAILLE_PIECE; l++) {
        for (h = 0; h < TAILLE_PIECE; h++) {
            if (maPiece.idPiece.forme[l][h] == 1) {
                if (monPlateau.state[maPiece.x + h - 1][maPiece.y + l] == 1 || maPiece.x + h - 1 < 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
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