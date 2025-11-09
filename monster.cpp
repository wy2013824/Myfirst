//
// Created by wy on 2025/9/12.
//

#include "shoot.hpp"

void Monster::draw() {
    move(y,x);
    addch(ch);
    refresh();
}

void Monster::clean() {
    move(y,x);
    addch(' ');
    refresh();
}

void Monster::create() {

    x=std::rand()%(HEIGHT-1-1+1)+1;
    y=std::rand()%(WIDTH-1-1+1)+1;
    mode=std::rand()%(4+1);

    if (mode==0) {
        ch='@';
        life=5;
    }
    else {
        ch='O';
        life=2;
    }
}

void Monster::moveit() {

    int able=std::rand()%(8-1+1)+1;
    int r=std::rand()%(4-1+1)+1;

    if (able==4){
        switch (r) {
            case 1:
                clean();
                --y;
                if (y<1) ++y;
                draw();
                break;
            case 2:
                clean();
                ++y;
                if (y>WIDTH-1) --y;
                draw();
                break;
            case 3:
                clean();
                --x;
                if (x<1) ++x;
                draw();
                break;
            case 4:
                clean();
                ++x;
                if (x>HEIGHT-1) --x;
                draw();
                break;
        }
    }
}




