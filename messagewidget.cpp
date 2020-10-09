#include "messagewidget.h"
#include "ui_messagewidget.h"
#include "gamewindow.h"
#include <QDebug>
ScoreRecorder::ScoreRecorder(int score, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/resource/img/record.png"));
    ui->lbl_score->setNum(score);
}

ScoreRecorder::~ScoreRecorder()
{
    delete ui;
    emit signalCloseEvent();
    qDebug() << "ScoreRecorder destruction!";

}

void ScoreRecorder::on_btn_writeInTable_clicked()
{

}


