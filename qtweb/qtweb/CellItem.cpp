#include "CellItem.h"


int CellItem::_refCount = 0;


QPixmap * CellItem::_initial = nullptr;
QPixmap * CellItem::_flag = nullptr;
QPixmap * CellItem::_blank = nullptr;
QPixmap * CellItem::_explode = nullptr;
QPixmap * CellItem::_question = nullptr;
QPixmap * CellItem::_digits[9] = {nullptr};

CellItem::CellItem(int x, int y, CellStatus status, QGraphicsItem *parent)
{
    _status = status;
    _cx = x;
    _cy = y;
    _refCount++; // 在加载第一个CellItem 的时候创建所有图片

    if(_refCount == 1){
        _initial = new QPixmap(":/image/initial.png");
        _flag = new QPixmap(":/image/flag.png");
        _question = new QPixmap(":/image/question.png");
        _blank = new QPixmap(":/image/blank.png");
        _explode = new QPixmap(":/image/explode.png");

        QString prefix = ":/image/";
        QString num;
        QString postfix = ".png";

        QString filename;
        for (int i = 1; i < 9; i++){
            filename += prefix;
            filename += num.setNum(i);
            filename += postfix;
            _digits[i] = new QPixmap(filename);
        }

    }
    setPixmap(*_initial);

}
/**
 * @brief CellItem::~CellItem
 * 销毁所有图片
 */
CellItem::~CellItem()
{
    _refCount--;
    if(_refCount == 0){
        delete _initial;
        delete _flag;
        delete _question;
        delete _blank;
        delete _explode;

        for( int i = 1; i < 9; i++){
            delete _digits[i];
        }
    }
}
