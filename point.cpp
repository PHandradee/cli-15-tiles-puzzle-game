#include "point.h"

Point Point::get_adjacent_point(const Direction::Type& dir) const
{
    switch (dir)
    {
    case Direction::Type::UP:
        return Point { this->x- 1, this->y  };
        break;
    case Direction::Type::DOWN:
        return Point { this->x+ 1, this->y  };
        break;
    case Direction::Type::LEFT:
        return Point { this->x,  this->y-1, };
        break;
    case Direction::Type::RIGHT:
        return Point { this->x, this->y +1};
        break;
    default:
        return Point {  };
        break;
    }
    
    
}

bool operator==(const Point& c1, const Point& c2)
{
    return c1.x == c2.x && c1.y == c2.y;
}

bool operator!=(const Point& c1, const Point& c2)
{
    return c1.x != c2.x || c1.y != c2.y;
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
    return out << "Point: {" << point.x << " , " << point.y << "}";
}
