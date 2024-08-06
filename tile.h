#ifndef TILE_H
#define TILE_H

#include <ostream>

class Tile
{
private:
    int m_value {};

public:
    Tile() = default;
    explicit Tile(int value) : m_value{ value } {};
    
    
    int get_value() const;
    void set_value(int value);
    bool is_empty() const;

    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

};


#endif