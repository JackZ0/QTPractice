#include <QSpinBox>
#include <QComboBox>
#include <QDebug>
#include <QApplication>
#include <QStyleOptionViewItem>
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "controldelegate.h"
SpinboxDelegate::SpinboxDelegate(int column)
{
    mColumn = column;
}

//Ϊָ�����л����д�������
QWidget *SpinboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    if(index.column() ==3) //����
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(1,110);
        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else if( index.column() == 5) //���
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(120,220);
        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else
    {
        return QItemDelegate::createEditor(parent,option,index);
    }
}

//��ʾ��ʽ����
void SpinboxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column()== 5)
    {
        int age = index.model()->data(index,Qt::DisplayRole).toInt();
        QString text = QString("%1 CM").arg(age,3,10,QChar(' '));

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        if (myOption.state & QStyle::State_HasFocus)
        {
            myOption.state = myOption.state ^ QStyle::State_HasFocus;
        }

        drawDisplay(painter,myOption,myOption.rect,text);
        drawFocus(painter,myOption,myOption.rect);
    }
    else if(index.column() == 3)
    {
        int height = index.model()->data(index,Qt::DisplayRole).toInt();
        QString text = QString("%1 Year").arg(height,3,10,QChar(' '));

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        if (myOption.state & QStyle::State_HasFocus)
        {
            myOption.state = myOption.state ^ QStyle::State_HasFocus;
        }

        drawDisplay(painter,myOption,myOption.rect,text);
        drawFocus(painter,myOption,myOption.rect);
    }
}

void SpinboxDelegate::commitAndCloseEditor()
{
    QSpinBox *editor = qobject_cast<QSpinBox*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}

//void SpinboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{

//}

void SpinboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

ComboboxDelegate::ComboboxDelegate()
{

}

QWidget *ComboboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    if(index.column() == 1)
    {
        editor->addItem(QString::fromLocal8Bit("����Сѧ"));
        editor->addItem(QString::fromLocal8Bit("��ţСѧ"));
        editor->setCurrentIndex(0);

        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else if(index.column() == 2)
    {
        editor->addItem(QString::fromLocal8Bit("1��"));
        editor->addItem(QString::fromLocal8Bit("2��"));
        editor->addItem(QString::fromLocal8Bit("3��"));
        editor->setCurrentIndex(0);

        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else if(index.column() == 4)
    {
        editor->addItem(QString::fromLocal8Bit("��"));
        editor->addItem(QString::fromLocal8Bit("Ů"));
        editor->setCurrentIndex(0);

        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else if(index.column() == 6)
    {
        editor->addItem(QString::fromLocal8Bit("Ⱥ��"));
        editor->addItem(QString::fromLocal8Bit("������Ա"));
        editor->addItem(QString::fromLocal8Bit("������Ա"));
        editor->setCurrentIndex(0);

        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else
    {
        QItemDelegate::createEditor(parent,option,index);
    }
}

void ComboboxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1 || index.column() == 2 ||index.column() == 4 ||index.column() == 6)
    {
        QString text = index.model()->data(index , Qt::DisplayRole).toString();

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;

        if (myOption.state & QStyle::State_HasFocus)
        {
            myOption.state = myOption.state ^ QStyle::State_HasFocus;
        }

        drawDisplay(painter,myOption,myOption.rect,text);
        drawFocus(painter,myOption,myOption.rect);
    }
    else
    {
        QItemDelegate::paint(painter,option,index);
    }
}

void ComboboxDelegate::commitAndCloseEditor()
{
    QComboBox *editor = qobject_cast<QComboBox*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}
