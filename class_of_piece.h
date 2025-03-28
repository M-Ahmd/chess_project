#include<set>
#include "class_of_game.h"
using namespace std;
class piece : private board
{
private:
    pices id;
    bool color;
    coor square_occiped;
    set<coor> motions;

    void set_color(pices &id)
    {
        color = !(id % 2);
    }
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
        return !(id % 2 == get_id(loction) % 2) || free(loction);
    }
    /**
     * knight_motions - is a function to set knight motions
     * return: void funcion
     */
    void knight_motions()
    {   
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
    }
    /**
     * bishob_motions - is a function set motions of the bishob
     * return: is a void function
     */
    void bishob_motions()
    {
        //for x + 1, y + 1
        for(coor tem = {square_occiped.x + 1, square_occiped.y + 1};
        true_coor(tem); tem = {tem.x + 1, tem.y + 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
        //for x - 1, y - 1
        for(coor tem = {square_occiped.x - 1, square_occiped.y - 1};
        true_coor(tem); tem = {tem.x - 1, tem.y - 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
        
        //for x + 1, y - 1
        for(coor tem = {square_occiped.x + 1, square_occiped.y - 1};
        true_coor(tem); tem = {tem.x + 1, tem.y - 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
            
        //for x - 1, y + 1
        for(coor tem = {square_occiped.x - 1, square_occiped.y + 1};
        true_coor(tem); tem = {tem.x - 1, tem.y + 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
    
    }
    /**
     * rook_motions - is a function to set the motions to the rook
     * return: a void functions
     */
    void rook_motions()
    {
        //for x + 1, y
        for(coor tem = {square_occiped.x + 1, square_occiped.y};
        true_coor(tem); tem = {tem.x + 1, tem.y})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
        //for x, y + 1
        for(coor tem = {square_occiped.x, square_occiped.y + 1};
        true_coor(tem); tem = {tem.x, tem.y + 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
        //for x - 1, y
        for(coor tem = {square_occiped.x - 1, square_occiped.y};
        true_coor(tem); tem = {tem.x - 1, tem.y})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
        //for x, y - 1
        for(coor tem = {square_occiped.x, square_occiped.y - 1};
        true_coor(tem); tem = {tem.x, tem.y - 1})
            if(free(tem))
                motions.insert(tem);
            else if(enimy_loction(tem))
            {
                motions.insert(tem);
                break;
            }
            else if(!enimy_loction(tem))
                break;
    }
    /**
     * queen_motions - is a function to set the motions to the queen
     * return: is a void function
     */
    void queen_motions()
    {
        rook_motions();
        bishob_motions();
    }
    /**
     * pawn_motions - is a function to set the motions to the
     * black pawn
     * return: is a void function
     */
    void black_pawn_motions()
    {
        // Moves
        if (square_occiped.y == 6) // Initial
        {
            coor loction = {square_occiped.x, square_occiped.y - 2}; // x first
            if (free(loction))
                motions.insert(loction);
        }
        coor forward = {square_occiped.x, square_occiped.y - 1}; // x first
        if (free(forward))
            motions.insert(forward);

        // Capture
        coor cap1 = {square_occiped.x + 1, square_occiped.y - 1}; // x first
        if (enimy_loction(cap1) && !free(cap1))
            motions.insert(cap1);
        coor cap2 = {square_occiped.x - 1, square_occiped.y - 1}; // x first
        if (enimy_loction(cap2) && !free(cap2))
            motions.insert(cap2);
    }
    /**
     * pawn_motions - is a function to set the motions to the
     * white pawn
     * return: is a void function
     */
    void white_pawn_motions()
    {
        // Moves
        if (square_occiped.y == 1) // Initial
        {
            coor loction = {square_occiped.x, square_occiped.y + 2}; // x first
            if (free(loction))
                motions.insert(loction);
        }
        coor forward = {square_occiped.x, square_occiped.y + 1}; // x first
        if (free(forward))
            motions.insert(forward);

        // Capture
        coor cap1 = {square_occiped.x - 1, square_occiped.y + 1}; // x first
        if (enimy_loction(cap1) && free(cap1))
            motions.insert(cap1);
        coor cap2 = {square_occiped.x + 1, square_occiped.y + 1}; // x first
        if (enimy_loction(cap2) && free(cap2))
            motions.insert(cap2);
}
    /**
     * king_move - is a function that set the motions of the 
     * king
     * return: is a void function
     */
    void king_motions()
    {
        coor left = {square_occiped.x - 1, square_occiped.y};
        if(true_coor(left) && enimy_loction(left)) motions.insert(left);

        coor right = {square_occiped.x + 1, square_occiped.y};
        if(true_coor(right) && enimy_loction(right)) motions.insert(right);
        
        coor up = {square_occiped.x , square_occiped.y + 1};
        if(true_coor(up) && enimy_loction(up)) motions.insert(up);

        coor down = {square_occiped.x , square_occiped.y - 1};
        if(true_coor(down) && enimy_loction(down)) motions.insert(down);

        coor right_up = {square_occiped.x + 1, square_occiped.y + 1};
        if(true_coor(right_up) && enimy_loction(right_up)) motions.insert(right_up);

        coor left_down = {square_occiped.x - 1, square_occiped.y - 1};
        if(true_coor(left_down) && enimy_loction(left_down)) motions.insert(left_down);
        
        coor left_up = {square_occiped.x - 1, square_occiped.y + 1};
        if(true_coor(left_up) && enimy_loction(left_up)) motions.insert(left_up);

        coor right_down = {square_occiped.x + 1, square_occiped.y - 1};
        if(true_coor(right_down) && enimy_loction(right_down)) motions.insert(right_down);
    }
public:
    /**
     * set_motions - is a function to set motions to every pieces
     * return: void function
     */
    void set_motions()
    {
        switch (id)
        {
            case black_knight:
            case white_knight:
                knight_motions();
                break;
            case white_bishob:
            case black_bishob:
                bishob_motions();
                break;
            case white_rook:
            case black_rook:
                rook_motions();
                break;
            case white_queen:
            case black_queen:
                queen_motions();
                break;
            case black_king:
            case white_king:
                king_motions();
                break;
            case white_pawn:
                white_pawn_motions();
                break;
            case black_pawn:
                black_pawn_motions();
                break;
        default:
            break;
        }
    }

    //contractor
    piece(coor &square_occiped)
    {
        this->id = (pices)get_id(square_occiped);
        this->square_occiped = square_occiped;
        set_color(id);
        set_motions();
    }
    /**
     * get_motions - is a function the make
     * every pice know there moves
     * return: the set of all motions of pieces
     */
    set<coor> get_motions()
    {
        return motions;
    }  
    /**
     * move - is a function to make pieces move
     * @loction: is the coordinates
     * return: true_coor ? true : flase
     */
    bool move(coor &loction)
    {
        
        if(motions.find(loction) == motions.end()) return false;
        empty(square_occiped);//make my square empty
        set_id_to_square(loction, id);
        return true;
    }
};
