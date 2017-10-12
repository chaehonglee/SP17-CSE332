// Lab 1.cpp 
// Annie Lee : annie.lee@wustl.edu
// (Lab 1) Game Boards and Pieces: 

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

int usageMsg(char* prog_name, string str, enum errors err_) {
	cout << "usage: lab 1 <" << prog_name << ">" << endl;
	cout << "error was detected : ";
	cout << str << endl;
	return err_;
}

void convertLower(string& str) {
	for (unsigned int i = 0; i < str.size(); ++i)
	{
			str[i] = tolower(str[i]);
	}
}

int main(int argc, char * argv[]) {
    
    
	

	//checks to see if exactly one argument is passed------
	if (argc != arg_size) 
	{
		string msg = "enter only one file name";
		enum errors err_ = more_than_one;
		return usageMsg(argv[input_name], msg, err_);
	}
	//-----------------------------------------------------
    
    ifstream inputfile(argv[input_name]);
    unsigned int hor, ver;

	//checks to see if the file exists---------------------
	if (!inputfile.is_open())
	{
		string msg = "the file does not exist";
		enum errors err_ = file_cannot_open;
		return usageMsg(argv[input_name], msg, err_);
	}
	//------------------------------------------------------


	//if unable to extract the dimensions, call it again----
	while (dimensions(inputfile, hor, ver) != success) {
		//if no dimension was read, print out error msg-----
		if (dimensions(inputfile, hor, ver) == unable_to_read_line
            || dimensions(inputfile, hor, ver) == no_dimension) {
			string msg = "this file contains no dimensions";
			enum errors err_ = no_dimension;
			return usageMsg(argv[input_name], msg, err_);
		}		
	}
	//------------------------------------------------------
	
	

	//assigns default piece to the vector-------------------
	game_piece defaultpiece(no_color, "empty", " ");
	vector<game_piece> pieces;
	unsigned int board_size = ver*hor;
	for (unsigned int i = 0; i < board_size; ++i) {
		pieces.push_back(defaultpiece);
	}
	//------------------------------------------------------

	read_pieces(inputfile, pieces, hor, ver);
	print_board(pieces, hor, ver);
	inputfile.close();
	return success;
}

