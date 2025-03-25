#include "class_of_piece.h"

class knight : public piece
{
    
    
public:

    knight(pices id, coor &square_occiped) : 
    piece(id, square_occiped){}
    set<coor> range_of_motion() override
    {
        set<coor> motions;
        
        coor left_north = {square_occiped.x + 2, square_occiped.y + 1};
        if(true_coor(left_north) && enimy_loction(left_north)) motions.insert(left_north);

        coor left_south = {square_occiped.x + 2, square_occiped.y - 1};
        if(true_coor(left_south) && enimy_loction(left_south)) motions.insert(left_south);
        
        coor right_north = {square_occiped.x - 2, square_occiped.y + 1};
        if(true_coor(right_north) && enimy_loction(right_north)) motions.insert(right_north);
        coor right_south = {square_occiped.x - 2, square_occiped.y - 1};
        if(true_coor(right_south) && enimy_loction(right_south)) motions.insert(right_south);

        coor north_left = {square_occiped.x + 1, square_occiped.y + 2};
        if(true_coor(north_left) && enimy_loction(north_left)) motions.insert(north_left);
        
        coor south_left = {square_occiped.x + 1, square_occiped.y - 2};
        if(true_coor(south_left) && enimy_loction(south_left)) motions.insert(south_left);
        
        coor north_right = {square_occiped.x - 1, square_occiped.y + 2};
        if(true_coor(north_right) && enimy_loction(north_right)) motions.insert(north_right);
        
        coor south_right = {square_occiped.x - 1, square_occiped.y - 2};
        if(true_coor(south_right) && enimy_loction(south_right)) motions.insert(south_right);
        return motions;
    }
    



};