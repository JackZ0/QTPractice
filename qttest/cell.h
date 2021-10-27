#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>
class Cell : public QTableWidgetItem
{
public:
    Cell();

    QTableWidgetItem *clone() const;
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    QString formular() const;
    void setFormula(const QString &formular);
    void setDirty();

private:
    QVariant value() const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str,int &pos)const;
    QVariant evalFactor(const QString &str, int &pos)const;

    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;

};

#endif // CELL_H
