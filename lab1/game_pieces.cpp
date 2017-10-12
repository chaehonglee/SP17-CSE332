// game_pieces.cpp
// Annie Lee : annie.lee@wustl.edu
// (Lab 1) Game pieces source file

#include "stdafx.h"
#include "lab1header.h"
#include "game_board.h"
#include "game_pieces.h"
#include <string>
using namespace std;

game_piece::game_piece(enum piece_color color, string name, string display) :
	color_(color), name_(name), display_(display){}

string enum_str(enum piece_color color) {
	string strcolor;
	if (color == piece_color::red)
	{
		strcolor = "red";
	}
	else if (color == piece_color::white) 
	{
		strcolor = "white";
	}
	else if (color == piece_color::black) 
	{
		strcolor = "black";
	}
	else if (color == piece_color::invalid_color) 
	{
		strcolor = "invalid color";
	}
	else if (color == piece_color::no_color) 
	{
		strcolor = "no color";
	}
	return strcolor;
}

enum piece_color str_enum(string str) {
	enum piece_color enum_color;
	if (str == "red") 
	{
		enum_color = piece_color::red;
	}
	else if (str == "white") 
	{
		enum_color = piece_color::white;
	}
	else if (str == "black") 
	{
		enum_color = piece_color::red;
	}
	else if (str == " ") 
	{
		enum_color = piece_color::no_color;
	}
	else 
	{
		enum_color = piece_color::invalid_color;
	}
	return enum_color;
}