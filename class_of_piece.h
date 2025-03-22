#include<set>
#include"class_of_board.h"
using namespace std;
class piece
{
private:
    int id;
    coor location;
    bool color;
    coor square_occiped;
public:
    virtual bool bin(coor input) = 0;
    virtual bool move(coor input) = 0;
    virtual set<coor> range_of_motion() = 0;
    virtual void die() = 0;
};
