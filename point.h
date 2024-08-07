#ifndef POINT_H
#define POINT_H

#include "direction.h"

struct Point
{
    int x { };
    int y { };

    Point get_adjacent_point(const Direction::Type& dir) const;

    friend bool operator== (const Point& c1, const Point& c2);
    friend bool operator!= (const Point& c1, const Point& c2);
    friend std::ostream& operator<<(std::ostream& out, const Point& point);


};


#endif