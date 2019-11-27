#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSpinBox>
class QSpinBox;
class QSlider;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
signals:

private:
    QSpinBox *spin;
    QSlider *slider;
};

#endif // DIALOG_H
