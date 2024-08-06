#include <iostream>
#include "tile.h"
#include "board.h"
#include "input_handler.h"
#include "point.h"


int main() 
{
    
    //Tile tile1{ 10 };
    //Tile tile2{ 8 };
    //Tile tile3{ 0 }; // the missing tile
    //Tile tile4{ 1 };
//
    //std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
    //std::cout << tile1 << tile2 << tile3 << tile4 << '\n';
//
    //std::cout << std::boolalpha << tile1.is_empty() << ' ' << tile3.is_empty() << '\n';
    //std::cout << "Tile 2 has number: " << tile2.get_value() << "\nTile 4 has number: " << tile4.get_value() << '\n';

    //Board board{};
    //std::cout << board;
    //
    //std::cout << "Generating random direction... " << Direction::generate_random_direction() << '\n';
    //std::cout << "Generating random direction... " << Direction::generate_random_direction() << '\n';
    //std::cout << "Generating random direction... " << Direction::generate_random_direction() << '\n';
    //std::cout << "Generating random direction... " << Direction::generate_random_direction() << "\n\n";
//
    //std::cout << "Enter a command: ";
//
    //while (true)
    //{
    //    char input { InputHandler::handle_user_input() };
//
//
    //    if (input == 'q')
    //    {
    //        std::cout << "\n\nBye!\n\n";
//
    //        break;
    //    }
//
    //    if (InputHandler::check_user_key(input)) 
    //    {
    //        // Handle direction commands
    //        Direction dir{ input };
//
    //        std::cout << "You entered direction: " << dir << '\n';
    //        std::cout << "The oppossite direction is: " << -dir << '\n';
//
    //    }
//
//
    //}
    
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.get_adjacent_point(Direction::UP)    == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent_point(Direction::DOWN)  == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent_point(Direction::LEFT)  == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent_point(Direction::RIGHT) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';



    return 0;
}