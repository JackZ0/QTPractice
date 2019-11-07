#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QXmlDefaultHandler>
#include <qtreeview.h>
#include <QTreeWidgetItem>
#include <QXmlParseException>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow ,public QXmlDefaultHandler
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool readFile(const QString &fileName);

protected:
    bool startElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName,
                      const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI,
                    const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
private:
    QTreeWidget *treeWidget;
    QTreeWidgetItem *currentItem;
    QString currentText;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
