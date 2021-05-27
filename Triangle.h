//
// Created by Oshri on 20/04/2021.
//

#ifndef EX2_TRIANGLE_H
#define EX2_TRIANGLE_H

class Triangle {
public:
    Triangle();
    ~Triangle(){}
    Triangle(const Triangle &t);
    Triangle& operator=(const Triangle &t);
    int getNumOfWhite() const {return numOfWhite;}//get number of white in triangle
    void setNumOfWhite(unsigned int numOfWhite) {Triangle::numOfWhite = numOfWhite;updateCharTriangle();}
    int getNumOfBlack() const {return numOfBlack;}//get number of black in triangle
    void setNumOfBlack(unsigned int numOfBlack) {Triangle::numOfBlack = numOfBlack;updateCharTriangle();}
    void decrementWhite(){numOfWhite--;};
    void incrementWhite(){numOfWhite++;};
    void decrementBlack(){numOfBlack--;};
    void incrementBlack(){numOfBlack++;};
    void updateCharTriangle();
    char printTriangleIndex(int index)const { return triangle[index];};//print by index on riangle
private:
    char triangle[15];
    unsigned int numOfWhite;
    unsigned int numOfBlack;


};


#endif //EX2_TRIANGLE_H
