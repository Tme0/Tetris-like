/* Ce fichier gère la logique principale du jeu.*/

#ifndef GAME_H
#define GAME_H

typedef struct scores {
    int score[10];
} scores;


int jouer();
scores recupererScores();


#endif /* GAME_H */