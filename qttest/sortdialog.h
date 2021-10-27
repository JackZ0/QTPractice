#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class sortDialog;
}

class sortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sortDialog(QWidget *parent = nullptr);
    ~sortDialog();

private:
    Ui::sortDialog *ui;
    void setColumnRange(QChar first,QChar last);
};

#endif // SORTDIALOG_H
