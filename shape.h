#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsRectItem>
#include <QBrush>
// центры осей башен
const int T1 = 150;
const int T2 = 500;
const int T3 = 850;

// положение горизонта
const int GROUND_Y = 394;

// базовые множители высоты и ширины
const int BASE_HEIGHT = 30;
const int BASE_WIDTH = 80;

enum Number{
    FIRST = 0,
    SECOND,
    THIRD,
};

enum Size  {
    little = 1,
    middle = 2,
    bigger = 3,
};

class Pos
{
public:
    Pos(int row = 0, int col = 0);

    int getX(Size size);
    int getY();
private:
    Size size;
    int row,col;
};



class Shape : public QGraphicsRectItem
{
public:
    Shape(Size size, Pos pos, QBrush color);

    void move(Pos pos);
    int getSize();
private:

    Size sizes;
    Pos p;
};

#endif // SHAPE_H
