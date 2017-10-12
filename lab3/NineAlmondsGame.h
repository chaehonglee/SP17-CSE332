// NineAlmondsGame.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : nine almonds game header file

#pragma once
#ifndef NINEALMONDS_HEADER
#define NINEALMONDS_HEADER
#include "common.h"
#include "game_pieces.h"
#include "GameClass.h"
#include <iostream>
using namespace std;


class NineAlmondsGame : public GameClass
{
	friend ostream &operator<<(ostream &out, const NineAlmondsGame &rGame);
public:
	virtual	bool done();
	virtual bool stalemate();
	virtual int turn();
	virtual void print();
	virtual void setup_board();
	bool IsValidMove(
		unsigned int coordinate_initial_x,
		unsigned int coordinate_initial_y,
		unsigned int coordinate_final_x,
		unsigned int coordinate_final_y);
	/*checks:
	1. coordinate bounds
	2. validity of the move
	*/
};

ostream &operator<<(ostream &out, const NineAlmondsGame &rGame);
#endif
