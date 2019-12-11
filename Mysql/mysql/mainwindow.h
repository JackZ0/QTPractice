#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlTableModel>

#include <QPaintEvent>
#include <QPen>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    void connect_mysql();
    QSqlQuery sqlquery;
    void Mysqlquery(QString StrQuery);
    void setModel();
    void Insert();
    bool Delete(QString str, QString tablename);
    bool Update(QStringList qstrl1, QStringList qstrl2, int id, QString tablename);
    bool Insert(QStringList qstrl1, QStringList qstrl2, QString tablename);
    void paintEvent(QPaintEvent *);



private slots:
   void setView();
   void close();

//    QTableView *table;
};

#endif // MAINWINDOW_H
