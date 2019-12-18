#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QTableView>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QDebug>
#include <QTreeWidgetItem>
#include <controldelegate.h>
#include <QToolTip>
#include <QAbstractItemView>
#include <QStandardItem>
#include <QList>
#include <QStandardItem>
#include <QMessageBox>
#include <QInputDialog>
#include "widget.h"
#include "ui_widget.h"

StuInfoManagementSystem::StuInfoManagementSystem(QWidget *parent) : QWidget(parent)/*,ui(new Ui::StuInfoManagementSystem)*/
{
    setMinimumSize(1200,400);

    menuBarInit();//菜单初始化
    tableWidgetInit(); //table初始化
    treeWidgetInit(); //tree初始化

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(menuBar,0,0,1,2);
    grid->addWidget(treeWidget,1,0);
    grid->addWidget(table,1,1);
    setLayout(grid);

    showMaximized();
}

StuInfoManagementSystem::~StuInfoManagementSystem()
{
    //delete ui;
}

void StuInfoManagementSystem::contextMenuEvent(QContextMenuEvent *e) //重写上下文事件
{
    //方法一
    if(table->hasFocus())
    {
        OperationMenu->move(cursor().pos());
        OperationMenu->show();
    }
    if(treeWidget->hasFocus())
    {
        schoolAndGradeMenu->move(cursor().pos());
        schoolAndGradeMenu->show();
    }

    //方法二
    //    {
    //        table->addAction(InsertAction);
    //        table->addAction(DeleteAction);
    //        table->setContextMenuPolicy(Qt::ActionsContextMenu);
    //    }
}

void StuInfoManagementSystem::menuBarInit()
{
    menuBar = new QMenuBar(0);
    OperationMenu = new QMenu(QString::fromLocal8Bit("学生"));
    DeleteAction = new QAction(QString::fromLocal8Bit("删除"));
    InsertAction = new QAction(QString::fromLocal8Bit("插入"));
    OperationMenu->addAction(DeleteAction);
    OperationMenu->addAction(InsertAction);

    helpMenu = new QMenu(QString::fromLocal8Bit("帮助"));
    aboutAction = new QAction(QString::fromLocal8Bit("关于软件"));
    aboutQtAction = new QAction(QString::fromLocal8Bit("关于Qt"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    schoolAndGradeMenu = new QMenu(QString::fromLocal8Bit("学校/班级"));
    addSchoolAction = new QAction(QString::fromLocal8Bit("添加 学校"));
    addGradeAction = new QAction(QString::fromLocal8Bit("添加 班级"));
    delSchoolOrGradeAction = new QAction(QString::fromLocal8Bit("删除"));
    schoolAndGradeMenu->addAction(addSchoolAction);
    schoolAndGradeMenu->addAction(addGradeAction);
    schoolAndGradeMenu->addAction(delSchoolOrGradeAction);

    menuBar->addMenu(schoolAndGradeMenu);
    menuBar->addMenu(OperationMenu);
    menuBar->addMenu(helpMenu);


    connect(InsertAction,SIGNAL(triggered(bool)),SLOT(sltInsertAction()));
    connect(DeleteAction,SIGNAL(triggered(bool)),SLOT(sltDeleteAction()));

    connect(addSchoolAction,SIGNAL(triggered(bool)),SLOT(sltAddSchoolAction()));
    connect(addGradeAction,SIGNAL(triggered(bool)),SLOT(sltAddGradeAction()));
    connect(delSchoolOrGradeAction,SIGNAL(triggered(bool)),SLOT(sltDelSchoolOrGradeAction()));

    connect(aboutAction,SIGNAL(triggered(bool)),SLOT(sltAboutAction()));
    connect(aboutQtAction,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

}

void StuInfoManagementSystem::tableWidgetInit()
{
    //tableview初始化
    {
        table  = new QTableView;
        tableModel = new QStandardItemModel;
        table->setModel(tableModel);

        tableModel->setHorizontalHeaderItem(0,new QStandardItem(QString::fromLocal8Bit("姓名")));
        tableModel->setHorizontalHeaderItem(1,new QStandardItem(QString::fromLocal8Bit("学校")));
        tableModel->setHorizontalHeaderItem(2,new QStandardItem(QString::fromLocal8Bit("班级")));
        tableModel->setHorizontalHeaderItem(3,new QStandardItem(QString::fromLocal8Bit("年龄")));
        tableModel->setHorizontalHeaderItem(4,new QStandardItem(QString::fromLocal8Bit("性别")));
        tableModel->setHorizontalHeaderItem(5,new QStandardItem(QString::fromLocal8Bit("身高")));
        tableModel->setHorizontalHeaderItem(6,new QStandardItem(QString::fromLocal8Bit("政治面貌")));
        tableModel->setHorizontalHeaderItem(7,new QStandardItem(QString::fromLocal8Bit("个人描述")));

        // 姓名，学校（金牛小学，青羊小学），班级（1班，2班，3班），年龄，性别，身高，政治面貌，个人描述（不超过300字符）

        table->setModel(tableModel);
        table->horizontalHeader()->setStretchLastSection(true);

        table->setItemDelegateForColumn(1, new ComboboxDelegate);
        table->setItemDelegateForColumn(2,new ComboboxDelegate);
        table->setItemDelegateForColumn(3,new SpinboxDelegate(3));
        table->setItemDelegateForColumn(4,new ComboboxDelegate);
        table->setItemDelegateForColumn(5,new SpinboxDelegate(5));
        table->setItemDelegateForColumn(6,new ComboboxDelegate);

        table->setEditTriggers(QAbstractItemView::DoubleClicked);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
    }
}

void StuInfoManagementSystem::treeWidgetInit()
{
    treeWidget = new QTreeWidget;
    treeWidget->setMaximumWidth(200);
    treeWidget->setHeaderLabel(QString::fromLocal8Bit("学校/班级"));

    QTreeWidgetItem *qingYang = new  QTreeWidgetItem;
    qingYang->setText(0,QString::fromLocal8Bit("青羊小学"));

    QTreeWidgetItem  *jinNiu = new QTreeWidgetItem;
    jinNiu->setText(0,QString::fromLocal8Bit("金牛小学"));

    QStringList classlist;
    classlist << QString::fromLocal8Bit("1班") << QString::fromLocal8Bit("2班")
              << QString::fromLocal8Bit("3班");
    for(int i=0;i<=2;i++)
    {
        QTreeWidgetItem *tmp_qingYang = new  QTreeWidgetItem(qingYang);
        tmp_qingYang->setText(0,classlist.at(i));
        qingYang->addChild(tmp_qingYang);

        QTreeWidgetItem  *tmp_jinNiu = new QTreeWidgetItem(jinNiu);
        tmp_jinNiu->setText(0,classlist.at(i));
        jinNiu->addChild(tmp_jinNiu);
    }
    treeWidget->insertTopLevelItem(0,qingYang);
    treeWidget->insertTopLevelItem(1,jinNiu);
    connect(treeWidget,SIGNAL(itemPressed(QTreeWidgetItem *, int)),SLOT(SlotItemClicked(QTreeWidgetItem *, int)));
}

void StuInfoManagementSystem::closeEvent(QCloseEvent *event)
{
    qDebug()<<"Application close";
}

void StuInfoManagementSystem::sltInsertAction() //插入行操作
{
    QList<QStandardItem*> item;
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.append(new QStandardItem(NULL));
    item.at(0)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); //设置指定项的对齐方式
    item.at(7)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tableModel->insertRow(tableModel->rowCount(),item);
}

void StuInfoManagementSystem::sltDeleteAction() //删除指定行操作
{
    int curreantRow = table->currentIndex().row(); //获取当前行数
    tableModel->removeRow(curreantRow);
}

void StuInfoManagementSystem::sltAddSchoolAction()
{
    bool ok;
    QString text = QInputDialog::getText(this,
                                         "Please Input School Name",
                                         tr("School name:"),
                                         QLineEdit::Normal,
                                         tr(""),
                                         &ok);
    if(ok && !text.isEmpty())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0,text);
        int schoolCount = treeWidget->topLevelItemCount();
        treeWidget->insertTopLevelItem(schoolCount,item);
    }
}

void StuInfoManagementSystem::sltAddGradeAction()
{
    if(treeWidget->currentItem())
    {
        bool ok;
        QString text = QInputDialog::getText(this,
                                             "Please Input Grade Name",
                                             tr("Grade name:"),
                                             QLineEdit::Normal,
                                             tr(""),
                                             &ok);
        if(ok && !text.isEmpty())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem;
            item->setText(0,text);

            if(treeWidget->currentItem()->parent())//当前选中的是班级
            {
                for(int i = 0; i< treeWidget->currentItem()->parent()->childCount(); i++) //同一个学校的班级不能重复
                {
                    if(treeWidget->currentItem()->parent()->child(i)->text(0) == text)
                    {

                        QMessageBox::information(this, QString::fromLocal8Bit("警告"),
                                                 QString::fromLocal8Bit("%1 已经存在").arg(text));
                        return;
                    }
                }
                treeWidget->currentItem()->parent()->addChild(item);
            }
            else
            {
                for(int i = 0; i< treeWidget->currentItem()->childCount(); i++) //同一个学校的班级不能重复
                {
                    if(treeWidget->currentItem()->child(i)->text(0) == text)
                    {

                        QMessageBox::information(this, QString::fromLocal8Bit("警告"),
                                                 QString::fromLocal8Bit("%1 已经存在").arg(text));
                        return;
                    }
                }
                treeWidget->currentItem()->addChild(item);
            }
        }
    }
    treeWidget->expandAll();
}

void StuInfoManagementSystem::sltDelSchoolOrGradeAction()
{
    QTreeWidgetItem *item = treeWidget->currentItem();
    if(!item->parent())
    {
        treeWidget->takeTopLevelItem(treeWidget->indexOfTopLevelItem(treeWidget->currentItem()));
    }
    else
    {
        QTreeWidgetItem *parent = item->parent();
        if(parent)
        {
            parent->removeChild(item);
        }
    }
}

void StuInfoManagementSystem::sltAboutAction()
{
    QMessageBox::about(this, tr("About Aoftware"),tr("Make By Hero"));
}

void StuInfoManagementSystem::SlotItemClicked(QTreeWidgetItem *item, int column)
{
    //学校1，班级2 
    if(item->parent()) //当前item为子项
    {
        for(int row = 0; row <= tableModel->rowCount();row++)
        {
            if(item->text(column) == tableModel->data(tableModel->index(row,2)).toString())  //班级
            {
                if(item->parent()->text(column) ==tableModel->data(tableModel->index(row,1)).toString()) //学校
                    table->setRowHidden(row,false);
                else
                    table->setRowHidden(row,true);
            }
            else
            {
                table->setRowHidden(row,true);
            }
        }
    }
    else //当前点击的item为父项
    {
        if(item->text(column) == QString::fromLocal8Bit("青羊小学"))
        {
            for(int row = 0; row <= tableModel->rowCount();row++)
            {
                if(tableModel->data(tableModel->index(row,1)).toString() != QString::fromLocal8Bit("青羊小学"))
                    table->setRowHidden(row,true);
                else
                    table->setRowHidden(row,false);
            }
        }
        else if(item->text(column) == QString::fromLocal8Bit("金牛小学"))
        {
            for(int row = 0; row <= tableModel->rowCount();row++)
            {

                if(tableModel->data(tableModel->index(row,1)).toString() != QString::fromLocal8Bit("金牛小学"))
                    table->setRowHidden(row,true);
                else
                    table->setRowHidden(row,false);
            }
        }
    }
}
