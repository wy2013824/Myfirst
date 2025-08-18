/
// Created by wy on 2025/8/8.
//

#include "shoot.hpp"

void bullet::draw() {
    move(y,x);
    addch(bl);
}

void bullet::clean() {
    move(y,x);
    addch(' ');
}
void bullet::shoot() {
    switch (d) {
        case UP:
            clean();
            y--;
            break;
        case DOWN:
            clean();
            y++;
            break;
        case LEFT:
            clean();
            x--;

            break;
        case RIGHT:
            clean();
            x++;
            break;
        default:break;
    }
    draw();
}

void wall() {

    for (int i=0;i<getmaxx(stdscr);i++) {
        move(0,i);
        printw("#");

        move(getmaxy(stdscr)-1,i);
        printw("#");

    }

    for (int i=0;i<getmaxy(stdscr);i++) {
        move(i,0);
        printw("#");

        move(i,getmaxx(stdscr)-1);
        printw("#");
    }

}
