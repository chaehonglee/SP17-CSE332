// lab1header.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 1 header) main header file or Lab 1.cpp

#pragma once
#ifndef LAB1_H
#define LAB1_H
#include "lab1header.h"
#include "game_board.h"
#include "game_pieces.h"
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
	file_cannot_open,
	no_dimension,
	unable_to_read_line,
	more_than_one,
	no_game_pieces,
	dimensions_does_not_match,
	not_a_digit
};
int usageMsg(char* prog_name, string str, enum errors err_);
//converts a string into all lowercase
void convertLower(string& str);

#endif
