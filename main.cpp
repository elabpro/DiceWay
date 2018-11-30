/*
 * File:   main.cpp
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#include <cstdlib>
#include <iostream>
#include "Field.h"
#include "Dice.h"

using namespace std;

/*
 * Dice game
 */
int main(int argc, char** argv) {
    cout << "Enter N Value:  ";
    int n;
    cin >> n;
    cout << "Enter M Value:  ";
    int m;
    cin >> m;
    if (n > 0 && m >= 0) {
        // Create the field
        Field* f = new Field(n);
        // Place the dice on the field
        Dice* d = new Dice();
        f->startAt(0, 0, *d);
        //   Trying to solve
        if (f->findWay(m) > 0) {
            // Show field
            f->printPath();
            f->print();
        }
    } else {
        cout << "Wrong input data" << endl;
    }
    return 0;
}

