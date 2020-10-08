#ifndef TOWERKEEPER_H
#define TOWERKEEPER_H

#include <QWidget>
#include <QGraphicsScene>
#include <vector>
#include <stack>
#include "shape.h"

using namespace std;

class TowerKeeper : public QWidget
{
public:
    TowerKeeper(QGraphicsScene *scene);
    ~TowerKeeper();

    bool move(Number from, Number to);

    bool isFull();
private:
    QGraphicsScene *scene {nullptr};
    vector<stack<Shape*>*> towers;
    bool isStackFull = false;

};

#endif // TOWERKEEPER_H
