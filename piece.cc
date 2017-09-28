//
//  bishop.cc
//  Chess
//
//  Created by Minglu Li on 7/17/16.
//  Copyright © 2016 Minglu Li. All rights reserved.
//
#include <vector>
#include <utility>
#include <iostream>
#include "piece.h"
using namespace std;


//*************************** King ******************************
// the ctor
King::King(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void King::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}


// check whether should put (r, c) into possibleChecks
bool King::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

King::~King() {}



//*************************** Queen ******************************
// the ctor
Queen::Queen(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void Queen::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}

// check whether should put (r, c) into possibleChecks
bool Queen::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

Queen::~Queen() {}



//*************************** Bishop ******************************
// the ctor
Bishop::Bishop(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void Bishop::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}

// check whether should put (r, c) into possibleChecks
bool Bishop::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

Bishop::~Bishop() {}



//*************************** Rook ******************************
// the ctor
Rook::Rook(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void Rook::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}

// check whether should put (r, c) into possibleChecks
bool Rook::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

Rook::~Rook() {}



//*************************** Knight ******************************
// the ctor
Knight::Knight(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void Knight::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}

// check whether should put (r, c) into possibleChecks
bool Knight::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

Knight::~Knight() {}



//*************************** Pawn ******************************
// the ctor
Pawn::Pawn(char type, char colour, vector<vector <Square>> &theBoard, int r, int c) : 
    ChessPiece(type, colour, theBoard, r, c) {}

// update possibleMoves & possibleAttacks
void Pawn::update() {
    
    // clear possibleMoves & possibleAttacks
    // (note: posibleChecks is cleared from its own update function)
    possibleMoves.clear();
    possibleAttacks.clear();
    
    int r = this->row;
    int c = this->col;
    
    // update possibleMoves & possibleAttacks in 4 diagonal directions:
    // up right, down right, down left, up left
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (!theBoard[r+i][c+i].isEmpty()) {
            if (theBoard[r+i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (!theBoard[r-i][c+i].isEmpty()) {
            if (theBoard[r-i][c+i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c+i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c+i));
        }
    }
    
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (!theBoard[r-i][c-i].isEmpty()) {
            if (theBoard[r-i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r-i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
            }
            break;
        }
        else {
            possibleMoves.emplace_back(make_pair<int, int>(r-i, c-i));
        }
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (!theBoard[r+i][c-i].isEmpty()) {
            if (theBoard[r+i][c-i].getColour() != this->getColour()) {
                possibleAttacks.emplace_back(make_pair<int, int>(r+i, c-i));
                possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
            }
            break;
        }
        else{
            possibleMoves.emplace_back(make_pair<int, int>(r+i, c-i));
        }
    }
    
    // update possibleChecks
    update_possibleChecks();
}

// check whether should put (r, c) into possibleChecks
bool Pawn::canCheck(const int r, const int c) {
    for (int i = 1; r+i <= 7 && c+i <= 7; i++) { // up right
        if (theBoard[r+i][c+i].isEmpty()) continue;
        else if (theBoard[r+i][c+i].getType() == 'K' && theBoard[r+i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c+i <= 7; i++) { // down right
        if (theBoard[r-i][c+i].isEmpty()) continue;
        else if (theBoard[r-i][c+i].getType() == 'K' && theBoard[r-i][c+i].getColour() != this->colour)
            return true;
        else break;
    }
    for (int i = 1; r-i >= 0 && c-i >= 0; i++) { // down left
        if (theBoard[r-i][c-i].isEmpty()) continue;
        else if (theBoard[r-i][c-i].getType() == 'K' && theBoard[r-i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    for (int i = 1; r+i <= 7 && c-i >= 0; i++) { // up left
        if (theBoard[r+i][c-i].isEmpty()) continue;
        else if (theBoard[r+i][c-i].getType() == 'K' && theBoard[r+i][c-i].getColour() != this->colour)
            return true;
        else break;
    }
    
    return false; // if non of above conditions returned, then finally return false
}

Pawn::~Pawn() {}

