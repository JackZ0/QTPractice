#include "FieldData.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <QDebug>
using namespace std;

FieldData *FieldData::_ins = nullptr;
FieldData::FieldData():
    _width(10),
    _height(10),
    _mines(8)
{
    reset();
    srand(time(nullptr));
}

FieldData *FieldData::getInstance()
{
    if(_ins == nullptr){
        _ins = new FieldData();
    }
    return _ins;
}

void FieldData::initCells()
{
    for(int x =0; x < _width; x++){
        _cells.push_back(CellColumn(_height));
    }
}

void FieldData::reset()
{
    _cells.clear();
    initCells();
    deployMines();
}

void FieldData::deployMines()
{
    for(int x =0; x < _width; x++){
        for(int y =0; y < _height; y++){
            _cells[x][y] = 0;
        }
    }
    int cpmines = _mines;
    while(cpmines){
        int x = rand()%_width;
        int y = rand()%_height;

        if(_cells[x][y]!=-1){
            cpmines--;
            _cells[x][y] = -1;
            //上左 上中 上右 中左 中右 下左 下中 下右
            updateSurroundding(x-1,y-1);
            updateSurroundding(x,y-1);
            updateSurroundding(x+1,y-1);
            updateSurroundding(x-1,y);
            updateSurroundding(x+1,y);
            updateSurroundding(x-1,y+1);
            updateSurroundding(x,y+1);
            updateSurroundding(x+1,y+1);
        }
    }
    dump();
}

void FieldData::customise(int cw, int ch, int cm)
{
    _width = cw;
    _height = ch;
    _mines = cm;
}

void FieldData::updateSurroundding()
{

}

void FieldData::updateSurroundding(int x, int y)
{
    if(x>=0 && x < _width && y>=0 && y < _height)
    {
        if(_cells[x][y] != -1){
            _cells[x][y]++;
        }
    }

}

void FieldData::dump()
{
    for(int y =0; y < _height; y++){
        for(int x =0; x < _width; x++){
            cout << _cells[x][y] <<'\t';
        }
        cout << endl;
    }
    qDebug() << "------------------------\n";

}
