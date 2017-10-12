// game_board.cpp
// Annie Lee : annie.lee@wustl.edu
// (Lab 1) Game board source file

#include "stdafx.h"
#include "lab1header.h"
#include "game_board.h"
#include "game_pieces.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


int dimensions(ifstream& input_file, unsigned int &hor, unsigned int &ver) {
	string str;
	if (getline(input_file, str)) 
	{
		istringstream iss(str);
		if (iss >> hor >> ver) 
		{
			return success;
		}
		else 
		{
			return no_dimension;
		}
	}
	else
	{
		return unable_to_read_line;
	}
}

int read_pieces(ifstream& input_file, vector<game_piece>& pieces, 
				unsigned int hor, unsigned int ver) 
{
	string str, piece_color, piece_name, display;
	unsigned int x, y;
	while (getline(input_file, str))
	{
		istringstream iss(str);
		iss >> piece_color >> piece_name >> display >>  x >> y;
		convertLower(piece_color);
		game_piece newpiece(str_enum(piece_color), piece_name, display);

		//stores the piece only if it has valid color
		//and if the position is within the board
		if (newpiece.color_ != invalid_color) 
		{
			if (!(x >= hor || y >= ver))
			{
				//pieces[hor*x + y] = newpiece;
				pieces[hor*y + x] = newpiece;
			}
		}
	}
	return success;
}

int print_board(const vector<game_piece>& gamepiece, 
				unsigned int hor, unsigned int ver) 
{
	unsigned int count = 0;
	//checks to see if the vector size agrees with the board dimension
	if (gamepiece.size() != hor*ver)
	{
		cout << "dimensions do not match" << endl;
		return dimensions_does_not_match;
	}
	for (unsigned int i = 0; i < hor*ver; ++i)
	{
		while (count < hor*ver) {
			for (unsigned int j = 0; j <= hor - 1; ++j)
			{
				cout << " " << gamepiece[count].display_ << " ";
				count = count + 1;
			}
			cout << endl;
		}
	}
	return success;
}
