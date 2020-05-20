#include "world.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include<iostream>
#include<ctime>

using namespace std;

World::~World(){
    //delete this->_monster;
}
int getTime() {
  return clock()/CLOCKS_PER_SEC;
}

void World::initWorld(string mapFile){
    //TODO 下面的内容应该改为从地图文件装载
    //player 5 5
    int i = 0;
      int lastTime = 0;
      while (1) {
        int now = getTime();
        if (now - lastTime > 0) {
            Monster *q = new Monster;
            q->initObj("player");
            q->setPosX(3);
            q->setPosY(-1);
            this->_monster.push_back(q);
            i++;
          lastTime = now;
}if(i==10){break;}}


    RPGObj *z = new RPGObj;
    z->initObj("stone");
    z->setPosX(4);
    z->setPosY(3);
    this->_objs.push_back(z);

    RPGObj *y = new RPGObj;
    y->initObj("tree");
    y->setPosX(21);
    y->setPosY(13);
    this->_objs.push_back(y);

    for(int k=0;k<4;k++){
        RPGObj *p1 = new RPGObj;
        p1->initObj("road1");
        p1->setPosX(11+k);
        p1->setPosY(5);
        this->_objs.push_back(p1);
    }

    for(int i=0;i<3;i++){
        RPGObj *x =new RPGObj;
        x->initObj("road_s");
        x->setPosX(3);
        x->setPosY(3*i);
        this->_objs.push_back(x);
        if(i==2){
            RPGObj *x =new RPGObj;
            x->initObj("road_s");
            x->setPosX(11);
            x->setPosY(6);
            this->_objs.push_back(x);
            for(int j=0;j<3;j++){
            RPGObj *x =new RPGObj;
            x->initObj("road_s");
            x->setPosX(14);
            x->setPosY(6+j*3);
            this->_objs.push_back(x);
        }}
    }
    for(int i=0;i<3;i++){
        RPGObj *x =new RPGObj;
        x->initObj("road_h");
        x->setPosX(3*i+3);
        x->setPosY(9);
        this->_objs.push_back(x);
        if(i==2){
            for(int k=0;k<2;k++){
                RPGObj *x =new RPGObj;
                x->initObj("road_h");
                x->setPosX(3*k+15);
                x->setPosY(14);
                this->_objs.push_back(x);
            }
        }
    }

    RPGObj *p3 = new Fruit;
    p3->initObj("fruit");
    p3->setPosX(6);
    p3->setPosY(8);    
    this->_objs.push_back(p3);

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/hdl.mp3"));
    player->setVolume(30);
    player->play();


}


void World::show(QPainter * painter){
    int n = this->_objs.size();
    for (int i=0;i<n;i++){
        this->_objs[i]->show(painter);
    }
    int a = this->_monster.size();
    for (int i=0;i<a;i++){
        this->_monster[i]->show(painter);
    }


}

void World::eraseObj(int x, int y){
    vector<RPGObj*>::iterator it;
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()=="fruit"); //
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);//位置重叠

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }
}

void World::handlePlayerMove(int direction, int steps){
    //int n=sizeof(_monster);
    int x =  this->_monster[0]->getNextX(direction);
    int y = this->_monster[0]->getNextY(direction);
    this->eraseObj(x,y);
    this->_monster[0]->move(direction, steps);
    }


