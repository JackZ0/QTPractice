#ifndef CONTROLDELEGATE_H
#define CONTROLDELEGATE_H
#include <QItemDelegate>
#include <QObject>

class SpinboxDelegate : public QItemDelegate  //ƒÍ¡‰
{
    Q_OBJECT

public:
    SpinboxDelegate(int column);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //void setEditorData(QWidget *editor, const QModelIndex &index) const ;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const ;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();

private:
    int mColumn;
};

class ComboboxDelegate : public QItemDelegate  //—ß–£
{
    Q_OBJECT

public:
    ComboboxDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private slots:
    void commitAndCloseEditor();
};

#endif // CONTROLDELEGATE_H
