#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("XML DOM Reader"));

    treeWidget = new QTreeWidget(this);
    QStringList headers;
    headers << "Items" << "Pages";
    treeWidget->setHeaderLabels(headers);
    setCentralWidget(treeWidget);
}
bool MainWindow::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    //填充dom树
    if (!doc.setContent(&file, false, &errorStr, &errorLine,
                        &errorColumn))//形参2，是否创建命名空间
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Parse error at line %1, column %2: %3")
                                .arg(errorLine).arg(errorColumn).arg(errorStr));
        return false;
    }

    QDomElement root = doc.documentElement();//获取dom树的根标签
    if (root.tagName() != "bookindex")
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Not a bookindex file"));
        return false;
    }
    parseBookindexElement(root);
      return true;
 }
void MainWindow::parseBookindexElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();//根标签下的子标签
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "entry")//qdomnode ————》qdomelement的转换基类到子类的转换
        {
            parseEntryElement(child.toElement(),
                              treeWidget->invisibleRootItem());
        }
        child = child.nextSibling();
    }
 }

void MainWindow::parseEntryElement(const QDomElement &element,
                                   QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, element.attribute("term"));

    QDomNode child = element.firstChild();
    while (!child.isNull())//遍历标签的子标签
    {
        if (child.toElement().tagName() == "entry")
        {
            parseEntryElement(child.toElement(), item);//递归调用本身
        }
        else if (child.toElement().tagName() == "page")
        {
            parsePageElement(child.toElement(), item);
        }
        child = child.nextSibling();//指针移动一个标签
    }
}
void MainWindow::parsePageElement(const QDomElement &element,
                                  QTreeWidgetItem *parent)
{
    QString page = element.text();
    QString allPages = parent->text(1);//最开始的一次为空
    qDebug()<<"allPages "<<allPages;
    if (!allPages.isEmpty())
    {
         allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}
MainWindow::~MainWindow()
{
    delete ui;
}
