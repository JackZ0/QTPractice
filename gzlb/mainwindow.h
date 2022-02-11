#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void initUi();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenu *menu1;
    QMenu *menu2;
    QMenu *menu3;
    QMenu *menu4;
    QMenu *menu5;
    QMenu *menu6;

    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;

    QAction *action6;
    QAction *action7;

    QAction *action8;
    QAction *action9;


    QDialog *m_dialog1;
    QDialog *m_dialog2;
    QDialog *m_dialog3;
    QDialog *m_dialog4;
    QDialog *m_dialog5;

private slots:
    void action1_sqlite();
    void action3_showGraphics();
    void action4_showGraphics();
    void action5_showGraphics();


};
#endif // MAINWINDOW_H
