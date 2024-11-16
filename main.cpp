#include "NcursesWrap.h"
#include <iostream>

int main() 
{
    std::string s{};
    {    
        Ncurses window;
        window.add("Demo of NcursesWrap", {1, 1});
        window.add(" *  *  *  *  *  *  ", {1, 2});
        window.refresh();
        window.add("Please enter a string: ", {1, 3});
        window.move_cursor({25,3});
        window.echo_mode();
        s = window.get_line();
        window.noecho_mode();
        window.clear_line( { 1, 2 } );
        window.add("You wrote: ", {1,4});
        window.add(s, {13, 4});
        window.refresh();
        window.add("Press any key to exit... ", {1, 7});
        window.press_any_key();
    }                      // end of Ncurses window
    std::cout << "Your string was: " << s << "\n";

    return 0;
}
