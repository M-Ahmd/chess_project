#include "class_of_piece.h"
int main()
{
    coor square = {1, 0};
    piece kn(square);
    coor loc = {2, 2};

    kn.move(loc);
    kn.print_board_for_white();
    
}