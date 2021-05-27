//
// Created by Oshri on 20/04/2021.
//

#include "Triangle.h"

Triangle::Triangle():numOfWhite(0),numOfBlack(0){
    updateCharTriangle();

}
void Triangle::updateCharTriangle()//update the piece
{
    for (int i = 0; i <15 ; ++i) {
        triangle[i]='|';
    }
    if(numOfWhite>0)
    {
        for ( unsigned int i = 0; i <numOfWhite ; ++i) {
            triangle[i]='W';
        }
    } else
    {
        if(numOfBlack>0)
        {
            for (unsigned int i = 0; i <numOfBlack ; ++i) {
                triangle[i]='B';
            }
        }
    }

}

Triangle::Triangle(const Triangle &t):numOfWhite(t.numOfWhite),numOfBlack(t.numOfBlack)
{
    updateCharTriangle();
}

Triangle &Triangle::operator=(const Triangle &t) {
    if(this== &t)
        return (*this);
    this->numOfBlack = t.numOfBlack;
    this->numOfWhite = t.numOfWhite;
    this->updateCharTriangle();
    return *this;
}


