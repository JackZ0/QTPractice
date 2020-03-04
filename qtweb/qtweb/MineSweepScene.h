#ifndef MINESWEEPSCENE_H
#define MINESWEEPSCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <vector>

#include "CellItem.h"

using namespace std;



typedef vector<CellItem *> ItemColumn;
typedef vector<ItemColumn> ItemMatrix;
class MineSweepScene:public QGraphicsScene
{
public:
    MineSweepScene(QObject *parent = Q_NULLPTR);
    ~MineSweepScene();
    void initItems();
    void clearItems();


protected:
    ItemMatrix _items;
};

#endif // MINSESWEEPSCENE_H
