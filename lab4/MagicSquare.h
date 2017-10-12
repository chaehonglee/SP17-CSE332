// MagicSquare.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// magic square header file

#pragma once
#ifndef MAGICSQUARE_HEADER
#define MAGICSQUARE_HEADER
#include "common.h"
#include "gamePieces.h"
#include "GameClass.h"
#include <iostream>
#include <set>
using namespace std;

class MagicSquare : public GameClass
{
	friend ostream &operator<<(ostream &out, const MagicSquare &rGame);
public:
	set<int> numPieces;
	virtual	bool done();
	virtual int prompt(int &number);
	virtual bool stalemate();
	virtual int turn();
	virtual void print();
	virtual void setup_board();
	bool isInTheSet(int &number);
	int starting_piece = 1;
};
ostream &operator<<(ostream &out, const MagicSquare &rGame);

#endif