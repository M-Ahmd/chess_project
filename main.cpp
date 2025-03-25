#include"class_of_board.h"
int main()
{
    string move = "b1";
    board b1;
    coor test = b1.square_to_coordinates(move);
    cout << "the x is " << test.x << "the y is " << test.y << endl;

    b1.print_board_for_white();
    coor loc = {0, 0};
    cout << b1.get_id(loc);
}