#include "NcursesWrap.h"
#include <iostream>

int main() 
{
    {    
        Ncurses window;
        window.add('*', 8, 0);
        window.refresh();
        window.nap(500);
        window.add('!', 5, 0);
        window.refresh();
        window.pause();
    }                      // end of Ncurses window


    return 0;
}
