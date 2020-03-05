#include "MineSweepScene.h"
#include "FieldData.h"
#include <QDebug>
MineSweepScene::MineSweepScene(QObject *parent):
    QGraphicsScene(parent)

{
    initItems();
}

MineSweepScene::~MineSweepScene()
{
    clearItems();
}

void MineSweepScene::initItems()
{
    int w = Field->getWidth();
    int h = Field->getHeight();
    qDebug()<<"||" <<w << h <<endl;

    for(int x = 0; x < w; x++){
        _items.push_back(ItemColumn());
        for(int y=0; y < h; y++){
            _items[x].push_back(new CellItem(x,y));
            static int cw = _items[0][0]->boundingRect().width();
            static int ch = _items[0][0]->boundingRect().height();

            _items[x][y]->setPos(x*cw,y*ch);
            addItem(_items[x][y]);
        }
    }
}

void MineSweepScene::clearItems()
{

}
