// GameClass.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : game base class header file

#pragma once
#ifndef GAMECLASS_HEADER
#define GAMECLASS_HEADER
#include "common.h"
#include "game_pieces.h"
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class GameClass
{
protected:
	std::vector<game_piece> mVector_Game_Board;
	unsigned int mDimHor;
	unsigned int mDimVer;
	unsigned int longest_str_len;
	int starting_piece;

public:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool stalemate() = 0;
	virtual int prompt(unsigned int & x_coord, unsigned int & y_coord);
	virtual int turn() = 0;
	virtual void setup_board() = 0;
	static GameClass * create_game(int argc, char* arg[]);
	virtual bool IsValidCoordinates(unsigned int coordinate_x, unsigned int coordinate_y);
	int play();
};

#endif
