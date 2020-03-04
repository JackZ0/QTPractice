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
    ~CellItem();
    static QPixmap * _initial;
    static QPixmap * _flag;
    static QPixmap * _question;
    static QPixmap * _blank;
    static QPixmap * _explode;
    static QPixmap * _digits[9];

    static int _refCount;
protected:
    int _cx;
    int _cy;
    enum CellStatus _status;


};

#endif // CELLITEM_H
