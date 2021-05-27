//
// Created by Oshri on 19/04/2021.
//

#ifndef EX2_DICE_H
#define EX2_DICE_H


class Dice {

public:
    ~Dice(){};
    Dice():a(22695477),c(1){};
    Dice(const Dice&d);
    Dice& operator=(const Dice& d);
    void insertSeed(const unsigned int& seed){X=seed;}
    const unsigned int rool();

private:
    const unsigned int a;
    const unsigned int c;
    unsigned int X;
};


#endif //EX2_DICE_H
