#ifndef OPERATIONDIALOG_H
#define OPERATIONDIALOG_H

#include <QDialog>

namespace Ui {
class operationDialog;
}

class operationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit operationDialog(QWidget *parent = nullptr);
    ~operationDialog();

private:
    Ui::operationDialog *ui;
};

#endif // OPERATIONDIALOG_H
