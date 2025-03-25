#include"class_of_board.h"
int main()
{
    string move = "b1";
    board b1;
    coor loction = {7, 4};
    b1.empty(loction);

    b1.print_board_for_black();
    
}