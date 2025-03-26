#pragma once
#include<iostream>
using namespace std;
typedef struct cooridnates
{
    int x, y;
} coor;
enum pices {white_pawn = 2, black_pawn = 1, white_knight = 4
, black_knight = 3, white_bishob = 6, black_bishob = 5, white_rook = 8,
black_rook = 7, white_queen = 10, black_queen = 9, white_king = 12, black_king = 11};
class board
{
private:
    //this is the grid of the game , {} init. all values to be zeros.
    int arr[8][8]{};
    /**
     * convert - is a function for convert pieces into characters to
     * print it in the console
     * @num: is the number of the piece
     * return: return character of piece number
     */
    char convert(int num)
    {
        switch (num)
        {
            case white_pawn:
                return 'P';
            case black_pawn:
                return 'p';
            case white_knight:
                return 'N';
            case black_knight:
                return 'n';
            case white_bishob:
                return 'B';
            case black_bishob:
                return 'b';
            case white_queen:
                return 'Q';
            case black_queen:
                return 'q';
            case white_king:
                return 'K';
            case black_king:
                return 'k';
            case white_rook:
                return 'R';
            case black_rook:
                return 'r';
            default:
                return '.';
        }
    }
public:
    /**
     * board - is a constractor to init. the board of chess
     * 
     * return: this is a void function
     */
    board()
    {

        arr[0][0] = white_rook;
        arr[0][1] = white_knight;
        arr[0][2] = white_bishob;
        arr[0][3] = white_queen;
        arr[0][4] = white_king;
        arr[0][5] = white_bishob;
        arr[0][6] = white_knight;
        arr[0][7] = white_rook;
        for(int i = 0; i < 8; i++)
            arr[1][i] = white_pawn;
        for(int i = 0; i < 8; i++)
            arr[6][i] = black_pawn;
        arr[7][0] = black_rook;
        arr[7][1] = black_knight;
        arr[7][2] = black_bishob;
        arr[7][3] = black_queen;
        arr[7][4] = black_king;
        arr[7][5] = black_bishob;
        arr[7][6] = black_knight;
        arr[7][7] = black_rook;
    }
    /**
     * print_board_for_black - a function to print the chess board 
     * frame of refrence black
     * return: a void function
     */
    void print_board_for_black()
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 7; j >= 0; j--)
                cout << convert(arr[i][j]) << " ";
            cout << "\n";
        }
        cout << endl;
    }
    /**
     * print_board_for_white - a function to print the chess board 
     * frame of refrence white
     * return: a void function
     */
    void print_board_for_white()
    {
        for(int i = 7; i >= 0; i--)
        {
            for(int j = 0; j < 8; j++)
                cout << convert(arr[i][j]) << " ";
            cout << endl;
        }
        cout << endl;
    }
    /**
     * free - checks if the given loction is occupied or free
     * @location: is a coordinate of the square location
     * return: true if the square are free and false if not
     */
    bool free(coor &location)
    {
	    return arr[location.y][location.x] == 0;
    }
    /**
     * square_to_coordinates - is a function convert the string
     * to the coordinates to used in perposes
     * @square: is the input square we want to convert
     * return: always the loction of square
     */
    coor square_to_coordinates(string &square)
    {
        coor ret;
        ret.x = square[0] - 'a';
        ret.y = square[1] - '1';
        return ret;
    }
    /**
     * get_id - is a funtion to get id of pieces by coordinates
     * @loction: is the x and y axises for the pieces
     * return: the id of the pieces
     */
    int get_id(coor &loction)
    {
        return arr[loction.y][loction.x];
    }
    /**
     * empty - make this square empty
     * @location: the loction of this square
     * return: void funtion
     */
    void empty(coor loction)
    {
        arr[loction.y][loction.x] = 0;
    }
};