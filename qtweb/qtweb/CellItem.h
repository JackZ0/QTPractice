#ifndef CELLITEM_H
#define CELLITEM_H


//小格子行为

enum CellStatus{
    INITIAL,FLAG,QUESTION,EXPLODE,DIGIT,BLANK
};


class CellItem : public QGraphicsPixmapItem
{
public:
    CellItem(int x, int y,enum CellStatus status = INITIAL);
};

#endif // CELLITEM_H
