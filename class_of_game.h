#include "class_of_board.h"

class game
{
private:
    board board_one;

public:
    int get_id(coor &loction)
    {
        return board_one.get_id(loction);
    }
    bool free_square(coor &loction)
    {
        return board_one.free(loction);
    }



};