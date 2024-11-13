#ifndef NCURSES_SIMPLE_WRAP
#define NCURSES_SIMPLE_WRAP

#ifdef _WIN32 // Windows -> Compile with g++ -std=c++20 .\main.cpp -o .\main -lncursesw
    #include <ncurses/ncurses.h>
#else
    #include <ncurses.h>
#endif
    #include <string>



class Ncurses 
{
    private:
    WINDOW* win;
    int max_x;
    int max_y;

    public:
    Ncurses();
    ~Ncurses();
    void add(char c, int x, int y);
    void add(int i, int x, int y);
    void add(double d, int x, int y);
    void add(std::string_view s, int x, int y);
    void refresh();
    void move_cursor();
    void nap(int ms);
    void noecho_mode();
    void echo_mode();
    char get_char();
    std::string get_line();
    void press_any_key();
};


#endif