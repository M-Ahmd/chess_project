#include"class_of_board.h"
int main()
{
    board b1;
    b1.print_board();
    cout << endl;
    coor c = {3, 4};
    cout << b1.free(c);
}