
extern int score;
extern int num;
#include "shoot.hpp"

int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);

    keypad(stdscr, true);
    nodelay(stdscr, true);


    Player p(up,'A',25,15);
    Enemy e;

    p.draw();
    wall();

    while (true) {
        p.moveit();
        p.draw();
        e.create();
        e.moveit();
        e.attack(p);
        e.shooted(p);

        p.autoshoot();
        mvprintw(WIDTH+1, 0, "Score: %d/%d\tLevel: %d", score,num*16,num);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    getch();
    endwin();
    return 0;
}
