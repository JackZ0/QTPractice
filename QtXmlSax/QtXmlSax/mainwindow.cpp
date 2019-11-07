#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfile.h>
#include <QXmlInputSource>
#include <QXmlSimpleReader>
#include <qmessagebox.h>

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
}
bool MainWindow::readFile(const QString &fileName)
{
    currentItem = 0;

    QFile file(fileName);
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;
    reader.setContentHandler(this);
    reader.setErrorHandler(this);
    return reader.parse(inputSource);//解析
}
bool MainWindow::startElement(const QString & /*namespaceURI*/,
                              const QString & /*localName*/,
                              const QString &qName,
                              const QXmlAttributes &attributes)
{
    if (qName == "entry")
    {
        currentItem = new QTreeWidgetItem(currentItem ?
                currentItem : treeWidget->invisibleRootItem());
        currentItem->setText(0, attributes.value("term"));
    }
    else if (qName == "page")
    {
        currentText.clear();

    }
    //this->errorString();错误提示
    return true;//最后，我们返回 true，告诉 SAX 继续处理文件。如果有任何错误，则可以返回 false 告诉 SAX 停止处理。
}
bool MainWindow::characters(const QString &str)
{
    currentText += str;
    return true;
}
bool MainWindow::endElement(const QString & /*namespaceURI*/,
                            const QString & /*localName*/,
                            const QString &qName/*标签名字*/)
{
    if (qName == "entry")
    {
        currentItem = currentItem->parent();//
    }
    else if (qName == "page")
    {
        if (currentItem)
        {
            QString allPages = currentItem->text(1);
            if (!allPages.isEmpty())
                allPages += ", ";
            allPages += currentText;
            currentItem->setText(1, allPages);
        }
    }
    return true;
}
bool MainWindow::fatalError(const QXmlParseException &exception)
{
    QMessageBox::critical(this,
                          tr("SAX Error"),
                          tr("Parse error at line %1, column %2:\n %3")
                          .arg(exception.lineNumber())
                          .arg(exception.columnNumber())
                          .arg(exception.message()));
    return false;
}
MainWindow::~MainWindow()
{
    delete ui;
}
