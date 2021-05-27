//
// Created by Oshri on 19/04/2021.
//

#include "Board.h"


void Board::printBoardToBlack()const//print num of board to black
{
    std::cout<<" 12 11 10  9  8  7     6  5  4  3  2  1" << std::endl;
    std::cout<<"+------------------+-+------------------+"<<std::endl;
    printBoardAll();
    std::cout<<"+------------------+-+------------------+"<<std::endl;
    std::cout<<" 13 14 15 16 17 18    19 20 21 22 23 24" << std::endl;
}
void Board::printBoardToWhite()const//print num of board to black
{
    std::cout<<" 13 14 15 16 17 18    19 20 21 22 23 24" << std::endl;
    std::cout<<"+------------------+-+------------------+"<<std::endl;
    printBoardAll();
    std::cout<<"+------------------+-+------------------+"<<std::endl;
    std::cout<<" 12 11 10  9  8  7     6  5  4  3  2  1" << std::endl;

}
void Board::printBoardAll() const//print board
{
    int printedBlackBar=blackBar-1;
    int printedWhiteBar=0;
    for (int i = 0; i <checkMaxUpBoardPrint() ; ++i)//use func
    {
        std::cout<<"+ ";
        for (int j = 0; j <12 ; ++j)
        {
            std::cout << triangles[j].printTriangleIndex(i);//TODO:operator[]
            if(j==11)
            {std::cout <<" ";}
            else if(j!=5)
            {std::cout <<"  ";}
            else{
                if(whiteBar!=0&&printedWhiteBar<whiteBar)
                {
                    std::cout <<" +W+ ";
                    printedWhiteBar++;
                }
                else
                {std::cout <<" + + ";}
            }
        }
        std::cout<<"+";
        std::cout << std::endl;
    }
    std::cout<<"+                  + +                  +"<<std::endl;
    for (int i = checkMaxDownBoardPrint()-1; i >=0 ; i--)//use func
    {
        std::cout<<"+ ";
        for (int j = 12; j <24 ; ++j) {
            std::cout << triangles[j].printTriangleIndex(i);//TODO:operator[]
            if(j==23)
            {std::cout <<" ";}
            else if(j!=17)
            {std::cout <<"  ";}
            else
            {
                if(blackBar!=0&&printedBlackBar==i)
                {
                    std::cout <<" +B+ ";
                    printedBlackBar--;
                }
                else
                {std::cout <<" + + ";}
            }

        }
        std::cout<<"+";
        std::cout << std::endl;
    }

}

int Board::checkMaxUpBoardPrint() const {
    int max=5;
    int tempNumOfWhite,tempNumOfBlack;
    for (int i = 0; i <12 ; ++i) {
        tempNumOfBlack=triangles[i].getNumOfBlack();
        tempNumOfWhite=triangles[i].getNumOfWhite();
        if(max<tempNumOfBlack)
            max=tempNumOfBlack;
        if(max<tempNumOfWhite)
            max=tempNumOfWhite;
    }
    if(max<whiteBar)
        max=whiteBar;
    return max;
}

int Board::checkMaxDownBoardPrint() const {
     int max=5;
     int tempNumOfWhite,tempNumOfBlack;
    for (int i = 12; i <24 ; ++i) {
        tempNumOfBlack=triangles[i].getNumOfBlack();
        tempNumOfWhite=triangles[i].getNumOfWhite();
        if(max<tempNumOfBlack)
            max=tempNumOfBlack;
        if(max<tempNumOfWhite)
            max=tempNumOfWhite;
    }
    if(max<blackBar)
        max=blackBar;
    return max;
}

bool Board::checkBlackWin()const//check if win
{
    if(blackOut == 15)
    {
        return true;
    }
    return false;
}

bool Board::checkWhiteWin()const//check if win
{
    if(whiteOut == 15)
    {
        return true;
    }
    return false;
}

void Board::initBoardToStartPosition()//start position
{
    triangles[11].setNumOfWhite(2);
    triangles[0].setNumOfWhite(5);
    triangles[18].setNumOfWhite(5);
    triangles[16].setNumOfWhite(3);
    triangles[23].setNumOfBlack(2);
    triangles[12].setNumOfBlack(5);
    triangles[6].setNumOfBlack(5);
    triangles[4].setNumOfBlack(3);
}

int Board::numOfBlack(int index) {

    return triangles[index].getNumOfBlack();
}

bool Board::moveBlack(int input_from, int input_to,int dice1,int dice2)//move pieces
{
    int from_in_matrix;
    int to_in_matrix;
    from_in_matrix=CastBlackInputToMatrixIndex(input_from);
    to_in_matrix=CastBlackInputToMatrixIndex(input_to);
    if(checkMoveBlack(from_in_matrix,to_in_matrix,input_from,input_to,dice1,dice2)== true)
    {
        if(input_from==25)
        {
            blackBar--;
            triangles[to_in_matrix].incrementBlack();
            triangles[to_in_matrix].updateCharTriangle();
        }
        else if(input_to==0)
        {
            blackOut++;
            triangles[from_in_matrix].decrementBlack();
            triangles[from_in_matrix].updateCharTriangle();
        }
        else
        {
            triangles[from_in_matrix].decrementBlack();
            triangles[to_in_matrix].incrementBlack();
            if(triangles[to_in_matrix].getNumOfWhite()>0)
            {
                triangles[to_in_matrix].decrementWhite();
                whiteBar++;
            }
            triangles[from_in_matrix].updateCharTriangle();
            triangles[to_in_matrix].updateCharTriangle();
        }
        return true;
    }
    return false;
}
bool Board::moveWhite(int input_from, int input_to,int dice1,int dice2)//move pieces
{
    int from_in_matrix;
    int to_in_matrix;
    from_in_matrix=CastWhiteInputToMatrixIndex(input_from);
    to_in_matrix=CastWhiteInputToMatrixIndex(input_to);
    if(checkMoveWhite(from_in_matrix,to_in_matrix,input_from,input_to,dice1,dice2)== true)
    {
        if(input_from==25)
        {
            whiteBar--;
            triangles[to_in_matrix].incrementWhite();
            triangles[to_in_matrix].updateCharTriangle();
        }
        else if(input_to==0)
        {
            whiteOut++;
            triangles[from_in_matrix].decrementWhite();
            triangles[from_in_matrix].updateCharTriangle();
        }
        else
        {
            triangles[from_in_matrix].decrementWhite();
            triangles[to_in_matrix].incrementWhite();
            if(triangles[to_in_matrix].getNumOfBlack()>0)
            {
                triangles[to_in_matrix].decrementBlack();
                blackBar++;
            }
            triangles[from_in_matrix].updateCharTriangle();
            triangles[to_in_matrix].updateCharTriangle();
        }
        return true;
    }
    return false;
}
int Board::numOfWhite(int index) {
    return triangles[index].getNumOfWhite();
}

bool Board::checkWhiteBar() //check if have pieces in bar
{
    if(whiteBar>0)
        return true;
    return false;
}

bool Board::checkBlackBar()//check if have pieces in bar
{
    if(blackBar>0)
        return true;
    return false;
}

bool Board::checkMoveBlack(int from, int to,int input_from,int input_to,int dice1,int dice2)//check move
{
    if((input_from<1||input_from>25)||(input_to<0||input_to>24)||(input_from-input_to>6||input_from-input_to<1))
    {
        std::cout << "Illegal move: From/to out of bounds (from="<<input_from<<", to="<<input_to<<")." << std::endl;
        return false;
    }
    else if(checkBlackBar()== true&&input_from!=25)
    {
        std::cout << "Illegal move: Player still has captured piece(s)." << std::endl;
        return false;
    }
    else if((input_from==25&&checkBlackBar()==false)||(input_from!=25&&numOfBlack(from)==0))
    {
        std::cout << "Illegal move: No pieces at from location "<< input_from<<"."<< std::endl;
        return false;
    }
    else if(input_to!=0&&numOfWhite(to)>1)
    {
        std::cout << "Illegal move: Cannot capture more that one piece at location "<< input_to<<"."<< std::endl;
        return false;
    }
    else if(input_to==0&&checkIfAllBlackHome()==false)
    {
        std::cout << "Illegal move: Cannot bear off while not all pieces at home."<< std::endl;
        return false;
    }
    else if((input_to==0&&input_from>dice1&&input_from>dice2)||(input_to!=0&&input_from-input_to!=dice1&&input_from-input_to!=dice2))
    {
        std::cout << "Illegal move: No value of "<< input_from-input_to<<" in dice roll "<< std::endl;
        return false;
    }
        return true;
}

bool Board::checkMoveWhite(int from, int to,int input_from,int input_to,int dice1,int dice2)//check move
{

    if((input_from<1||input_from>25)||(input_to<0||input_to>24)||(input_from-input_to>6||input_from-input_to<1))
    {
        std::cout << "Illegal move: From/to out of bounds (from="<<input_from<<", to="<<input_to<<")." << std::endl;
        return false;
    }
    else if(checkWhiteBar()== true&&input_from!=25)
    {
        std::cout << "Illegal move: Player still has captured piece(s)." << std::endl;
        return false;
    }
    else if((input_from==25&&checkWhiteBar()==false)||(input_from!=25&&numOfWhite(from)==0))
    {
        std::cout << "Illegal move: No pieces at from location "<< input_from<<"."<< std::endl;
        return false;
    }
    else if(input_to!=0&&numOfBlack(to)>1)
    {
        std::cout << "Illegal move: Cannot capture more that one piece at location "<< input_to<<"."<< std::endl;
        return false;
    }
     else if(input_to==0&&checkIfAllWhiteHome()== false)
     {
         std::cout << "Illegal move: Cannot bear off while not all pieces at home."<< std::endl;
         return false;
     }
    else if((input_to==0&&input_from>dice1&&input_from>dice2)||(input_to!=0&&input_from-input_to!=dice1&&input_from-input_to!=dice2))
    {
        std::cout << "Illegal move: No value of "<< input_from-input_to<<" in dice roll "<< std::endl;
        return false;
    }
    return true;
}

int Board::CastBlackInputToMatrixIndex(int input)//change input to matrix index
{
    if(input==25)
        return 25;
    if(input==0)
        return -1;
    if(input>12)
        return input-1;
    else
        return 12-input;
}

int Board::CastWhiteInputToMatrixIndex(int input)//change input to matrix index
{
    if(input==25)
        return 25;
    if(input==0)
        return -1;
    if(input>12)
        return input-13;
    else
        return 24-input;
}

bool Board::checkIfAllBlackHome()//check if all pieces in home
{
    int count=0;
    for (int i = 6; i < 12; ++i)
    {
        count+=triangles[i].getNumOfBlack();
    }
    count+=blackOut;
    if(count==15)
        return true;
    return false;
}

bool Board::checkIfAllWhiteHome() //check if all pieces in home
{
    int count=0;
    for (int i = 18; i < 24; ++i)
    {
        count+=triangles[i].getNumOfWhite();
    }
    count+=whiteOut;
    if(count==15)
        return true;
    return false;}

bool Board::checkPossbileMoveBlack(int dice)//check if possible move
{
    if(blackBar==0){
        for (int i = 1; i < 25; ++i) {
            if (triangles[CastBlackInputToMatrixIndex(i)].getNumOfBlack() > 0) {
                if (i - dice > 0 && triangles[CastBlackInputToMatrixIndex(i - dice)].getNumOfWhite() < 2)
                    return true;
                if (i - dice <= 0 && checkIfAllBlackHome() == true)
                    return true;
            }
        }
    }
    if(blackBar>0&&triangles[CastBlackInputToMatrixIndex(25-dice)].getNumOfWhite()<2)
        return true;
    return false;
}

bool Board::checkPossbileMoveWhite(int dice)//check if possible to move
{
    if(whiteBar==0) {
        for (int i = 1; i < 25; ++i) {
            if (triangles[CastWhiteInputToMatrixIndex(i)].getNumOfWhite() > 0) {
                if (i - dice > 0 && triangles[CastWhiteInputToMatrixIndex(i - dice)].getNumOfBlack() < 2)
                    return true;
                if (i - dice <= 0 && checkIfAllWhiteHome() == true)
                    return true;
            }
        }
    }
    if(whiteBar>0&&triangles[CastWhiteInputToMatrixIndex(25-dice)].getNumOfBlack()<2)
        return true;
    return false;
}

Board::Board(const Board &b):blackBar(b.blackBar),whiteBar(b.whiteBar),blackOut(b.blackOut),whiteOut(b.whiteOut) {
    for (int i = 0; i <24 ; ++i) {
        triangles[i]=b.triangles[i];

    }
}

Board &Board::operator=(const Board &b) {
    if(this== &b)
        return (*this);
    this->blackBar = b.blackBar;
    this->whiteBar = b.whiteBar;
    this->blackOut = b.blackOut;
    this->whiteOut = b.whiteOut;
    for (int i = 0; i <24 ; ++i) {
        triangles[i]=b.triangles[i];
    }
    return *this;
}




