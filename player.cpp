/
// Created by wy on 2025/8/8.
//

#include "shoot.hpp"

void player::draw() {
    move(y,x);
    addch(pl);

}

void player::clean() {
    move(y,x);
    addch(' ');

}

void player::moveit() {
    switch (d) {
        case UP:
            pl='A';
            clean();
            if (!(y<2)) {
                y--;
            }
            break;
        case DOWN:
            pl='V';
            clean();
            if (!(y>getmaxy(stdscr)-3)) {y++;}
            break;
        case LEFT:
            pl='<';
            clean();
            if (!(x<2)) {x--;}

            break;
        case RIGHT:
            pl='>';
            clean();
            if (!(x>getmaxx(stdscr)-3)) {x++;}
            break;
        default:break;
    }
    draw();
}
 void player::moveplayer() {

    usleep(100000);
    switch (getch()) {
        case KEY_UP:
            d=UP;
            moveit();
            break;
        case KEY_DOWN:
            d=DOWN;
            moveit();
            break;
        case KEY_LEFT:
            d=LEFT;
            moveit();
            break;

        case KEY_RIGHT:
            d=RIGHT;
            moveit();
            break;
        case ' ':
            shoot();
            break;
        default:break;

    }


}

void player::shoot() {

    switch (d) {
        case UP:
        case DOWN:
            v.push_back(bullet(x,y,'|',d));
            break;
        case LEFT:
        case RIGHT:
            v.push_back(bullet(x,y,'-',d));
            break;
    }
    draw();
}

void player::autoshoot() {
    for (int i=0; i<v.size(); i++) {
        v[i].shoot();
        if (v[i].x<1 || v[i].x>getmaxx(stdscr)-2) {
            v[i].clean();
            v.erase(v.begin()+i);
            wall();
        }
        if (v[i].y<1 || v[i].y>getmaxy(stdscr)-2) {
            v[i].clean();
            v.erase(v.begin()+i);
            wall();
        }
        draw();
    }
}
