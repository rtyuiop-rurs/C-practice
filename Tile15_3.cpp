#include<iostream>
#include "Random.h"
#include<algorithm>
#include<cassert>

constexpr int g_consoleLines{ 25 };

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


class Tile{
    int m_tile{0};
    public:
        Tile() = default;
        explicit Tile(int tile)
        : m_tile{tile}
        {}

        int getNum() const {return m_tile;};

        bool isEmpty() const {
            return m_tile == 0;
        }
};

std::ostream& operator<<(std::ostream& out, const Tile& t1){
    if(t1.getNum() > 9){
        out <<t1.getNum()<<"  "<<" ";
    }
    else if(t1.getNum() > 0){
        out <<t1.getNum()<<"   "<<" ";
    }
    else if(t1.getNum() == 0){
        out<<"    "<<" ";
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
        maxType
    };
    private:
    Type m_direction{};

    public:
    Direction(Type t1)
    : m_direction{t1}
    {}

    Type getDirection() const {return m_direction;};

    Direction operator-() const{
        switch(m_direction){
            case up : return Direction{down}; break;
            case down : return Direction{up}; break;
            case left : return Direction{right}; break;
            case right : return Direction{left}; break;
            default : break;
        }

        return Direction{up};
    }
    
    friend std::ostream& operator<<(std::ostream& out, Direction d1){
        switch(d1.getDirection()){
            case up : out << "up"; break;
            case down : out << "down"; break;
            case left : out << "left"; break;
            case right : out << "right"; break;
            default : break;
        }

        return out;
    }

    static Direction getRandomDirection(){
        return Direction{static_cast<Type>(Random::get(0,Direction::maxType - 1))};
    }
};


struct Point{
    int x{};
    int y{};

    friend bool operator==(Point mx, Point my){
        return mx.x == my.x && mx.y == my.y;
    }

    friend bool operator!=(Point mx, Point my){
        return !(mx == my);
    }

    Point getAdjacentPoint(Direction d1) const {
        switch(d1.getDirection()){
            case Direction::up : return Point{x, y-1}; break;
            case Direction::down : return Point{x, y+1};break;
            case Direction::left : return Point{x-1, y};break;
            case Direction::right: return Point{x+1, y};break;
            default: break;
        }

        return Point{-1,-1};
    }

    
};

class Board{
    static const int s_size{4};
    Tile tile_board[s_size][s_size] = {
        Tile{1},Tile{2},Tile{3},Tile{4},
        Tile{5},Tile{6},Tile{7},Tile{8},
        Tile{9},Tile{10},Tile{11},Tile{12},
        Tile{13},Tile{14},Tile{15},Tile{0},
    };
    public:
        Board() = default;

        friend std::ostream& operator<<(std::ostream& out, const Board& b1){
            for(int i = 0; i < g_consoleLines; i++){
                out << "\n";
            }

            for(int x{0}; x < s_size; ++x){
                for(int y{0}; y < s_size; ++y){
                    out << b1.tile_board[x][y];
                }
                out << "\n";
            }

            return out;
        }

        bool isValidTile(Point p1){
            return (p1.x >= 0 && p1.x < s_size) && (p1.y >= 0 && p1.y < s_size);
        }

        Point EmptyTile(){
            for(int y = 0; y < s_size; ++y){
                for(int x = 0; x < s_size; ++x){
                    if(tile_board[y][x].isEmpty()){
                        return Point{x,y};
                    }
                }
            }
            return Point{-1,-1};
        }

        void swapTiles(Point m1, Point m2){
            std::swap(tile_board[m1.y][m1.x],tile_board[m2.y][m2.x]);
        }

        bool moveTiles(Direction dir){
            Point empty_tile{EmptyTile()};
            Point adjacentTile{empty_tile.getAdjacentPoint(-dir)};
            if(!isValidTile(adjacentTile)){
                return false;
            }

            swapTiles(adjacentTile,empty_tile);
            return true;
        }

        friend bool operator==(Board& p1, Board& p2){
            for(int y = 0; y < s_size; ++y){
                for(int x = 0; x < s_size; ++x){
                    if(p1.tile_board[y][x].getNum() != p2.tile_board[y][x].getNum()){
                        return false;
                    }
                }
            }

            return true;
        }

        bool playerWon(){
            static Board s_board{};
            return s_board == *this;
        }

        void RandomizeBoard(){
            for(int i = 0; i < 1000;){
                if(moveTiles(Direction::getRandomDirection())){
                    i++;
                }
            }
        }
};


namespace userInput{
    char getCommandFromUser(){
        char choice{};
        std::cin>>choice;
        ignoreLine();
        return choice;
    }

    bool isValid(char ch){
        return ch == 'w'
        || ch == 'a'
        || ch == 's'
        || ch == 'd'
        || ch == 'q';
    }

    char getInput(){
        char ch{};
        while(!isValid(ch)){
            ch = getCommandFromUser();
        }

        return ch;
    }

    Direction chartoDirection(char ch){
        switch(ch){
            case 'w' : return Direction::up; break;
            case 's' : return Direction::down; break;
            case 'a' : return Direction::left; break;
            case 'd' : return Direction::right;break;
            default : break;
        }

        return Direction::up;
    }

};

int main(){
    Board board{};
    board.RandomizeBoard();
    std::cout << board;

    while(!board.playerWon()){
        char choice{userInput::getInput()};

        std::cout<<"Valid command : "<<choice<<"\n";
        std::cout<<"You entered direction "<<userInput::chartoDirection(choice)<<"\n";
        
        if(board.moveTiles(userInput::chartoDirection(choice))){
            std::cout<<board;
        }
        if(choice == 'q'){
            std::cout<<"\n\nBye\n\n";
            break;
        }
    }

    if(board.playerWon()){
        std::cout<<"\n\nYou won\n\n";
    }

    return 0;
}