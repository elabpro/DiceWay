/*
 * File:   Field.h
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#ifndef FIELD_H
#define FIELD_H

#include "Dice.h"
#include "Point.h"
#include <iostream>
#include <vector>

using namespace std;

class Field {
public:
    Field();
    Field(const Field& orig);
    Field(int n);
    ~Field();
    void startAt(int x, int y, Dice &d);
    int findWay(int m);
    void const print();
    void const printPath();
    int makeStep(int x, int y, Dice *d);
private:
    int *field;
    int n;
    int summary;
    int diceX, diceY;
    int goal = 0;
    Dice* dice;
    int directions[4] = {2, 4, 6, 8};
    int position(int x, int y);
    int position(Point *p);
    bool newposition(int x, int y, int direction, Point *p);
    vector<Point>path;
};

#endif /* FIELD_H */

