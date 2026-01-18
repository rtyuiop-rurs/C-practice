#include<iostream>
#include<limits>
#include "Random.h"
#include<cassert>
#include<algorithm>

class Direction{
    public:
        enum Type{
            up,
            down,
            left,
            right,
            maxDirections
        };

        Direction(Type initialType)
        : m_direction{initialType}
        {}

        Type getType() const {return m_direction;};

        Direction operator-() const{
            switch(m_direction){
                case up    : return Direction{down};
                case down  : return Direction{up};
                case left  : return Direction{right};
                case right : return Direction{left};
                default    : break;
            }

            assert(0 && "Unsupported direction was passed!");
            return Direction{ up };
        }

        static Direction RandomDirection(){
            Type m1{static_cast<Type>(Random::get(0,Type::maxDirections - 1))};
            return Direction{m1};
        }
    

    private:
        Type m_direction{};

};


std::ostream& operator<<(std::ostream& out, Direction m1){
    switch(m1.getType()){
        case Direction::up:    out << "up";    break;
        case Direction::down:  out << "down";  break;
        case Direction::left:  out << "left";  break;
        case Direction::right: out << "right"; break;
        default:               out << "unknown"; break;
    }
    return out; // Remove the assert(0) here so it can actually return
}

struct Point{
    int x{};
    int y{};

    friend bool operator==(Point m1, Point m2){
        return m1.x == m2.x && m1.y == m2.y;
    }

    friend bool operator!=(Point m1, Point m2){
        return !(m1 == m2);
    }

   Point getAdjacentPoint(Direction m1) const {
        switch(m1.getType()){
            case Direction::up    :  return Point{x, y-1};
            case Direction::down  :  return Point{x, y+1};
            case Direction::left  :  return Point{x-1, y};
            case Direction::right :  return Point{x+1, y};
            default               :  break;
        }
        assert(0 && "Unsupported direction was passed!");
        return *this;
   }
    
};

namespace UserInput{
    void ignoreLine(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValid(char ch){
       return  ch == 'w'
            || ch == 'a'
            || ch == 's'
            || ch == 'd'
            || ch == 'q';
    }

    char getCharacter(){
        char input{};
        std::cin>>input;
        ignoreLine();
        return input;
    }

    char getCommandFromUser(){
        char ch;
        while(!isValid(ch)){
            ch = getCharacter();
        }
        return ch;
    }

    Direction charToDirection(char ch){
        switch(ch){
            case 'w' : return Direction{Direction::up};
            case 's' : return Direction{Direction::down};
            case 'a' : return Direction{Direction::left};
            case 'd' : return Direction{Direction::right};
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{Direction::up};
    }
};


class Tile{
    int m_tile;
    public:
        Tile() = default;
        explicit Tile(int tiles)
        : m_tile{tiles}
        {}

        bool isEmpty() const {
            return m_tile == 0;
        }

        int getNum () const {return m_tile;};
};

std::ostream& operator<<(std::ostream& stream, Tile tile){
    if (tile.getNum() > 9) // if two digit number
        stream << " " << tile.getNum() << " ";
    else if (tile.getNum() > 0) // if one digit number
        stream << "  " << tile.getNum() << " ";
    else if (tile.getNum() == 0) // if empty spot
        stream << "    ";
    return stream;
}



constexpr int g_consoleLines{ 3 };
class Board{
    public:
        Board() = default;

        static void printEmptyLines(int count){
            for( int i = 0; i < count; i++){
                std::cout<<"\n";
            }
        }

        friend std::ostream& operator<<(std::ostream& out, Board b1){
            for(int i = 0; i < g_consoleLines; ++i){
                std::cout<<"\n";
            }

            for(int y = 0; y < s_size; ++y){
                for(int x = 0; x < s_size; ++x){
                    out << b1.m_tiles[y][x];
                }
                out << "\n";
            }

            return out;

        }

        Point emptyTitlePos() const {
            for(int y = 0; y < s_size; ++y){
                for(int x = 0; x < s_size; ++x){
                    if(m_tiles[y][x].isEmpty()){
                        return {x,y};
                    }
                }
            }
            assert(0 && "There is no empty tiles on the board!");
            return {-1,-1};
        }

        static bool isValid(Point pt){
            return (pt.x >= 0 && pt.x < s_size) && (pt.y >= 0 && pt.y < s_size);
        }

        void swapTiles(Point p1, Point p2){
            std::swap(m_tiles[p1.y][p1.x],m_tiles[p2.y][p2.x]);
        }

        friend bool operator==(const Board& m1, const Board& m2){
            for(int y = 0; y < s_size; ++y){
                for(int x = 0; x < s_size; ++x){
                    if(m1.m_tiles[y][x].getNum() != m2.m_tiles[y][x].getNum()){
                        return false;
                    }
                }
            }
            return true;
        }

        bool moveTile(Direction d1){
            Point emptyTile{emptyTitlePos()};
            Point adj{emptyTile.getAdjacentPoint(-d1)};
            if(!isValid(adj)){
                return false;
            }
            swapTiles(adj,emptyTile);
            return true;
        }

        bool playerWon() const {
            static Board s_solved{};
            return s_solved == *this;
        }

        void RandomizeTiles(){
            for(int i = 0; i < 1000;){
                if(moveTile(Direction::RandomDirection()))
                i++;
            }
        }
    private:
    static const int s_size{4};
    Tile m_tiles[s_size][s_size] = {
        {Tile{},Tile{1},Tile{2},Tile{3}},
        {Tile{4},Tile{5},Tile{6},Tile{7}},
        {Tile{8},Tile{9},Tile{10},Tile{11}},
        {Tile{12},Tile{13},Tile{14},Tile{15}}
    };

};


int main()
{
    Board board{};
    board.RandomizeTiles();
    std::cout << board;

    std::cout << "Enter a command: ";
    while (!board.playerWon())
    {
        char ch{ UserInput::getCommandFromUser() };


        // Handle non-direction commands
        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::charToDirection(ch) };
        std::cout << "You entered direction: " << dir << '\n';

        bool isMoved{board.moveTile(dir)};
        if(isMoved){
            std::cout<<board;
        }
    }

    std::cout << "\n\nYou won!\n\n";
    return 0;
}