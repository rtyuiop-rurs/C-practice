#include<iostream>
#include<algorithm>
#include "Random.h"
#include<cassert>

constexpr int g_consoleLines{ 25 };

class Tile{

    int m_tile{};
    public:
        Tile() = default;
        explicit Tile(int tile)
        :m_tile{tile}
        {}

        int getNum() const {return m_tile;};

        bool isEmpty(){
            return m_tile == 0;
        }
};

std::ostream& operator<<(std::ostream& out, Tile t1){
    if(t1.getNum() > 9){
        out <<" "<<t1.getNum()<<" ";
    }
    else if(t1.getNum() > 0){
        out<<"  "<<t1.getNum()<<" ";
    }
    else if(t1.getNum() == 0){
        out << "   "<<" ";
    }

    return out;
}

class Direction{
    public:
    enum Type{
        up,
        down,
        left,
        right,
        MaxDirections
    };

    Direction(Type direction)
    : m_direction{direction}
    {}

    Type getType() const {return m_direction;};

    Direction operator-() const {
        switch(m_direction){
            case up    : return Direction{down};  
            case down  : return Direction{up};    
            case left  : return Direction{right}; 
            case right : return Direction{left};  
            default    : break;
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{up};
    }

    static Type getRandomType(){
        Type randomType{static_cast<Type>(Random::get(0,MaxDirections - 1))};
        return randomType;
    }

    private:
        Type m_direction{};
};

std::ostream& operator<<(std::ostream& out, Direction m1){
    switch(m1.getType()){
        case Direction::up    : (out << "up");    break;
        case Direction::down  : (out << "down");  break;
        case Direction::left  : (out << "left");  break;
        case Direction::right : (out << "right"); break;
        default               : break;
    }

    return out;
}

struct Point{
    int x{};
    int y{};

    friend bool operator==(Point mx, Point my){
        return (mx.x == my.x) && (mx.y == my.y);
    }

    friend bool operator!=(Point mx, Point my){
        return (mx != my);
    }

    Point getAdjacentPoint(Direction d1) const{
        switch(d1.getType()){
            case Direction::up    : return Point{x, y-1}; break;
            case Direction::down  : return Point{x, y+1}; break;
            case Direction::left  : return Point{x-1, y}; break;
            case Direction::right : return Point{x+1, y}; break;
            default               : break;
        }

        return Point{-1,-1};
    }
};


class Board{
    static const int s_size{4};
    Tile tile[s_size][s_size] = {
        Tile{ },Tile{1},Tile{2},Tile{3},
        Tile{4},Tile{5},Tile{6},Tile{7},
        Tile{8},Tile{9},Tile{10},Tile{11},
        Tile{12},Tile{13},Tile{14},Tile{15}
    };
    public:
        Board() = default;

        friend std::ostream& operator<<(std::ostream& out, Board b1){
            for(int i = 0; i < g_consoleLines; i++){
                std::cout<<"\n";
            }

            for(int y{0}; y < s_size; ++y){
                for(int x{0}; x < s_size; ++x){
                    std::cout<<b1.tile[y][x]<<" ";
                }
                std::cout<<"\n";
            }

            return out;
        }

        static bool isValid(Point p1){
            return (p1.x >= 0 && p1.x < s_size) && (p1.y >= 0 && p1.y < s_size);
        }

        Point emptyTilePoint(){
            for(int x = 0; x < s_size; ++x){
                for(int y = 0; y < s_size; ++y){
                    if(tile[y][x].isEmpty()){
                        return Point{x,y};
                    }
                }
            }
            assert(0 && "There is no empty tile in the board!!!");
            return Point{-1,-1};
        }

        void swapTiles(Point p1, Point p2){
            std::swap(tile[p1.y][p1.x],tile[p2.y][p2.x]);
        }

        bool moveTile(Direction dir){
            Point emptyTile{emptyTilePoint()};
            Point adj{emptyTile.getAdjacentPoint(-dir)};
            if(!isValid(adj)){
                return false;
            }

            swapTiles(adj,emptyTile);
            return true;
        }

        friend bool operator==(const Board m1, const Board m2){
           for(int x = 0; x < s_size; ++x){
            for(int y = 0; y < s_size; ++y){
                if(m1.tile[y][x].getNum() != m2.tile[y][x].getNum()){
                    return false;
                }
            }
           }
           return true;
        }

        bool playerWon(){
            static Board b1{};
            return b1 == *this;
        }

        void RandomizeBoard(){
            for(int i = 0; i < 1000;){
                if(moveTile(Direction::getRandomType())){
                    i++;
                }
            }
        }

};


namespace UserInput{
    void ignoreLine(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool ValidInput(char ch){
        return ch == 'w' 
            || ch == 'a'
            || ch == 's'
            || ch == 'd'
            || ch == 'q';
    }

    char getInput(){
        char input;
        std::cin>>input;
        ignoreLine();
        return input;
    }

    char getCommandFromUser(){
        char ch;
        while(!ValidInput(ch)){
            ch = getInput();
        }

        return ch;
    }

    Direction getDirection(char ch){
        switch(ch){
            case 'w' : return Direction::up;    break;
            case 'a' : return Direction::left;  break;
            case 's' : return Direction::down;  break;
            case 'd' : return Direction::right; break;
            default  : break;
        }

        return Direction::MaxDirections;
    }

}



int main(){
    Board board{};
    board.RandomizeBoard();
    std::cout<<board;

    std::cout<<"Enter a command: ";
    while(!board.playerWon()){
        char input{UserInput::getCommandFromUser()};

        if(UserInput::ValidInput(input)){
            std::cout<<"valid input: "<<input<<"\n";
        }
        if(input == 'q'){
            std::cout<<"\n\nBye!\n\n";
        }

        Direction dir{ UserInput::getDirection(input) };
        std::cout << "You entered direction: " << dir << '\n';

        bool isMoved{board.moveTile(dir)};
        if(isMoved){
            std::cout<<board;
        }

    }

    std::cout<<"\n\nYou won!\n\n";
}