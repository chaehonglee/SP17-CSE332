// game piece.cpp 
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) game piece source file

#include "stdafx.h"
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//copies a game piece with the properties
game_piece::game_piece(enum piece_color color, string name, string display) :
	color_(color), name_(name), display_(display) {}