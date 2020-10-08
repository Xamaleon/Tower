#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

private slots:
    void on_btn_back_clicked();

signals:
    void signalCloseWidget();
private:
    Ui::TableWidget *ui;
    QSqlTableModel *model {nullptr};
    void settingView();
};

#endif // TABLEWIDGET_H
