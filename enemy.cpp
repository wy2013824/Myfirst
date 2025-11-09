//
// Created by wy on 2025/10/25.
//
int score=0;
int num=1;
int times=3;

#include "shoot.hpp"

void Enemy::create() {

    int able=std::rand()%(64-1+1)+1;
    if (able==1) {
        mon.emplace_back();
        mon.back().create();
    }
}

void Enemy::moveit() {
    for (int i = 0; i < mon.size(); i++) {
        mon[i].moveit();
        mon[i].draw();
    }
}
void Enemy::attack(Player &p) {
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    for (int i = 0; i < mon.size(); i++) {
        if (mon[i].x == p.x && mon[i].y == p.y) {
            mon.clear();
            clear();
            attron(COLOR_PAIR(1));
            mvprintw(15, 20, "You died!");
            refresh();
            mvprintw(16, 20, "Score: %d", score);
            refresh();
            attroff(COLOR_PAIR(1));

            p.x=std::rand()%(HEIGHT-1-1+1)+1;
            p.y=std::rand()%(WIDTH-1-1+1)+1;

            p.bullets.clear();
            std::this_thread::sleep_for(std::chrono::seconds(3));

            --times;
            if (times<=0) {
                score=0;
                clear();
                attron(COLOR_PAIR(2));
                num=1;
                for (int i=0;i<WIDTH;++i) {
                    for (int j=0;j<HEIGHT;++j) {
                        printw(" ");
                        refresh();
                    }
                    printw("\n");
                    refresh();
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                attroff(COLOR_PAIR(2));
                times=3;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            clear();
            wall();
        }
    }
}

void Enemy::shooted(Player& p) {

    for (int i=0;i<mon.size();i++) {
        for (int ii=0;ii<p.bullets.size();ii++) {
            if (mon[i].x == p.bullets[ii].x && mon[i].y == p.bullets[ii].y) {
                p.bullets[ii].clean();
                p.bullets.erase(p.bullets.begin()+ii);
                mon[i].life--;

                if (mon[i].life<=0) {
                    mon[i].clean();
                    mon.erase(mon.begin()+i);
                    score++;

                    if (score>=16*num) {
                        clear();
                        mon.clear();
                        p.bullets.clear();
                        score=0;
                        num++;

                        mvprintw(15,20,"You win!");
                        refresh();
                        mvprintw(16, 20, "Level: %d", num);
                        refresh();

                        p.x=std::rand()%(HEIGHT-1-1+1)+1;
                        p.y=std::rand()%(WIDTH-1-1+1)+1;

                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        clear();
                        wall();
                    }
                }
            }
        }
    }
}
