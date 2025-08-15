//
// Created by wy on 25-7-31.

#ifndef SHOOT_HPP
#define SHOOT_HPP

#include <ncurses.h>
#include <cstdlib>
#include <vector>
#include <conio.h>
void wall();

enum direction { UP, DOWN, LEFT, RIGHT };

class bullet {
public:
    int x,y;
    direction d;
    char bl;
    bullet(int x,int y,char bl,direction d): x(x),y(y),bl(bl),d(d) {}
    bullet(int x,int y,char bl):x(x),y(y),bl(bl){}
    void draw();
    void clean();
    void shoot();
};
class player {

public:
    int x;
    int y;
    std::vector<bullet>  v;
    direction d;
    char pl;
    player(int x,int y,char pl):x(x), y(y), pl(pl) {}
    void draw();
    void moveit();
    void clean();
    void moveplayer();
    void shoot();
    void autoshoot();
};

class tank {
    public:
    int x,y;
    int r,m;
    direction d;
    int blood;
    std::vector<bullet>  v;

    void draw() {
        move(y,x);
        addch('O');
    }
    void clean() {
        move(y,x);
        addch(' ');
    }
    void create() {
        x=rand()%45+1;
        y=rand()%25+1;
        blood=16;

    }
    void moveit() {
        m=rand()%16+1;

        switch (m) {
            case 1:
                clean();
                d=UP;
                y--;
                if (y>1) {
                    y++;
                }
                draw();
                break;
            case 2:
                d=DOWN;
                clean();
                y++;
                if (y>=getmaxy(stdscr)-1) {
                    y--;
                }
                draw();
                break;

            case 3:
                clean();
                d=RIGHT;
                x++;
                draw();
                break;
            case 4:
                clean();
                d=LEFT;
                x--;
                draw();
                break;
        }


    }
    void shoot() {
        r=rand()%8;
        if (r==4) {
            v.push_back(bullet(x,y,'*',d));
        }
    }

    void shooted(player& p) {
        for (int i=0; i<p.v.size(); i++) {
            if (p.v[i].x==x && p.v[i].y==y) {

                blood--;
                wall();
                if (blood==0) {
                    clear();
                     mvprintw(15,25,"You win");
                    getchar();
                    clear();
                    exit(0);
                }


            }
        }
    }
    void autoshoot(player& p) {
        for (int i=0;i<v.size();i++) {
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
            if (p.x==v[i].x && p.y==v[i].y) {
                clear();
                mvprintw(15,25,"You died!\n");
                getchar();
                clear();
                blood=16;

                v.clear();
                p.v.clear();
            }

            for (int ii=0;ii<p.v.size();ii++) {
                if (v[i].x==p.v[ii].x && v[i].y==p.v[ii].y) {
                    v[i].clean();
                    v.erase(v.begin()+i);
                    p.v[ii].clean();
                    p.v.erase(v.begin()+ii);
                    break;
                }
            }
            draw();
        }
    }
};

#endif //SHOOT_HPP
