#include <QtGui>
#include "spreadsheet.h"
#include "cell.h"
Spreadsheet::Spreadsheet(QWidget *parent)
    :QTableWidget(parent)
{
    autoRecalc = true;
    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);
    connect(this,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(somethingChanged()));

    clear();

}

QString Spreadsheet::currentLocation() const
{
    return QChar('A'+currentColumn())+QString::number(currentRow()+1);
}

QString Spreadsheet::currentFormula() const
{
    return formula(currentRow(),currentColumn());
}

QTableWidgetSelectionRange Spreadsheet::selectRange() const
{

}

void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for(int i = 0; i < ColumnCount; ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar ('A'+i)));
        setHorizontalHeaderItem(i,item);
    }
    setCurrentCell(0,0);
}

bool Spreadsheet::readFile(const QString &filename)
{

}

bool Spreadsheet::writeFile(const QString &filename)
{

}

void Spreadsheet::sort(const SpreadsheetCompare &compare)
{

}

void Spreadsheet::cut()
{

}

void Spreadsheet::copy()
{

}

void Spreadsheet::paste()
{

}

void Spreadsheet::del()
{

}

void Spreadsheet::selectCurrentRow()
{

}
void Spreadsheet::selectCurrentColumn()
{

}

void Spreadsheet::recalculate()
{

}

void Spreadsheet::setAutoRecalculate(bool recalc)
{

}

void Spreadsheet::findNext(const QString &str, Qt::CaseSensitivity cs)
{

}

void Spreadsheet::somethingChanged()
{
    if(autoRecalc)
        recalculate();
    emit modified();
}

Cell *Spreadsheet::cell(int row, int column) const
{
    return static_cast<Cell *>(item(row,column));
}

QString Spreadsheet::text(int row, int column) const
{
    Cell *c = cell(row,column);
    if(c)
    {
        return c->text();
    }else
    {
        return "";
    }
}

QString Spreadsheet::formula(int row, int column) const
{
    Cell *c = cell(row,column);
    if(c){
        return c->formular();
    }else{
        return "";
    }

}

void Spreadsheet::setFormula(int row, int column, const QString &formular)
{
    Cell *c = cell(row,column);
    if(!c){
        c = new Cell;
        setItem(row,column,c);
    }
    c->setFormula(formular);
}

