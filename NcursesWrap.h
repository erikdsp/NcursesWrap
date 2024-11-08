#ifndef NCURSES_SIMPLE_WRAP
#define NCURSES_SIMPLE_WRAP

#ifdef _WIN32 // Windows -> Compile with g++ -std=c++20 .\main.cpp -o .\main -lncursesw
    #include <ncurses/ncurses.h>
#else
    #include <ncurses.h>
#endif


class Ncurses 
{
    private:
    WINDOW* win;
    int max_x;
    int max_y;

    public:
    Ncurses() {}
    ~Ncurses(){}
    void pause(){}
    void nap(int ms){}
    void refresh(){}
    void add(char c, int x, int y){}
    void add(int i, int x, int y){}
};


#endif