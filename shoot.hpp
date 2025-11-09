//
// Created by wy on 25-7-31.

#ifndef SHOOT_HPP
#define SHOOT_HPP

#define WIDTH 25
#define HEIGHT 50

#include <vector>
#include <thread>
#include <chrono>
#include <ncurses.h>

void wall();

enum Direct{ up, down, left, right};

class Bullet {
public:
    Direct d;
    char ch;
    int x,y;

    Bullet(){}
    Bullet(Direct d,char ch, int x, int y): d(d), ch(ch), x(x), y(y) {}

    void moveit();
    void draw();
    void clean();
};

class Player {
public:
    int x,y;
    char ch;
    Direct d;
    std::vector<Bullet> bullets;

    Player(){}
    Player(Direct d,char ch, int x, int y): d(d), ch(ch), x(x), y(y) {}

    void draw();
    void moveit();
    void clean();
    void shoot();
    void autoshoot();
};

class Monster {
public:
    int mode;
    int x,y;
    char ch;
    int life;

    Monster() {}

    void create();
    void moveit();
    void draw();

    void clean();

};

class Enemy {
public:
    std::vector<Monster> mon;

    void create();
    void moveit();
    void shooted(Player& p);
    void attack(Player& p);

};
#endif //SHOOT_HPP
