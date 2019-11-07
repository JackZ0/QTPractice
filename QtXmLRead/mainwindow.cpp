#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <qmessagebox.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("XML Reader"));

    treeWidget = new QTreeWidget(this);
    QStringList headers;
    headers << "Items" << "Pages";
    treeWidget->setHeaderLabels(headers);
    setCentralWidget(treeWidget);
    qDebug()<<QApplication::applicationDirPath();
}
bool MainWindow::readFile(const QString &fileName)
{
    QFile file(QApplication::applicationDirPath() + "/demo.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }
    reader.setDevice(&file);
    while (!reader.atEnd())
    {

        if (reader.isStartElement())
        {
            qDebug()<<"2222222222222222";
            if (reader.name() == "bookindex")
            {
                 readBookindexElement();//递归下降算法，层层读取
            }
            else
            {
                reader.raiseError(tr("Not a valid book file"));
            }
        }
        else
        {
            qDebug()<<"111111111111111";
            reader.readNext(); //循坏调用首次移动3次，后面移动一次
        }
    }
    file.close();
    if (reader.hasError())
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Failed to parse file %1").arg(fileName));
        return false;
    }
    else if (file.error() != QFile::NoError)
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }
    return true;
}
void MainWindow::readBookindexElement()
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "bookindex");//不是则会报错
    reader.readNext(); // 读取下一个记号，它返回记号的类型
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                readEntryElement(treeWidget->invisibleRootItem());
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}
void MainWindow::readEntryElement(QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, reader.attributes().value("term").toString());//元素的属性

    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                readEntryElement(item);
            }
            else if (reader.name() == "page")
            {
                readPageElement(item);
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}
void MainWindow::readPageElement(QTreeWidgetItem *parent)
{
    QString page = reader.readElementText();
    if (reader.isEndElement())
    {
        qDebug()<<"3333333333333333";
        reader.readNext();
    }

    QString allPages = parent->text(1);
    if (!allPages.isEmpty())
    {
        allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}
void MainWindow::skipUnknownElement()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            skipUnknownElement();
        }
        else
        {
            reader.readNext();
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
