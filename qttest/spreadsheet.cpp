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

}

QString Spreadsheet::currentFormula() const
{

}

QTableWidgetSelectionRange Spreadsheet::selectRange() const
{

}

void Spreadsheet::clear()
{

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

}
