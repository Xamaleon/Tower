#ifndef WIDGETS_H
#define WIDGETS_H

#include <QString>

enum WIDGETS{
    MAIN_WIDGET,
    GAME_WIDGET,
    TABLE_WIDGET,
    INSTRUCTION_WIDGET
};

struct Player{
    QString name;
    int score = 0;
};

#endif // WIDGETS_H
