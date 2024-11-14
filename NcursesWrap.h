#ifndef NCURSES_SIMPLE_WRAP
#define NCURSES_SIMPLE_WRAP

#ifdef _WIN32 // Windows -> Compile with g++ -std=c++20 .\main.cpp -o .\main -lncursesw
    #include <ncurses/ncurses.h>
#else
    #include <ncurses.h>
#endif
    #include <string>

struct Coord
{
    int x{};
    int y{};
};


class Ncurses 
{
    private:
    WINDOW* win;
    Coord max{};

    public:
    Ncurses();
    ~Ncurses();
    void add(char c, Coord p);
    void add(int i, Coord p);
    void add(double d, Coord p);
    void add(float f, Coord p);
    void add(const char* str, Coord p);
    void add(std::string& str, Coord p) const;
    void add(char c);
    void add(int i);
    void add(double d);
    void add(float f);
    void add(const char* str);
    void add(std::string& str) const;
    void refresh();
    void move_cursor(Coord p);
    void nap(int ms);
    void noecho_mode();
    void echo_mode();
    char get_char();
    std::string get_line();
    void press_any_key();
};


#endif