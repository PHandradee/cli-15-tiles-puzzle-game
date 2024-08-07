#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <array>
#include <ostream>
#include "tile.h"
#include "direction.h"


using Matrix = std::array<std::array<Tile,4>,4>;

class Board
{
private:
    Matrix m_board {};

    Matrix create_default_board();

    void swap_tiles(const Tile& tile1, const Tile& tile2);

public:
    Board(): m_board { create_default_board() } {};

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    static void printEmptyLines(int count)
    {
        for (int i = 0; i < count; ++i)
            std::cout << '\n';
    }

    void move_tile(Direction dir);

};




#endif