#include "NcursesWrap.h"


Ncurses::Ncurses()
    {
        win = initscr();
        cbreak();           // disable input buffering
        Point p{};
        getmaxyx(stdscr, p.y, p.x); 
        max.x = p.x;
        max.y = p.y;
    }

Ncurses::~Ncurses()
    {
        endwin();
    }

void Ncurses::press_any_key(){
        getch();
    }

void Ncurses::add(char c, Point p)
{
    Point old{};
    getyx(stdscr, old.y, old.x);
    mvaddch(p.y, p.x, c);
    move(old.y, old.x);
}
void Ncurses::add(int i, Point p)
{
    Point old{};
    getyx(stdscr, old.y, old.x);
    move(p.y, p.x);
    printw("%d", i);
    move(old.y, old.x);
}

void Ncurses::add(double d, Point p)
{

}

void Ncurses::add(std::string_view s, Point p)
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


void Ncurses::move_cursor(Point p)
{
    move(p.y, p.x);
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
