## A simple Ncurses wrap for C++

The idea is to simplify basic use of Ncurses by wrapping it in a C++ class. 
This attempt is not aiming to be complete. It includes the parts I find useful
and tries to make them accessible. It is mainly for my own use and educational 
purposes. If you need a wrap there are likely better and more complete attempts
out there.

You need to install ncurses on your system:
https://invisible-island.net/ncurses/

A nice tutorial on ncurses: 
https://github.com/mcdaniel/curses_tutorial



Usage: \
Create Ncurses object in a scope. \
When the scope ends the destructor calls endwin() and removes the window. \
This version only uses the default window called stdscr 

Output: \
add() to print stuff to the screen. \
refresh() needs to be called before output is shown 

Input: \
get_char(); \
get_line(); \
press_any_key();    // discards input 


Colors: \
init_colors() enables colors \
set_color_pair() defines a color pair \
color_on() turns a color pair on \
color_off() turns a color pair off \
define_color() defines a custom color 

Predefined colors in Ncurses: \
 COLOR_BLACK   0 \
 COLOR_RED     1 \
 COLOR_GREEN   2 \
 COLOR_YELLOW  3 \
 COLOR_BLUE    4 \
 COLOR_MAGENTA 5 \
 COLOR_CYAN    6 \
 COLOR_WHITE   7 

Simple demo in example.cpp

