#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMovie>
#include <QLabel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    bool isplaying;
    QMovie *movie;


};

#endif // DIALOG_H
