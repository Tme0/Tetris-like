#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void resoudreEvenement(MLV_Keyboard_button touche) {
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
        default:
            break;
    }
}

int jouer() {
    struct timespec debut, fin;
    MLV_Keyboard_modifier disposition;
    MLV_Keyboard_button touche;
    int unicode_touche;
    int continuer = 1;
    while (continuer) {
        /*Temps au début l'image*/
        clock_gettime(CLOCK_REALTIME, &debut );
        MLV_actualise_window();
        MLV_get_event(&touche, &disposition, &unicode_touche, NULL, NULL, NULL, NULL, NULL, NULL); 
        /*get_event à completer; Je ne sais pas comment ça marche.*/
        resoudreEvenement(touche);

        /*Temps à la fin de l'image et boucle while pour completer le temps manquant (60/1 sec)*/
        clock_gettime(CLOCK_REALTIME, &fin );
        while ((fin.tv_sec - debut.tv_sec) * 1000000000 + (fin.tv_nsec - debut.tv_nsec) < 16666667) {
            clock_gettime(CLOCK_REALTIME, &fin );
        }
    }
    return 0;
}

void choisirSauvegarde() {
    printf("Choix de la sauvegarde...\n");
}
