#include "NcursesWrap.h"


Ncurses::Ncurses()
    {
        win = initscr();
        cbreak();           // disable input buffering
        int y{};
        int x{};
        getmaxyx(stdscr, y, x); 
        max_x = x;
        max_y = y;
    }
Ncurses::~Ncurses()
    {
        endwin();
    }
void Ncurses::pause(){
        getch();
    }
void Ncurses::add(char c, int x, int y)
{
    int old_x{};
    int old_y{};
    getyx(stdscr, old_y, old_x);
    mvaddch(y, x, c);
    move(old_y, old_x);
}
void Ncurses::add(int i, int x, int y)
{
    int old_x{};
    int old_y{};
    getyx(stdscr, old_y, old_x);
    move(y, x);
    printw("%d", i);
    move(old_y, old_x);
}
void Ncurses::nap(int ms)
{
    napms(ms);
}
void Ncurses::refresh()
{
    ::refresh();    // access global function refresh()
}