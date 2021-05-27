//
// Created by Oshri on 19/04/2021.
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H
#include "Triangle.h"
#include <iostream>
class Board {
public:
    Board():blackBar(0),whiteBar(0),blackOut(0),whiteOut(0){initBoardToStartPosition();}
    ~Board() {}
    Board(const Board &b);
    Board& operator=(const Board &b);
    void printBoardToBlack() const ;
    void printBoardToWhite()const ;
    bool moveBlack(int input_from, int input_to,int dice1,int dice2);
    bool moveWhite(int input_from, int input_to,int dice1,int dice2);
    bool checkBlackWin()const;
    bool checkWhiteWin()const ;
    bool checkPossbileMoveBlack(int dice) ;
    bool checkPossbileMoveWhite(int dice) ;

private:
    Triangle triangles[24];
    int blackBar;
    int whiteBar;
    int blackOut;
    int whiteOut;
    void initBoardToStartPosition();
    void printBoardAll()const;
    int checkMaxUpBoardPrint()const ;
    int checkMaxDownBoardPrint()const ;
    bool checkMoveBlack(int from,int to,int input_from,int input_to,int dice1,int dice2);
    bool checkMoveWhite(int from,int to,int input_from,int input_to,int dice1,int dice2);
    int numOfBlack(int index);
    int numOfWhite(int index);
    bool checkWhiteBar();
    bool checkBlackBar();
    int CastBlackInputToMatrixIndex(int input);
    int CastWhiteInputToMatrixIndex(int input);
    bool checkIfAllBlackHome();
    bool checkIfAllWhiteHome();
};


#endif //EX2_BOARD_H
