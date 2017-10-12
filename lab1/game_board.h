// game_board.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 1) header file for game board source file

#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "lab1header.h"
#include "game_board.h"
#include "game_pieces.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//this function reads dimension from the input file
int dimensions(ifstream& input_file, unsigned int &a, unsigned int &b);

//this function reads each valid line from the input file 
//stores valid information to each new game piece
int read_pieces(ifstream& input_file, vector<game_piece>& pieces, unsigned int hor, unsigned int ver);

//this function prints out the game board
int print_board(const vector<game_piece>& gamepiece, unsigned int hor, unsigned int ver);

#endif
