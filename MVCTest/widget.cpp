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

    menuBarInit();//�˵���ʼ��
    tableWidgetInit(); //table��ʼ��
    treeWidgetInit(); //tree��ʼ��

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

void StuInfoManagementSystem::contextMenuEvent(QContextMenuEvent *e) //��д�������¼�
{
    //����һ
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

    //������
    //    {
    //        table->addAction(InsertAction);
    //        table->addAction(DeleteAction);
    //        table->setContextMenuPolicy(Qt::ActionsContextMenu);
    //    }
}

void StuInfoManagementSystem::menuBarInit()
{
    menuBar = new QMenuBar(0);
    OperationMenu = new QMenu(QString::fromLocal8Bit("ѧ��"));
    DeleteAction = new QAction(QString::fromLocal8Bit("ɾ��"));
    InsertAction = new QAction(QString::fromLocal8Bit("����"));
    OperationMenu->addAction(DeleteAction);
    OperationMenu->addAction(InsertAction);

    helpMenu = new QMenu(QString::fromLocal8Bit("����"));
    aboutAction = new QAction(QString::fromLocal8Bit("�������"));
    aboutQtAction = new QAction(QString::fromLocal8Bit("����Qt"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

    schoolAndGradeMenu = new QMenu(QString::fromLocal8Bit("ѧУ/�༶"));
    addSchoolAction = new QAction(QString::fromLocal8Bit("��� ѧУ"));
    addGradeAction = new QAction(QString::fromLocal8Bit("��� �༶"));
    delSchoolOrGradeAction = new QAction(QString::fromLocal8Bit("ɾ��"));
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
    //tableview��ʼ��
    {
        table  = new QTableView;
        tableModel = new QStandardItemModel;
        table->setModel(tableModel);

        tableModel->setHorizontalHeaderItem(0,new QStandardItem(QString::fromLocal8Bit("����")));
        tableModel->setHorizontalHeaderItem(1,new QStandardItem(QString::fromLocal8Bit("ѧУ")));
        tableModel->setHorizontalHeaderItem(2,new QStandardItem(QString::fromLocal8Bit("�༶")));
        tableModel->setHorizontalHeaderItem(3,new QStandardItem(QString::fromLocal8Bit("����")));
        tableModel->setHorizontalHeaderItem(4,new QStandardItem(QString::fromLocal8Bit("�Ա�")));
        tableModel->setHorizontalHeaderItem(5,new QStandardItem(QString::fromLocal8Bit("���")));
        tableModel->setHorizontalHeaderItem(6,new QStandardItem(QString::fromLocal8Bit("������ò")));
        tableModel->setHorizontalHeaderItem(7,new QStandardItem(QString::fromLocal8Bit("��������")));

        // ������ѧУ����ţСѧ������Сѧ�����༶��1�࣬2�࣬3�ࣩ�����䣬�Ա���ߣ�������ò������������������300�ַ���

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
    treeWidget->setHeaderLabel(QString::fromLocal8Bit("ѧУ/�༶"));

    QTreeWidgetItem *qingYang = new  QTreeWidgetItem;
    qingYang->setText(0,QString::fromLocal8Bit("����Сѧ"));

    QTreeWidgetItem  *jinNiu = new QTreeWidgetItem;
    jinNiu->setText(0,QString::fromLocal8Bit("��ţСѧ"));

    QStringList classlist;
    classlist << QString::fromLocal8Bit("1��") << QString::fromLocal8Bit("2��")
              << QString::fromLocal8Bit("3��");
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

void StuInfoManagementSystem::sltInsertAction() //�����в���
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
    item.at(0)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); //����ָ����Ķ��뷽ʽ
    item.at(7)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tableModel->insertRow(tableModel->rowCount(),item);
}

void StuInfoManagementSystem::sltDeleteAction() //ɾ��ָ���в���
{
    int curreantRow = table->currentIndex().row(); //��ȡ��ǰ����
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

            if(treeWidget->currentItem()->parent())//��ǰѡ�е��ǰ༶
            {
                for(int i = 0; i< treeWidget->currentItem()->parent()->childCount(); i++) //ͬһ��ѧУ�İ༶�����ظ�
                {
                    if(treeWidget->currentItem()->parent()->child(i)->text(0) == text)
                    {

                        QMessageBox::information(this, QString::fromLocal8Bit("����"),
                                                 QString::fromLocal8Bit("%1 �Ѿ�����").arg(text));
                        return;
                    }
                }
                treeWidget->currentItem()->parent()->addChild(item);
            }
            else
            {
                for(int i = 0; i< treeWidget->currentItem()->childCount(); i++) //ͬһ��ѧУ�İ༶�����ظ�
                {
                    if(treeWidget->currentItem()->child(i)->text(0) == text)
                    {

                        QMessageBox::information(this, QString::fromLocal8Bit("����"),
                                                 QString::fromLocal8Bit("%1 �Ѿ�����").arg(text));
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
    //ѧУ1���༶2 
    if(item->parent()) //��ǰitemΪ����
    {
        for(int row = 0; row <= tableModel->rowCount();row++)
        {
            if(item->text(column) == tableModel->data(tableModel->index(row,2)).toString())  //�༶
            {
                if(item->parent()->text(column) ==tableModel->data(tableModel->index(row,1)).toString()) //ѧУ
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
    else //��ǰ�����itemΪ����
    {
        if(item->text(column) == QString::fromLocal8Bit("����Сѧ"))
        {
            for(int row = 0; row <= tableModel->rowCount();row++)
            {
                if(tableModel->data(tableModel->index(row,1)).toString() != QString::fromLocal8Bit("����Сѧ"))
                    table->setRowHidden(row,true);
                else
                    table->setRowHidden(row,false);
            }
        }
        else if(item->text(column) == QString::fromLocal8Bit("��ţСѧ"))
        {
            for(int row = 0; row <= tableModel->rowCount();row++)
            {

                if(tableModel->data(tableModel->index(row,1)).toString() != QString::fromLocal8Bit("��ţСѧ"))
                    table->setRowHidden(row,true);
                else
                    table->setRowHidden(row,false);
            }
        }
    }
}
