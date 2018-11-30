/*
 * File:   Dice.cpp
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#include "Dice.h"

Dice::Dice() {
    // Bottom
    dice[0] = 6;
    // Front
    dice[1] = 2;
    // Right side
    dice[2] = 3;
}

Dice::Dice(Dice const& a) {
    dice[0] = a.dice[0];
    dice[1] = a.dice[1];
    dice[2] = a.dice[2];
}

Dice::~Dice() {
}

int Dice::getBottom() {
    return dice[0];
}

/**
 * Roll the dice
 *
 * @param direction (4<- ->6, 8/\, 2 \/)
 * @return down side
 */
int Dice::roll(int direction) {
    int b = dice[0];
    switch (direction) {
        case 6:
        {
            dice[0] = dice[2];
            dice[2] = 7 - b;
            break;
        }
        case 4:
        {
            dice[0] = 7 - dice[2];
            dice[2] = b;
            break;
        }
        case 8:
        {
            dice[0] = 7 - dice[1];
            dice[1] = b;
            break;
        }
        case 2:
        {
            dice[0] = dice[1];
            dice[1] = 7 - b;
            break;
        }
        default:
        {
            cout << "Wrong direction " << direction << endl;
        }
    }
    return getBottom();
}
