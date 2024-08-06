#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>

class Direction
{

public:
    enum Type { UP, DOWN, LEFT, RIGHT, MAXDIRECTIONS };
    Direction(char input_command): m_current_direction{ map_input_to_direction(input_command) } {};

    static Direction generate_random_direction() ;

    Type get_type() const;

    friend std::ostream& operator<<(std::ostream& out, const Direction& dir);

    Direction operator-() const;

private:
    Type m_current_direction {};

    Type map_input_to_direction(char input_command);

};



#endif