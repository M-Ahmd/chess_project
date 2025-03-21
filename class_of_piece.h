#include<set>
class piece
{
private:
    struct coordinates
    {
        int x, y;
    };
    int id;
    piece::coordinates location;
    bool color;
    piece::coordinates square_occiped; 
public:
    virtual bool bin() = 0;
    virtual bool move(piece::coordinates input) = 0;
    virtual std::set<piece::coordinates> range_of_motion() = 0;
    virtual void die() = 0;
};
