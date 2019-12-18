#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QTreeView>
#include <QTreeWidget>
#include <QStandardItem>
#include "controldelegate.h"

class SpinboxDelegate;
class ComboboxDelegate;

//namespace Ui {
//class StuInfoManagementSystem;
//}

class StuInfoManagementSystem: public QWidget
{
    Q_OBJECT

public:
    explicit StuInfoManagementSystem(QWidget *parent = 0);
    ~StuInfoManagementSystem();

public:
    void contextMenuEvent(QContextMenuEvent *e);
    void menuBarInit(); //�˵���ʼ��
    void tableWidgetInit(); //table�ؼ���ʼ��
    void treeWidgetInit();
    void closeEvent(QCloseEvent *event);//����ر�ʱ����
    void upDateTableView();

private:
    QMenu *OperationMenu;  //�����˵�
    QAction *DeleteAction;
    QAction *InsertAction;

    QMenu *helpMenu; //�����˵�
    QAction *aboutAction;
    QAction *aboutQtAction;

    QMenu *schoolAndGradeMenu;
    QAction *addSchoolAction;
    QAction *addGradeAction;
    QAction *delSchoolOrGradeAction;

    QMenuBar* menuBar;

    SpinboxDelegate* ageSpinbox;//����
    SpinboxDelegate* heightSpinbox; //���
    ComboboxDelegate* schoolCombobox;//ѧУ
    ComboboxDelegate* gradeCombobox;//�༶
    ComboboxDelegate* sexCombobox; //�Ա�
    ComboboxDelegate* statusCombobox; //������ò

private slots:
    void sltInsertAction();
    void sltDeleteAction();

    void sltAddSchoolAction();
    void sltAddGradeAction();
    void sltDelSchoolOrGradeAction();

    void sltAboutAction();

    void SlotItemClicked(QTreeWidgetItem *item, int column);

private:
    QStandardItemModel* tableModel;
    QTableView* table;
    QStandardItem *dataSources;

    QTreeWidget *treeWidget;

//private:
//    Ui::StuInfoManagementSystem *ui;
};

#endif // WIDGET_H
