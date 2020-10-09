#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include "widgets.h"

namespace Ui {
class MessageWidget;
}

class ScoreRecorder : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreRecorder(int score, QWidget *parent = nullptr);
    ~ScoreRecorder();
signals:
   void signalCloseEvent();

private slots:
    void on_btn_writeInTable_clicked();

private:
    Ui::MessageWidget *ui;
};

#endif // MESSAGEWIDGET_H
