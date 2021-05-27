//
// Created by Oshri on 19/04/2021.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Board.h"
#include "Dice.h"
#include <stdexcept>
class Game{
public:
    Game():turn(0),playerWin(0){}
    ~Game() {}
    void run();
private:
    Dice dice;
    int dice1,dice2;
    Board board;
    int turn;//0-white,1-black
    int playerWin;//1-win
    void whiteTurn();
    void blackTurn();
    Game(const Game &g);
    Game& operator=(const Game &g);

};


#endif //EX2_GAME_H
