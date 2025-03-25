#include<set>
#include"class_of_board.h"
using namespace std;
class piece
{
protected:
    pices id;
    bool color;
    coor square_occiped;
    board board_one;
    /**
     * true_coor - is a function to check the coordintes
     * still in the board or not
     * @current: the loction of the piceces
     * return: true loction ? true : false
     */
    bool true_coor(coor &current)
    {
        return current.x >= 0 && current.x <= 7
        && current.y >= 0 && current.y <= 7;
    }
    /**
     * enimy_loction - is a function to check is this loction is occupied 
     * by my friend my friend or my enimy (ohh U r U r my enimy is a song)
     * @loction: is a loction for the square that i amma check it
     * return: enimy_loction ? false : true
     */
    bool enimy_loction(coor &loction)
    {
        (board_one.get_id(loction) % 2 == board_one.get_id(loction) % 2)
        ? false : true;
    }
public:
    //contractor
    piece(pices id, coor &square_occiped)
    {
        this->id = id;
        this->color = !(id % 2);
        this->square_occiped = square_occiped;
    }
    virtual bool bin(coor &input) = 0;
    virtual bool move(coor &input) = 0;
    virtual bool capture(coor &input) = 0;
    //done
    virtual set<coor> range_of_motion() = 0;
    virtual void die() = 0;
};
