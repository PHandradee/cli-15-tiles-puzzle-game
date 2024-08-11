#include <iostream>
#include "tile.h"
#include "board.h"
#include "input_handler.h"
#include "point.h"


int main() 
{
    
    const Board correct_board {};
    
    Board board{};

    board.shuffle_board(1);

    std::cout << board;

    while (true)
    {
        std::cout << "Enter a command: ";
        char input { InputHandler::handle_user_input() };


        if (input == 'q')
        {
            std::cout << "\n\nBye!\n\n";

            break;
        }

        if (InputHandler::check_user_key(input)) 
        {
            // Handle direction commands
            Direction dir{ input };

            board.move_tile(dir);

            std::cout << board;

        }

        if (board.check_win_condition(correct_board)) 
        {
            std::cout << board << '\n';

            std::cout << "Congratulations! You win!" << '\n';

            break;
        };
        

    }
    


    return 0;
}