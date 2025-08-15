

#include "shoot.hpp"

int main()
{
    initscr();
    resize_term(32,50);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    noecho();
    wall();
    tank t;
    t.create();
    player p(10,10,'A');
    p.draw();
    while (true) {
        p.moveplayer();
        t.moveit();
        t.shoot();
        t.shooted(p);
        t.autoshoot(p);
        p.autoshoot();

        mvprintw(31,0,"Blood: %d",t.blood);
    }

    getch();
    endwin();

    return 0;
}
