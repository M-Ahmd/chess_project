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
    int arr[8][8]{};
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
    board()
    {
        arr[0][0] = black_rook;
        arr[0][1] = black_knight;
        arr[0][2] = black_bishob;
        arr[0][3] = black_queen;
        arr[0][4] = black_king;
        arr[0][5] = black_bishob;
        arr[0][6] = black_knight;
        arr[0][7] = black_rook;
        for(int i = 0; i < 8; i++)
            arr[1][i] = black_pawn;
        for(int i = 0; i < 8; i++)
            arr[6][i] = white_pawn;
        arr[7][0] = white_rook;
        arr[7][1] = white_knight;
        arr[7][2] = white_bishob;
        arr[7][3] = white_queen;
        arr[7][4] = white_king;
        arr[7][5] = white_bishob;
        arr[7][6] = white_knight;
        arr[7][7] = white_rook;
    }
    void print_board_for_white()
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
                cout << convert(arr[i][j]) << " ";
            cout << "\n";
        }
        cout << endl;
    }
    void print_board_for_black()
    {
        for(int i = 7; i >= 0; i--)
        {
            for(int j = 7; j >= 0; j--)
                cout << convert(arr[i][j]) << " ";
            cout << endl;
        }
        cout << endl;
    }
    bool free(coor &location)
    {
	    return arr[location.x][location.y] == 0;
    }
    

};