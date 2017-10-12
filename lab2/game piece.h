// game piece.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) header of the game piece source

#pragma once
#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
using namespace std;

enum piece_color
{
	red,
	white,
	black,
	brown,
	invalid_color,
	no_color,
};

//new struct of a game piece
struct game_piece
{
	//this function creates a game piece with the passed values
	game_piece(enum piece_color color, string name, string display);
	enum piece_color color_;
	string name_;
	string display_;
};

#endif 
