/*Ce fichier gère la création et le mouvement des pièces.*/

#include "../headers/plateau.h"

void initialiserPlateau(int plateau[10][20]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            plateau[i][j] = 0;
        }
    }
}

