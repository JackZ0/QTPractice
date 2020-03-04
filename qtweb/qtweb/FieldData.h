#ifndef FIELDDATA_H
#define FIELDDATA_H
#include <vector>
using namespace std;
#define Field (FieldData::getInstance())

typedef vector<int> CellColumn;
typedef  vector<CellColumn> CellMatrix;

class FieldData
{
public:
    FieldData();
    ~FieldData();

    static FieldData *getInstance();
    inline int getWidth(){return _width;}
    inline int getHeight(){return _height;}
    inline int getMines(){return _mines;}

    const CellMatrix &getCells(){return _cells;}
    void initCells(); // 申请空间
    void reset();
    void deployMines(); //布雷
    void customise(int cw,int ch, int cm);
protected:
    int _width;
    int _height;
    int _mines;
    CellMatrix _cells;
    void updateSurroundding();
    void updateSurroundding(int x, int y);
    void dump();
private:
    static FieldData *_ins;


};

#endif // FIELDDATA_H
