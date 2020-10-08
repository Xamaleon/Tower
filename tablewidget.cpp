#include "tablewidget.h"
#include "ui_tablewidget.h"
#include <QDebug>
#include "mainwindow.h"
TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("SCORE");

    ui->tableView->setModel(model);

    settingView();




}

TableWidget::~TableWidget()
{
    delete ui;
    delete model;
    qDebug() << "tableWidget delete destruction!";
}


void TableWidget::on_btn_back_clicked()
{
    emit signalCloseWidget();
    qDebug() << "TableWidget (back) closed success!";
    this->close();
}

void TableWidget::settingView()
{
    model->setEditStrategy(QSqlTableModel::OnManualSubmit); // кэширование до активации сигналаж
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Запрещаем вносить изменения в таблицу
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Растягиваем последнюю колонку по конца представления таблицы
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();

    ui->tableView->horizontalHeader()->hideSection(0);
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Имя"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Количество ходов"));

    model->select();

}


