#ifndef NCURSES_SIMPLE_WRAP
#define NCURSES_SIMPLE_WRAP

#ifdef _WIN32 // Windows -> Compile with g++ -std=c++20 .\main.cpp -o .\main -lncursesw
    #include <ncurses/ncurses.h>
#else
    #include <ncurses.h>
#endif
    #include <string>

struct Point
{
    int x{};
    int y{};
};


class Ncurses 
{
    private:
    WINDOW* win;
    Point max{};

    public:
    Ncurses();
    ~Ncurses();
    void add(char c, Point p);
    void add(int i, Point p);
    void add(double d, Point p);
    void add(std::string_view s, Point p);
    void refresh();
    void move_cursor(Point p);
    void nap(int ms);
    void noecho_mode();
    void echo_mode();
    char get_char();
    std::string get_line();
    void press_any_key();
};


#endif