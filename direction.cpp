#include "direction.h"
#include "Random.h"
#include <string>

Direction::Type Direction::map_input_to_direction(char input_command)
{
    switch (input_command)
    {
    case 'w':
        return Direction::UP;
        break;
    case 'a':
        return Direction::LEFT;
        break;
    case 's':
        return Direction::DOWN;
        break;
    case 'd':
        return Direction::RIGHT;
        break;
    default:
        break;
    }

    return Direction::UP;
}

Direction Direction::generate_random_direction() 
{
    std::string str { "wasd" };

    // Gera um índice aleatório
    int randomIndex { (Random::get(0, Type::MAXDIRECTIONS - 1)) };

    
    return Direction(str[randomIndex]);
}

Direction::Type Direction::get_type() const
{
    return m_current_direction;
}

Direction Direction::operator-() const
{
    
    switch (m_current_direction)
    {
    case Direction::Type::UP:
        return Direction{ 's' };
        break;
    case Direction::Type::DOWN:
        return Direction{ 'w' };
        break;
    case Direction::Type::LEFT:
        return Direction{ 'd' };
        break;
    case Direction::Type::RIGHT:
        return Direction{ 'a' };
        break;
    default:
        return Direction { 'w' };
        break;
    }
    
}

std::ostream& operator<<(std::ostream& out, const Direction& dir)
{
    switch (dir.get_type())
    {
        case Direction::UP:     return (out << "up");
        case Direction::DOWN:   return (out  << "down");
        case Direction::LEFT:   return (out << "left");
        case Direction::RIGHT:  return (out << "right");
        default:                break;
    }

    return out << Direction::generate_random_direction();
}
