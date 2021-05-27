#include <iostream>
//#include "Dice.h"
//#include "Board.h"
#include "Game.h"
int main() {
    Game* game = new Game;
    game->run();
    delete game;
    return 0;
}