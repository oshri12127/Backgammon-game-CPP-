//
// Created by Oshri on 19/04/2021.
//

#include "Game.h"

void Game::run() //start the game
{
    try
    {
        int seed;
        std::cout << "Enter seed" << std::endl;
        std::cin >> seed;
        if (std::cin.fail() || seed < 0)
        {
            std::string error = "Missing user input - quiting game.";
            throw std::invalid_argument(error);
        }
        dice.insertSeed(seed);
        do
        {
            dice1 = dice.rool();
            dice2 = dice.rool();
            std::cout << "White player casts " << dice1 << ", black player casts " << dice2 << std::endl;
        } while (dice1 == dice2);
        if (dice1 > dice2)
        {
            turn = 0;
            std::cout << "White plays first." << std::endl;
        }
        else
        {
            turn = 1;
            std::cout << "Black plays first." << std::endl;
        }
        while(playerWin==0)
        {
            //numOfMoves = 2;
            if(turn==0)
            {
                whiteTurn();
                turn=1;
            }
            else
            {
                blackTurn();
                turn=0;
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
}

void Game::whiteTurn()//white turn
{
    int numOfMoves=2;
    int input_from, input_to;
    int dicePlayed=0;
    board.printBoardToWhite();
    dice1 = dice.rool();
    dice2 = dice.rool();
    if (dice1 == dice2)
        numOfMoves = 4;
    std::cout << "White rolls " << dice1 << "-" << dice2 << "." << std::endl;
    if (board.checkPossbileMoveWhite(dice1) == false && board.checkPossbileMoveWhite(dice2) == false)
    {
        std::cout << "No possible move for White" << std::endl;
        return;
    }
    for (int i = numOfMoves; i > 0; i--)
    {
        std::cout << "Enter White move: " << std::endl;
        std::cin >> input_from >> input_to;
        if (std::cin.fail())
        {
            std::string error = "Missing user input - quiting game.";
            throw std::invalid_argument(error);
        }
        if(numOfMoves==2&&dicePlayed!=0&&input_to!=0)
        {
            if(input_from-input_to==dicePlayed)
            {
                std::cout << "You've already played this dice, try again" << std::endl;
                i++;
                continue;
            }
        }
        if (board.moveWhite(input_from, input_to, dice1, dice2) == false)
        {
            i++;
        }
        else//move is true
        {
            dicePlayed=input_from-input_to;
            if (board.checkWhiteWin() == true)
            {
                std::cout << "White player wins!" << std::endl;
                playerWin=1;
                return;
            }
            if(numOfMoves==4)
            {
                if (board.checkPossbileMoveWhite(dice1) == false)
                {
                    std::cout << "No possible move for White" << std::endl;
                    return;
                }
            }
            else if(input_from-input_to==dice1)
            {
                if(board.checkPossbileMoveWhite(dice2) == false)
                {
                    std::cout << "No possible move for White" << std::endl;
                    return;
                }
            }
            else if(board.checkPossbileMoveWhite(dice1) == false)
            {
                std::cout << "No possible move for White" << std::endl;
                return;
            }
        }
    }
}

void Game::blackTurn()//black turn
{
    int numOfMoves=2;
    int dicePlayed=0;
    int input_from, input_to;
    board.printBoardToBlack();
    dice1 = dice.rool();
    dice2 = dice.rool();
    if (dice1 == dice2)
        numOfMoves = 4;
    std::cout << "Black rolls " << dice1 << "-" << dice2 << "." << std::endl;
    if (board.checkPossbileMoveBlack(dice1) == false && board.checkPossbileMoveBlack(dice2) == false)
    {
        std::cout << "No possible move for Black" << std::endl;
        return;
    }
    for (int i = numOfMoves; i > 0; i--)
    {
        std::cout << "Enter Black move: " << std::endl;
        std::cin >> input_from >> input_to;
        if (std::cin.fail())
        {
            std::string error = "Missing user input - quiting game.";
            throw std::invalid_argument(error);
        }
        if(numOfMoves==2&&dicePlayed!=0&&input_to!=0)
        {
            if(input_from-input_to==dicePlayed)
            {
                std::cout << "You've already played this dice, try again" << std::endl;
                i++;
                continue;
            }
        }
        if (board.moveBlack(input_from, input_to, dice1, dice2) == false)
        {
            i++;
        }
        else//move is true
        {
            dicePlayed=input_from-input_to;
            if (board.checkBlackWin() == true)
            {
                std::cout << "Black player wins!" << std::endl;
                playerWin=1;
                return;
            }
            if(numOfMoves==4)
            {
                if (board.checkPossbileMoveBlack(dice1) == false)
                {
                    std::cout << "No possible move for Black" << std::endl;
                    return;
                }
            }
            else if(input_from-input_to==dice1)
            {
                if(board.checkPossbileMoveBlack(dice2) == false)
                {
                    std::cout << "No possible move for Black" << std::endl;
                    return;
                }
            }
            else if(board.checkPossbileMoveBlack(dice1) == false)
            {
                std::cout << "No possible move for Black" << std::endl;
                return;
            }
        }
    }

}

Game::Game(const Game &g):dice(g.dice),dice1(g.dice1),dice2(g.dice2),board(g.board),turn(g.turn),playerWin(g.playerWin) {

}

Game &Game::operator=(const Game &g) {
    if (this == &g) // copying from the same object
        return *this;
    else
    {
        this->dice = g.dice;
        this->dice1 = g.dice1;
        this->dice2 = g.dice2;
        this->board= g.board;
        this->turn = g.turn;
        this->playerWin = g.playerWin;
    }
    return *this;
}

