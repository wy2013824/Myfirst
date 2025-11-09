//
// Created by wy on 2025/8/8.
//

#include "shoot.hpp"

void Player::draw() {
    move(y,x);
    addch(ch);
    refresh();
}

void Player::clean() {
    move(y,x);
    addch(' ');
    refresh();
}

void Player::moveit() {
    int key=getch();

   switch (key) {
       case 'w':
           d=up;
            ch='A';
            clean();
            if (y>1) {
                --y;
            }
            draw();
           break;
       case 's':
           d=down;
            ch='V';
            clean();
            if (y<WIDTH-1) {
                ++y;
            }
            draw();
           break;
       case 'a':
           d=left;
            ch='<';
            clean();
            if (x>1) {
                --x;
            }
            draw();
           break;
       case 'd':
           d=right;
            ch='>';
            clean();
            if (x<HEIGHT-1) {
            ++x;
            }
            draw();
            break;
       case ' ':
           shoot();
           draw();
           break;
       case '\t':

           nodelay(stdscr, false);
           getch();
           nodelay(stdscr, true);
           clear();
           wall();
           break;
   }
}

void Player::shoot() {
    switch (d) {
        case up:
        case down:
            bullets.push_back(Bullet(d,'|',x,y));
            break;
        case left:
        case right:
            bullets.push_back(Bullet(d,'-',x,y));
            break;
    }
}

void Player::autoshoot() {
    for (int i=0;i<bullets.size();i++) {
        bullets[i].moveit();
       if (bullets[i].x<1 || bullets[i].x>HEIGHT) {
            bullets[i].clean();
            bullets.erase(bullets.begin()+i);
            wall();
            break;
        }
        if (bullets[i].y<1 || bullets[i].y>WIDTH) {
            bullets[i].clean();
            bullets.erase(bullets.begin()+i);
            wall();
            break;
        }
    }
}
