#include <iostream>
#include <vector>
#include <utility>
#include "computer.h"

Computer::Computer(char pt, char colour): 
		Player(pt, colour) { }

int Computer::cMove(Board &b) {
	return 1;
}
/*
char Player::getPlayerType() {
        return playerType;
}

pair<int,char>  Player::moveFrom() {
        return make_pair(0, 'X');
}

pair<int,char> Player::moveTo() {
        return make_pair(0, 'X');
}*/
