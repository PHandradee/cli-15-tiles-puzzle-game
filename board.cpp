#include "board.h"
#include <stddef.h>


Matrix Board::create_default_board()
{
    
    int value { 1 };
    Matrix board { };

    for (auto& i : board)
    {
        for (auto& j : i)
        {
            if (value < 16)
            {
                j.set_value(value);
            } else
            {
                j.set_value(0);
            }            
            ++value;
        }
        
    }

    return board;
}



std::ostream& operator<<(std::ostream& out, const Board& board)
{
    
    
    board.printEmptyLines(25);
    
    for (const auto& i : board.m_board)
    {
        for (const auto& j : i)
        {
            out <<  j;
        }
        
        out << '\n';
    }
    

    return out;
}
