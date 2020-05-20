#ifndef MONSTER_H
#define MONSTER_H
#include"rpgobj.h"

class Monster:public RPGObj
{
public:
    Monster();
    void move(int direction, int steps);
    void onErase();
};

#endif // MONSTER_H
