#include "NcursesWrap.h"
#include <iostream>

int main() 
{
    {    
        Ncurses window;
        window.add('*', {8, 0});
        window.refresh();
        window.nap(500);
        window.add('!', {5, 0});
        std::string s {"Hello"};
        window.add(s, {8, 4});
        window.refresh();
        window.press_any_key();
    }                      // end of Ncurses window
    std::cout << "Welcome back!" << "\n";

    return 0;
}
