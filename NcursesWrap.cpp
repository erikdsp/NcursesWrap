#include "NcursesWrap.h"


Ncurses::Ncurses()
    {
        win = initscr();
        cbreak();           // disable input buffering
        Coord p;
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

/** 
 * Add functions with Coord prints at given Coord
 * and then returns cursor to precious position
 * Note that refresh() is needed afterwards for actual output to screen
 */

void Ncurses::add(char c, Coord p)
{
    Coord old{};
    getyx(stdscr, old.y, old.x);
    mvaddch(p.y, p.x, c);
    move(old.y, old.x);
}
void Ncurses::add(int i, Coord p)
{
    Coord old{};
    getyx(stdscr, old.y, old.x);
    move(p.y, p.x);
    printw("%d", i);
    move(old.y, old.x);
}

void Ncurses::add(double d, Coord p)
{
    Coord old{};
    getyx(stdscr, old.y, old.x);
    move(p.y, p.x);
    printw("%lf", d);
    move(old.y, old.x);
}

void Ncurses::add(float f, Coord p)
{
    add(static_cast<double>(f), p);
}

void Ncurses::add(const char* str, Coord p)
{
    Coord old{};
    getyx(stdscr, old.y, old.x);
    mvaddstr(p.y, p.x, str);
    move(old.y, old.x);    
}

void Ncurses::add(std::string& str, Coord p) const
{
    Coord old{};
    getyx(stdscr, old.y, old.x);
    mvaddstr(p.y, p.x, str.c_str());
    move(old.y, old.x);
}

/** 
 * Add functions without Coord prints at current cursor location
 * Note that refresh() is needed afterwards for actual output to screen
 */

void Ncurses::add(char c)
{
    addch(c);
}

void Ncurses::add(int i)
{
    printw("%d", i);
}

void Ncurses::add(double d)
{
    printw("%lf", d);
}

void Ncurses::add(float f)
{
    printw("%f", f);
}

void Ncurses::add(const char* str)
{
    addstr(str);
}

void Ncurses::add(std::string& str) const
{
    addstr(str.c_str());
}


void Ncurses::nap(int ms)
{
    napms(ms);
}
void Ncurses::refresh()
{
    ::refresh();    // access global function refresh()
}


void Ncurses::move_cursor(Coord p)
{
    move(p.y, p.x);
}


/** Turn off input echo and hide cursor 
 */
void Ncurses::noecho_mode()
{
    noecho();
    curs_set(0); 
}

/** Turn back on input echo and show cursor 
 */
void Ncurses::echo_mode()
{
    echo();
    curs_set(1);
}

char Ncurses::get_char()
{
    return getch();    
}

std::string Ncurses::get_line()
{
    char input[80];
    getnstr(input, 79);
    return input;    
}
