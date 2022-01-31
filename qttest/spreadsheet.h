#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class Cell;
class SpreadsheetCompare;

class Spreadsheet : public QTableWidget
{
public:
    Spreadsheet(QWidget *parent = 0);
    bool autoRecalculate() const {return autoRecalc;}
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectRange() const;
    void clear();
    bool readFile(const QString &filename);
    bool writeFile(const QString &filename);
    void sort(const SpreadsheetCompare &compare);

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
    void recalculate();
    void setAutoRecalculate(bool recalc);
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void somethingChanged();

signals:
    void modified();




private:
    enum{MagicNumber = 0x7F51C883,RowCount=999,ColumnCount=26};
    Cell *cell(int row, int column) const;
    QString text(int row, int column) const;
    QString formula(int row, int column) const;
    void setFormula(int row, int column, const QString &formular);
    bool autoRecalc;
};


class SpreadsheetCompare
{
public:
    bool operator()(const QStringList &row1,
                    const QStringList &row2)const;
    enum{KeyCount = 3};
    int key[KeyCount];
    bool ascending[KeyCount];
};



#endif // SPREADSHEET_H