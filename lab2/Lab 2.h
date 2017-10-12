// Lab 2.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) header of the main source

#pragma once
#ifndef LAB2_H
#define LAB2_H
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
using namespace std;

enum arrayIndex
{
	prog_name,
	input_name,
	arg_size
};

enum errors
{
	success,
	more_than_one,
	isvalid,
	startIndex_finishIndex_same,
	startIndex_without_almond,
	not_two_away,
	finishIndex_occupied,
	no_middle_almond,
	user_quit_game,
	valid_coordinates,
	game_over,
	isstalemate,
	game_name_err,
	no_possible_moves
};

int usageMsg(char* prog_name, string str, enum errors err_);


#endif 
