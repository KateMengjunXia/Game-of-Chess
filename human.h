#ifndef _HUMAN_H_
#define _HUMAN_H_
#include <iostream>
#include <vector>
#include "player.h"

class Human: public Player {
	//char playerType; // either 'H' (human player) or 'C' (computer player)
	//char colour; // either 'W' (white) or 'B' (black)
  public:
  	Human(char colour, char pt);
  	//char getPlayerType();
  	//char getColourTurn();
  	void displayInvalid();
  	std::pair<int, char> moveFrom() override;
  	std::pair<int, char> moveTo() override;
//	int cMove(Board &b) override;
};


#endif
