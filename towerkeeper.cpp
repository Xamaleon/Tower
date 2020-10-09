#include "towerkeeper.h"


TowerKeeper::TowerKeeper(QGraphicsScene *scene)
{
    this->scene = scene;

    for(int i = 0; i < 3; i++){
        towers.push_back(new stack<Shape*>);
    }

    towers.at(0)->push(new Shape(bigger, Pos(1,1), Qt::green));
    scene->addItem(towers.at(0)->top());

    towers.at(0)->push(new Shape(middle, Pos(2,1), Qt::red));
    scene->addItem(towers.at(0)->top());

    towers.at(0)->push(new Shape(little, Pos(3,1), Qt::blue));
    scene->addItem(towers.at(0)->top());

}

TowerKeeper::~TowerKeeper()
{
    for(auto tower : towers){
        while(tower->size())
        {
            delete tower->top();
            tower->pop();
        }
    }
}

bool TowerKeeper::move(Number from, Number to)
{
    stack<Shape*> *src = towers.at(from);
    stack<Shape*> *dst = towers.at(to);

    if(src->empty() || dst->size() >= 3){
        isStackFull = true;
        return false;
    }
    else if(!dst->empty()){
        if(dst->top()->getSize() == little || src->top()->getSize() == bigger){
            return false;
        }
    }

    dst->push(src->top());
    src->pop();

    dst->top()->move(Pos(dst->size(), to + 1));
    return true;

}

bool TowerKeeper::isFull()
{
    for(auto &t : towers){
        while (t->size() == 3 && towers.at(0)->size() != 3) {
            return true;
        }
    }
    return false;
}
