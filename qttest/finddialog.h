#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT

public:
    findDialog(QWidget *parent = 0);

    ~findDialog();
signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);
private:
    Ui::findDialog *ui;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
private slots:
    void findClicked();
    void enableFindButton(const QString &text);
};

#endif // FINDDIALOG_H
