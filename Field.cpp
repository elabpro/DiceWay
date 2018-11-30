/*
 * File:   Field.cpp
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#include "Field.h"

Field::Field() {
    summary = 0;
    n = 0;
    field = 0;
}

Field::Field(const Field& orig) {
}

Field::~Field() {
    delete [] field;
}

/**
 * Init field with size NxN (fill with 0)
 *
 * @param n1
 */
Field::Field(int n1) {
    summary = 0;
    n = n1;
    field = new int[n * n];
    for (int i = 0; i < n * n; i++) {
        field[i] = 0;
    }
}

/**
 * Set initial point for the dice
 *
 * @param x
 * @param y
 * @param d
 */
void Field::startAt(int x, int y, Dice &d) {
    int diceValue = d.getBottom();
    field[position(x, y)] = diceValue;
    summary += diceValue;
    dice = &d;
    diceX = x;
    diceY = y;
}

/**
 * Get position on the field
 *
 * @param x
 * @param y
 * @return
 */
int Field::position(int x, int y) {
    return (y * n)+x;
}

/**
 * Get position on the field
 *
 * @param p
 * @return
 */
int Field::position(Point *p) {
    return (p->y * n)+p->x;
}

/**
 * Check new position
 *
 * @param x
 * @param y
 * @param direction
 * @return
 */
bool Field::newposition(int x, int y, int direction, Point *p) {
    switch (direction) {
        case 8:y++;
            break;
        case 2:y--;
            break;
        case 4:x--;
            break;
        case 6:x++;
            break;
    }
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    } else {
        *p = {x, y};
        return true;
    }
}

/**
 * Start search for a way
 *
 * @param m
 * @return
 */
int Field::findWay(int m) {
    int result = 0;
    goal = m;
    if (goal < summary) {
        cout << "No way\n";
        result = -1;
    } else {
        if (goal == summary) {
            cout << "Nothing to do\n";
        } else {
            // Make a step
            result = makeStep(diceX, diceY, dice);
            if (!result) {
                cout << "Can't find a way\n";
                result = -1;
            }
        }
    }
    return result;
}

/**
 * Output the field
 *
 * @return
 */
void const Field::print() {
    cout << "------- FIELD -----------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[position(j, n - i - 1)] << "\t";
        }
        cout << endl;
    }
}

/**
 * Show path
 *
 * @return
 */
void const Field::printPath() {
    cout << "------- PATH -----------------" << endl;
    for (size_t i = 0; i < path.size(); i++) {
        cout << "(" << path[i].y << "," << path[i].x << ")" << "\t";
    }
    cout << endl;
}

/**
 * Making a step
 *
 * @param x
 * @param y
 * @param d
 * @return
 */
int Field::makeStep(int x, int y, Dice *d) {
    for (int iDir = 0; iDir <= 3; iDir++) {
        Point curPos = {x, y};
        Point newPos;
        if (newposition(x, y, directions[iDir], &newPos) && field[position(&newPos)] == 0) {
            // We able to make a move
            // Make local copy of the dice
            Dice newDice = *d;
            // Pretend to roll the dice
            int newBottom = newDice.roll(directions[iDir]);
            if (newBottom + summary < goal) {
                field[position(&newPos)] = newBottom;
                summary += newBottom;
                path.push_back(newPos);
                int res = makeStep(newPos.x, newPos.y, &newDice);
                if (res != 1) {
                    // Forget this step
                    path.pop_back();
                    field[position(&newPos)] = 0;
                    summary -= newBottom;
                } else {
                    // We reached the goal in the depth
                    return 1;
                }
            } else {
                if (newBottom + summary == goal) {
                    // We reach the goal
                    field[position(&newPos)] = newBottom;
                    path.push_back(newPos);
                    return 1;
                }
            }
        }
    }
    return 0;
}
