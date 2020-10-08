#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QDesktopWidget>
#include <QStyle>
#include <QGraphicsScene>
#include "shape.h"
#include "widgets.h"
#include "towerkeeper.h"
#include <messagewidget.h>


namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
public slots:
    void slotBackMenu();
signals:
    void signalLockButton();
    void signalCloseEvent();
private slots:
    void on_firstToSecond_clicked();

    void on_firstToThird_clicked();

    void on_secondToFirst_clicked();

    void on_secondToThird_clicked();

    void on_thirdToFirst_clicked();

    void on_thirdToSecond_clicked();

    void setButtonsLock(bool lock);

    void showResult();




private:
    bool checkForComplite();

    Ui::GameWindow *ui;
    QGraphicsScene *scene {nullptr};
    TowerKeeper *towersKeeper {nullptr};
    ScoreRecorder *messageWidget {nullptr};
    int score = 0;

};

#endif // GAMEWINDOW_H
