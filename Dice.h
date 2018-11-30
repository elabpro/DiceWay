/*
 * File:   Dice.h
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#ifndef DICE_H
#define DICE_H
#include <iostream>

using namespace std;

class Dice {
public:
    Dice();
    Dice(Dice const& a);
    ~Dice();
    int getBottom();
    int roll(int direction);
private:
    int dice[3];
};

#endif /* DICE_H */

