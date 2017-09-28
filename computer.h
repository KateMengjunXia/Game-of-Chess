#ifndef _COMPUTER_H_
#define _COMPUTER_H_
#include <iostream>
#include <vector>
#include "player.h"

class Computer: public Player {
	//char playerType; // either 'H' (human player) or 'C' (computer player)
	//char colour; // either 'W' (white) or 'B' (black)
  public:
  	Computer(char pt, char colour);
  	//char getPlayerType();
//  	~Computer() = 0;
  	//char getColourTurn();
  	virtual int cMove(Board &b) override;
//  	virtual pair<int, char> moveFrom() override;
 // 	virtual pair<int, char> moveTo() override;
};


#endif
