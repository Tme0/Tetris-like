#include "../headers/graphics.h"
#include "../headers/input.h"
#include "../headers/save.h"
#include "../headers/game.h"
#include "../headers/piece.h"
#include "../headers/plateau.h"
#include <time.h>


int main() {
    srand(time(NULL));
    initialiserFenetre();
    menu(1);
    exit(EXIT_SUCCESS);
}
