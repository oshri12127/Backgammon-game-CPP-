//
// Created by Oshri on 19/04/2021.
//

#include "Dice.h"

const unsigned int Dice::rool() //rool dice
{
    X = a*X + c;
    return (((X & 0x7fffffff) >> 16)%6)+1;
}

Dice::Dice(const Dice &d):a(d.a),c(d.c),X(d.X) {

}

Dice &Dice::operator=(const Dice &d) {
    if(this== &d)
        return (*this);
    this->X = d.X;
    return *this;
}
