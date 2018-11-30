/* 
 * File:   Point.h
 * Author: eugine
 *
 * Created on November 2, 2018
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:
    int x;
    int y;
    Point();
    Point(int x, int y) : x(x), y(y) {
    };
    Point(const Point& orig);
    virtual ~Point();
private:

};

#endif /* POINT_H */

