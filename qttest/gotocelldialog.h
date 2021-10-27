#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

namespace Ui {
class GoToCellDialog;
}

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::GoToCellDialog *ui;




};

#endif // GOTOCELLDIALOG_H
