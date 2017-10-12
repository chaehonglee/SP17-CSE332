// gmae_pieces.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : game pieces source file

#include "stdafx.h"
#include "game_pieces.h"
#include <iostream>
using namespace std;

game_piece::game_piece(piece_color enum_piece_color, string piece_name, string piece_symbol)
	:enum_piece_color_(enum_piece_color), piece_name_(piece_name), piece_symbol_(piece_symbol) {}


