/* Ce fichier gère la logique principale du jeu.*/

#include "game.h"

int jouer() {
    struct timespec debut, fin;
    MLV_Keyboard_modifier disposition;
    MLV_Keyboard_button touche;
    int unicode_touche;
    int continuer = 1;
    MLV_clear_window(MLV_COLOR_BLACK);
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