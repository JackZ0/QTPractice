#include "cell.h"

Cell::Cell()
{
    setDirty();
}

QTableWidgetItem *Cell::clone() const
{
    return new Cell(*this);
}

QVariant Cell::data(int role) const
{
    if(role == Qt::DisplayRole){
        if(value().isValid()){
            return value().toString();
        }
        else{
            return "####";
        }
    }else if(role == Qt::TextAlignmentRole){
        if(value().type() == QVariant::String){
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        }else{
            return int(Qt::AlignRight | Qt::AlignVCenter);
        }
    }else{
        return QTableWidgetItem::data(role);
    }
}

QString Cell::formular() const
{
    return data(Qt::EditRole).toString();
}

void Cell::setFormula(const QString &formular)
{
    setData(Qt::EditRole,formular);
}

void Cell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role,value);
    if(role == Qt::EditRole)
        setDirty();
}

void Cell::setDirty()
{
    cacheIsDirty = true;
}
const QVariant Invalid;
QVariant Cell::value() const
{
    if(cacheIsDirty){
        cacheIsDirty = false;
        QString formularStr = formular();
        if(formularStr.startsWith('\'')){
            cachedValue = formularStr.mid(1);
        }
        else if(formularStr.startsWith('='))
        {
            cachedValue = Invalid;
            QString expr = formularStr.mid(1);
            expr.replace(" ","");
            expr.append(QChar::Null);

            int pos = 0;
            cachedValue = evalExpression(expr,pos);
            if(expr[pos]!= QChar::Null)
                cachedValue = Invalid;
        }else
        {
            bool ok;
            double b = formularStr.toDouble(&ok);
            if(ok)
            {
                cachedValue = b;
            }else
            {
                cachedValue = formularStr;
            }
        }

    }
}

QVariant Cell::evalExpression(const QString &str, int &pos) const
{

}

QVariant Cell::evalTerm(const QString &str, int &pos) const
{

}

QVariant Cell::evalFactor(const QString &str, int &pos) const
{

}
