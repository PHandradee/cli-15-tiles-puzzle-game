#include "tile.h"


int Tile::get_value() const { return m_value; }

void Tile::set_value(int value)
{
    m_value = value;
}

bool Tile::is_empty() const
{
   return m_value <= 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    if (tile.m_value > 9) // if two digit number
        out << " " << tile.m_value << " ";
    else if (tile.m_value > 0) // if one digit number
        out << "  " << tile.m_value << " ";
    else if (tile.m_value == 0) // if empty spot
        out << "    ";
    return out;
}
