#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <limits>
#include <iostream>
#include "direction.h"


namespace InputHandler 
{
    char get_user_key() 
    {   
        char input { };
        std::cin >> input;

        return input;
    };

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool check_user_key(char key)
    {
        if (!std::isalpha(key))
        {
            return false;
        }

        switch (key)
        {
            case 'w':
            case 'a':
            case 's':
            case 'd':
            case 'q':
            case 'r':
                return true;
            default:
                return false;
        }
        
        return false;
    }
    

    char handle_user_input() 
    {
        char input { get_user_key() };
        ignoreLine();
        if (check_user_key(input))
        {
            
            std::cout << "Valid command: " << input << '\n';
            
        } else 
        {
            std::cout << "Invalid command: "<< input << '\n';
        }

        return input;
    }

}



#endif