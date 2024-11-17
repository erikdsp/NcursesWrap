#include "NcursesWrap.h"
#include <iostream>

int main() 
{
    std::string s{};
    const int purple_rain = 8;  // define an index 
    {    
        Ncurses window;
        window.init_colors();
        window.set_color_pair(1, COLOR_RED, COLOR_BLACK);       
        window.define_color(purple_rain, 98, 47, 117);
        window.set_color_pair(2, purple_rain, COLOR_BLACK);     
        window.color_on(1);
        window.add("Demo of NcursesWrap", {1, 1});
        window.color_off(1);
        window.color_on(2);
        window.add(" *  *  *  *  *  *  ", {1, 2});
        window.color_off(2);
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
