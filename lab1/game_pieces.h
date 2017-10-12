// game_pieces.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 1 header) header file for game pieces source file

#pragma once
#ifndef GAMEPIECES_H
#define GAMEPIECES_H
#include "lab1header.h"
#include "game_board.h"
#include "game_pieces.h"
#include <string>
using namespace std;

enum piece_color 
{
	red,
	white,
	black,
	invalid_color,
	no_color,
};

//converts enum piece color to string
string enum_str(enum piece_color color);

//converts string to enum piece color
enum piece_color str_enum(string str);

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
