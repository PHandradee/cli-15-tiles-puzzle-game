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

public:
    Board(): m_board { create_default_board() } {};

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    static void print_empty_lines(int count)
    {
        for (int i = 0; i < count; ++i)
            std::cout << '\n';
    }

    bool check_win_condition(const Board& correct_board) const;

    void move_tile(Direction dir);

    void shuffle_board(int move_count = 25);

    Matrix get_board() const;

};




#endif