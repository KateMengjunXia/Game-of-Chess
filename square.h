#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <vector>
#include <iostream>
#include <memory>
#include "chesspiece.h"
#include "textdisplay.h"
#include "observer.h"

class ChessPiece;

class Square : public Observer {
  private:
    //vector <pair<char, int>> possibleMoves;  //put into chesspiece?
    //vector <pair<char, int>> possibleAttacks;
    std::vector <std::shared_ptr<Observer>> observers;
    int r;
    char c;
    //?bool incheck;
    char chess_type = 'X';
    char colour = 'X';
    //shared_ptr < vector<vector <Square>> > theBoard;
    std::shared_ptr<ChessPiece> piece;
  public:
    Square();    //square need to take 
    ~Square();
    //string getState();
    int getRow();
    int getCol();
    bool isEmpty();
    void setType(char type);
    void setColour(char co);
    void clearPiece();
    char getType();
    char getColour();
    void setCoords(int row, int col);
    void setPiece(char type, char co, std::vector<std::vector <Square>> &theBoard);
    bool canMove(int r, int c);
    bool canAttack(int r, int c);
    bool canAvoidCapture(int r, int c);
    void addMove(int r, int c);
    void addAttack(int r, int c);

    std::pair<int, int> getMoveCoord(int rand);
    std::pair<int, int> getAttackCoord(int rand);
    std::pair<int, int> getCheckCoord(int rand);

    int sizeMove();
    int sizeAttack();
    int sizeCheck();

    bool inCheck(int r, int c);
    bool firstMove();
    bool secondMove();

    void attach(const std::shared_ptr<Observer>& o);
    void notify(Square &, std::vector<std::vector<Square>> &theBoard) override;
    void notifyAll(std::vector<std::vector<Square>> &theBoard);
    void move_piece(int r, int c, std::vector<std::vector <Square>> &theBoard);
    void attack_piece(int r, int c, std::vector<std::vector <Square>> &theBoard);

};
#endif
