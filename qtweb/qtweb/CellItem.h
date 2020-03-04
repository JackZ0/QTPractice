#ifndef CELLITEM_H
#define CELLITEM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

//小格子行为

enum CellStatus{
    INITIAL,FLAG,QUESTION,EXPLODE,DIGIT,BLANK
};


class CellItem : public QGraphicsPixmapItem
{
public:
    CellItem(int x, int y,enum CellStatus status = INITIAL,
             QGraphicsItem *parent = Q_NULLPTR );
    QPixmap * _initial;
    QPixmap * _flag;
    QPixmap * _question;
    QPixmap * _blank;
    static int _refCount;
protected:
    int _cx;
    int _cy;
    enum CellStatus _status;


};

#endif // CELLITEM_H
