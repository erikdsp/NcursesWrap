#include "NcursesWrap.h"
#include <iostream>

int main() 
{
    {    
        Ncurses window;
        window.add('*', {8, 0});
        window.refresh();
        window.nap(500);
        window.noecho_mode();
        char my_c = window.get_char();
        window.add(my_c, {5, 0});
        std::string s{};
        window.move_cursor({0,2});
        window.echo_mode();
        s = window.get_line();
        window.noecho_mode();
        window.add("Hello", {8, 4});
        window.add(s, {14, 4});
        window.refresh();
        window.press_any_key();
    }                      // end of Ncurses window
    std::cout << "Welcome back!" << "\n";

    return 0;
}
