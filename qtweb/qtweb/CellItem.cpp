#include "CellItem.h"


int CellItem::_refCount = 0;

CellItem::CellItem(int x, int y, CellStatus status, QGraphicsItem *parent)
{
    _status = status;
    _cx = x;
    _cy = y;

    if(_refCount == 0){
        _refCount++;
        _initial = new QPixmap();
    }

}
