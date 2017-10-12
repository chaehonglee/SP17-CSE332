// game_pieces.h
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : game pieces header file

#pragma once
#ifndef GAMEPIECES_HEADER
#define GAMEPIECES_HEADER
#include "common.h"
using namespace std;

enum piece_color { red, white, black , brown, invalid_color, no_color};
struct game_piece
{
	game_piece(piece_color enum_piece_color, string piece_name, string piece_symbol);
	piece_color enum_piece_color_;
	string piece_name_;
	string piece_symbol_;
};

#endif
