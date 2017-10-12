// Reversi.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// reversi header file

#pragma once
#ifndef REVERSI_HEADER
#define REVERSI_HEADER
#include "common.h"
#include "gamePieces.h"
#include "GameClass.h"
#include <string>
using namespace std;

class Reversi : public GameClass 
{
	friend ostream &operator<<(ostream &out, const Reversi &rGame);
public:
	string user1 = " ";
	string user2 = " ";
	int userTurn = 0;
	virtual void setup_board();
	virtual	bool done();
	virtual bool stalemate();
	virtual int turn();
	virtual void print();
	bool AreValidMovesRemainingX();
	bool AreValidMovesRemainingO();


};

ostream &operator<<(ostream &out, const Reversi &rGame);


#endif
