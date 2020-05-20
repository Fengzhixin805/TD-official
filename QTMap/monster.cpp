#include "monster.h"

Monster::Monster()
{

}
void Monster::move(int direction, int steps){
    switch (direction){
        case 1:
            this->_pos_y -= steps;
            break;
        case 2:
            this->_pos_y += steps;
            break;
        case 3:
            this->_pos_x -= steps;
            break;
        case 4:
            this->_pos_x += steps;
            break;
    }

}
void Monster::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/crash.mp3"));
    player->setVolume(30);
    player->play();
}

