#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(int cw,int ch, int cm,QWidget *parent = nullptr);
    ~ConfigDialog();
    int _width;
    int _height;
    int _mines;

    virtual void accept() override;

private:
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H
