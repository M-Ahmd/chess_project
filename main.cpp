#include "class_of_piece.h"
int main()
{
    coor square = {0, 1};
    piece bs(black_pawn, square);

    set<coor> res = bs.get_motions();
    for (const auto& coord : res)
    {
        cout << "(" << coord.x << ", " << coord.y << ")" << endl;
    }
    
}