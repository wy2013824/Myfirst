//
// Created by wy on 2025/8/8.
//

#include "shoot.hpp"

void Bullet::draw() {
    move(y,x);
    addch(ch);
}

void Bullet::clean() {
    move(y,x);
    addch(' ');
}

void Bullet::moveit() {
    switch (d) {
        case up:
            clean();
            --y;
            draw();
            break;
        case down:
            clean();
            ++y;
            draw();
            break;
        case left:
            clean();
            --x;
            draw();
            break;
        case right:
            clean();
            ++x;
            draw();
            break;
    }
}

void wall() {
    for (int i=0;i<WIDTH;i++) {
        mvprintw(i,0,"#");
        refresh();

        mvprintw(i,HEIGHT,"#");
        refresh();
    }

    for (int i=0;i<HEIGHT;i++) {
        mvprintw(0,i,"#");
        refresh();

        mvprintw(WIDTH,i,"#");
        refresh();
    }
    printw("#");
    refresh();
}
