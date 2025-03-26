#include"class_of_board.h"
#include"class_of_player.h"
int main()
{

    player pl1("Muhammed", 1);
    board board1;
    
    string str = pl1.enter_move();
    coor loction = board1.square_to_coordinates(str);
    board1.empty(loction);
    
    board1.print_board_for_white();
}