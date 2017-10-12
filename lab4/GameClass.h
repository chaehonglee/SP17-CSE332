// GameClass.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// game base class header file

#pragma once
#ifndef GAMECLASS_HEADER
#define GAMECLASS_HEADER
#include "common.h"
#include "gamePieces.h"
#include <vector>
#include <set>
#include <memory>
#include <iostream>
using namespace std;

class GameClass
{
protected:
	static shared_ptr<GameClass> smartPtr;
	std::vector<game_piece> mVector_Game_Board;
	unsigned int mDimHor;
	unsigned int mDimVer;
	unsigned int longest_str_len;
	string gameName = " ";
	string PlayerNames = "";
	int num_turns_played = 0;
	int starting_piece;
	std::set<int> msExisting;

public:
	static shared_ptr<GameClass> instance();
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool stalemate() = 0;
	virtual int prompt(unsigned int & x_coord, unsigned int & y_coord);
	virtual int turn() = 0;
	virtual void setup_board() = 0;
	static void create_game(int argc, char* arg[]);
	virtual bool IsValidCoordinates(int coordinate_x, int coordinate_y);
	virtual void saveGame();
	virtual void openGame();
	int play();
};

#endif
