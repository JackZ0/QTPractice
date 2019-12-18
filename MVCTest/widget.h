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
    void menuBarInit(); //菜单初始化
    void tableWidgetInit(); //table控件初始化
    void treeWidgetInit();
    void closeEvent(QCloseEvent *event);//程序关闭时触发
    void upDateTableView();

private:
    QMenu *OperationMenu;  //操作菜单
    QAction *DeleteAction;
    QAction *InsertAction;

    QMenu *helpMenu; //帮助菜单
    QAction *aboutAction;
    QAction *aboutQtAction;

    QMenu *schoolAndGradeMenu;
    QAction *addSchoolAction;
    QAction *addGradeAction;
    QAction *delSchoolOrGradeAction;

    QMenuBar* menuBar;

    SpinboxDelegate* ageSpinbox;//年龄
    SpinboxDelegate* heightSpinbox; //身高
    ComboboxDelegate* schoolCombobox;//学校
    ComboboxDelegate* gradeCombobox;//班级
    ComboboxDelegate* sexCombobox; //性别
    ComboboxDelegate* statusCombobox; //政治面貌

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
