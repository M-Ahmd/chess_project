#include "class_of_board.h"
enum state {curr = 0, win = 1, lose = 2, draw = 3};
class player
{
    string name;
    state splayer = curr;
    bool color;
    //absolute value
    int abs(int number)
    {
        return (number < 0) ? -number : number;
    }
    //valid pawn move
    bool valid_pawn(string &move)
    {
        return abs(int(move[0]) - int(move[2])) == 1;
    }
    //check the input size
    bool wrong_size(string &move)
    {
        return  !move.size() || (move.size() != 2 && 
        move.size() != 3 && move.size() != 4 && move.size() != 5);
    }
    //check the file name is true or not
    bool file_character(char &ch)
    {
        return (ch >= 'a' && ch <= 'h');
    }
    //check the piece name is true or not
    bool piece_character(char &ch)
    {
        return ch == 'R' || ch == 'N' || ch == 'B'
        || ch == 'Q' || ch == 'K';
    }
    //check the rows digit are true or not
    bool chess_digit(char &ch)
    {
        return ch >= '1' && ch <= '8';
    }
    //check if the x are true or not
    bool capture_character(char &ch)
    {
        return ch == 'x';
    }
    //if the pawn take something (capture)
    bool pawn_take(string &move)
    {
        return  valid_pawn(move) && capture_character(move[1])
        && file_character(move[2]) && chess_digit(move[3]);
    }
    //check the syntax for size of 2
    bool check_4_size_2(string &move)
    {
        return file_character(move[0]) && chess_digit(move[1]);
    }
    //check the syntax for size of 3
    bool check_4_size_3(string &move)
    {
        return piece_character(move[0]) && file_character(move[1]) && chess_digit(move[2]);
    }
    //check the syntax for size of 4
    bool check_4_size_4(string &move)
    {
        return (piece_character(move[0]) && capture_character(move[1])
        && file_character(move[2]) && chess_digit(move[3]))
        || pawn_take(move);
    }
    //check the syntax for size of 5
    bool check_4_size_5(string &move)
    {
        return piece_character(move[0]) && file_character(move[1])
        && capture_character(move[2]) && file_character(move[3]) &&
        chess_digit(move[4]);
    }
    /**
     * valid_syntax - is a function check the validy of input user
     * @move: is a string that the user entered
     * return: true if the syntax was true else flase
     */
    bool valid_syntax(string &move)
    {
        //check if there is move or not and check the frist character true?
        if(wrong_size(move))
            return false;
        if(move.size() == 2)
            return check_4_size_2(move);
        else if(move.size() == 3)
            return check_4_size_3(move);
        else if(move.size() == 4)
            return check_4_size_4(move);
        else if(move.size() == 5)
            return check_4_size_5(move);
        else
        {
            return false;
        }
    }
public:
    /**
     * constractor - that is build object
     * @name: this is the name of player
     * @color: is the piece color of player
     * return: void function
     */
    player(string name, bool color)
    {
        this->name = name;
        this->color = color;
    }
    void enter_move()
    {
        string move = "";
        do
        {
            cout << "Enter a true move plz\n";
            cin >> move;
        }while(!valid_syntax(move));
    }

};