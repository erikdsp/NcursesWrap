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

void Ncurses::press_any_key(){
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

void Ncurses::add(double d, int x, int y)
{

}
void Ncurses::add(std::string_view s, int x, int y)
{
    
}


void Ncurses::nap(int ms)
{
    napms(ms);
}
void Ncurses::refresh()
{
    ::refresh();    // access global function refresh()
}


void Ncurses::move_cursor()
{

}

void Ncurses::noecho_mode()
{

}

void Ncurses::echo_mode()
{

}

char Ncurses::get_char()
{
    return 'E';     // dummy return
}

std::string Ncurses::get_line()
{
    return "get_line()";    // dummy return
}
