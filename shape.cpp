#include "shape.h"


Shape::Shape(Size size, Pos pos, QBrush color)
{
    this->sizes = size;
    this->setRect(0, 0, size * BASE_WIDTH, BASE_HEIGHT);
    this->setBrush(color);
    move(pos);
}

int Shape::getSize()
{
    return sizes;
}

void Shape::move(Pos pos)
{
    this->p = pos;
    this->setPos(p.getX(sizes),p.getY());

}

Pos::Pos(int row, int col)
{
    this->row = row;
    this->col = col;
}

int Pos::getX(Size size)
{
    this->size = size;
    int towerCenter = col == 1? T1 : col == 2? T2: T3;
    return towerCenter - size * BASE_WIDTH / 2 ;
}

int Pos::getY()
{
    return  GROUND_Y - BASE_HEIGHT * row;
}
