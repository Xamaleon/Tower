#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    db.open() ? qDebug() << "Database connect success!" : qDebug() << "Warning: Failet to connect database!";

    setting(WIDGETS::MAIN_WIDGET);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_btn_newGame_clicked()
{
    gameWindow = new GameWindow(this);
    ui->stackedWidget->insertWidget(WIDGETS::GAME_WIDGET, gameWindow);
    setting(WIDGETS::GAME_WIDGET);

    connect(this, &MainWindow::signalBackMenu, gameWindow, &GameWindow::slotBackMenu);
    connect(gameWindow, &GameWindow::signalCloseEvent, this, &MainWindow::slotCloseEvent);

}

void MainWindow::on_back_menu_triggered()
{
    emit signalBackMenu();
    int indexWidget = ui->stackedWidget->currentIndex();
    deleteWidget(indexWidget);
    setting(WIDGETS::MAIN_WIDGET);

}

void MainWindow::on_btn_table_clicked()
{
    tableWidget = new TableWidget(this);
    ui->stackedWidget->insertWidget(WIDGETS::TABLE_WIDGET, tableWidget);
    setting(WIDGETS::TABLE_WIDGET);

    connect(tableWidget, &TableWidget::signalCloseWidget, this, &MainWindow::slotCloseWidget);
}

void MainWindow::slotCloseEvent()
{
    setting(WIDGETS::MAIN_WIDGET);
    deleteWidget(WIDGETS::GAME_WIDGET);
}


void MainWindow::slotCloseWidget()
{
    setting(WIDGETS::MAIN_WIDGET);
}

void MainWindow::deleteWidget(const int indexWidget)
{
    switch (indexWidget) {
    case 0:
        qDebug() << "You are on the menu";
        break;
    case 1:
        delete gameWindow;
        break;
    case 2:
        delete tableWidget;
        break;
    default:
        qDebug() << "Incorrect value";
    }
}

void MainWindow::setting(const WIDGETS indexWidget)
{
    indexWidget == WIDGETS::MAIN_WIDGET ? ui->menubar->setVisible(false) : ui->menubar->setVisible(true);

    switch (indexWidget) {
    case MAIN_WIDGET:
        this->setWindowTitle("Главное меню");
        this->setWindowIcon(QIcon(":/resource/img/main_ico.png"));
        ui->stackedWidget->setCurrentIndex(indexWidget);
        db.close();   qDebug() << "Database closed!";
        break;
    case TABLE_WIDGET:
        this->setWindowTitle("Рекорды");
        this->setWindowIcon(QIcon(":/resource/img/record.png"));
        ui->stackedWidget->setCurrentIndex(indexWidget);
        db.open();    qDebug() << "Database open!";
        break;
    case INSTRUCTION_WIDGET:
        this->setWindowIcon(QIcon(":/resource/img/info.png"));
        break;
    case GAME_WIDGET:
        this->setWindowTitle("Ханойская башня");
        ui->stackedWidget->setCurrentIndex(indexWidget);
        db.open();    qDebug() << "Database open!";
        break;
    default:
        qDebug() << "incorrect value select";
        ;
    }
}



