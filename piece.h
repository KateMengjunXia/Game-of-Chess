#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "chesspiece.h"
#include "square.h"
#include "board.h"

// King
class King : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    King(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~King();
};

// Queen
class Queen : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    Queen(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~Queen();
};

// Bishop
class Bishop : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    Bishop(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~Bishop();
};

// Rook
class Rook : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    Rook(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~Rook();
};

// Knight
class Knight : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    Knight(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~Knight();
};

// Pawn
class Pawn : public ChessPiece {
    bool canCheck(int r, int c) override;
public:
    Pawn(char type, char colour, vector<vector <Square>> &theBoard, int r, int c);
    void update() override;
    ~Pawn();
};
#endif /* piece.h */
