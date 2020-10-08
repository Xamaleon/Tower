#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <QMessageBox>
#include <mainwindow.h>


GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    int widthView = ui->graphicsView->minimumWidth() - 2;
    int heightView = ui->graphicsView->minimumHeight() - 2;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(QRect(0,0,widthView,heightView));

    scene->addRect(QRect(T1,200,6,200),QPen(Qt::black), Qt::black);
    scene->addRect(QRect(10,GROUND_Y,290,6),QPen(Qt::black), Qt::black);


    scene->addRect(QRect(T2,200,6,200),QPen(Qt::black), Qt::black);
    scene->addRect(QRect(354,GROUND_Y,290,6),QPen(Qt::black), Qt::black);

    scene->addRect(QRect(T3,200,6,200),QPen(Qt::black), Qt::black);
    scene->addRect(QRect(704,GROUND_Y,290,6),QPen(Qt::black), Qt::black);


    towersKeeper = new TowerKeeper(scene);
}

GameWindow::~GameWindow()
{
    delete ui;
    delete towersKeeper;
    qDebug() << "gameWidget delete destruction!";
}


void GameWindow::slotBackMenu()
{
    this->close();
}



void GameWindow::on_firstToSecond_clicked()
{
    if(towersKeeper->move(FIRST, SECOND)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::on_firstToThird_clicked()
{
    if(towersKeeper->move(FIRST, THIRD)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::on_secondToFirst_clicked()
{
    if(towersKeeper->move(SECOND, FIRST)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::on_secondToThird_clicked()
{
    if(towersKeeper->move(SECOND, THIRD)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::on_thirdToFirst_clicked()
{
    if(towersKeeper->move(THIRD, FIRST)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::on_thirdToSecond_clicked()
{
    if(towersKeeper->move(THIRD, SECOND)){
        score += 1;
        checkForComplite();
    }
}

void GameWindow::setButtonsLock(bool lock)
{
    ui->firstToThird->  setDisabled(lock);
    ui->firstToSecond-> setDisabled(lock);
    ui->secondToFirst-> setDisabled(lock);
    ui->secondToThird-> setDisabled(lock);
    ui->thirdToFirst->  setDisabled(lock);
    ui->thirdToSecond-> setDisabled(lock);
}

void GameWindow::showResult()
{
    ScoreRecorder * messageWidget = new ScoreRecorder(score);
    connect(messageWidget, &ScoreRecorder::signalCloseEvent, this, [&](){
        setButtonsLock(false);
        // хоть на луну тут лети
        // 1. хочу теслу на новый год
        // 2. съездить на бали
        // 3. носки с медведем
        // ...
    });
    messageWidget->setAttribute(Qt::WA_DeleteOnClose);
    messageWidget->show();
}

bool GameWindow::checkForComplite()
{
    if(towersKeeper->isFull()){
        setButtonsLock(true);
        showResult();
        return true;
    }
    return false;
}




