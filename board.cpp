#include "board.h"
#include <stddef.h>
#include <algorithm>
#include "direction.h"
#include "point.h"


Matrix Board::get_board() const
{
    return m_board;
}


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

bool is_zero_tile(const Tile& tile) 
{
    return tile.get_value() == 0;
}

bool Board::check_win_condition(const Board& correct_board) const
{
    
    for (size_t i = 0; i < m_board.size(); ++i)
    {
        for (size_t j = 0; j < m_board[i].size(); ++j)
        {
            if (m_board[i][j].get_value() == correct_board.get_board()[i][j].get_value()) 
            {
                continue;
            } else {
                return false;
            };
        }
        
    }

    
    return true;
}

void Board::move_tile(Direction dir)
{

    auto it = std::find_if(m_board.begin(), m_board.end(), [](std::array<Tile, 4> array ) -> bool
    {
        return std::any_of(array.begin(), array.end(), is_zero_tile);
    });

    Tile* zero_tile = nullptr;
    Point zero_tile_position {};
    if (it != m_board.end())
    {
        int zero_row = std::distance(m_board.begin(), it);
        auto zeroObj = std::find_if(it->begin(), it->end(), is_zero_tile);
        int zero_col = std::distance(it->begin(), zeroObj);
        zero_tile = zeroObj;
        zero_tile_position = Point { zero_row, zero_col };
        
    }

    Point adjacent_point { zero_tile_position.get_adjacent_point((-dir).get_type())};

    if ((adjacent_point.x >= 0 && adjacent_point.x < 4  ) && (adjacent_point.y >= 0 && adjacent_point.y < 4  ))
    {
        Tile& tile_to_move = m_board[adjacent_point.x][adjacent_point.y] ;

        zero_tile->set_value(tile_to_move.get_value());
        tile_to_move.set_value(0);
    }

    

}

void Board::shuffle_board(int move_count)
{
    for (size_t i = 0; i <= move_count; ++i)
    {
        move_tile( Direction::generate_random_direction() );
    }
    
}



std::ostream& operator<<(std::ostream& out, const Board& board)
{
    
    
    board.print_empty_lines(25);
    
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
