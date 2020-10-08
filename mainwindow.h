#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets.h"
#include "gamewindow.h"
#include "tablewidget.h"
#include "messagewidget.h"
#include <QSqlDatabase>

#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_exit_clicked();

    void on_exit_triggered();

    void on_btn_newGame_clicked();

    void on_back_menu_triggered();

    void on_btn_table_clicked();

    void slotCloseEvent();

    void slotShowMessageWidget();

signals:
    void signalBackMenu();
public slots:
    void slotCloseWidget();
private:
    Ui::MainWindow *ui;
    GameWindow *gameWindow {nullptr};
    TableWidget *tableWidget {nullptr};

    QSqlDatabase db;

    void deleteWidget(const int indexWidget);
    void setting(const WIDGETS index);

};
#endif // MAINWINDOW_H
