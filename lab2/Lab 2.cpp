// Lab 1.cpp 
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) Nine Almonds Game

#include "stdafx.h"
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int usageMsg(char* prog_name, string str, enum errors err_) {
	cout << "usage: lab 2 <" << prog_name << ">" << endl;
	cout << "error was detected : ";
	cout << str << endl;
	return err_;
}

int main(int argc, char* argv[]) {
	//checks if exactly two elements are passed
	if (argc != arg_size) {
		string msg = "Type (NineAlmonds) to start game.";
		enum errors err_ = more_than_one;
		if (argc == 1) {
			return usageMsg(" ", msg, err_);
		}
		return usageMsg(argv[input_name], msg, err_);
	}

	//checks if the user correctly calls the function
	if (string(argv[input_name]) != "NineAlmonds") {
		string msg = "Type (NineAlmonds) to start game.";
		enum errors err_ = game_name_err;
		return usageMsg(argv[input_name], msg, err_);
	}

	//starts the game
	NineAlmondsGame newgame = NineAlmondsGame();
	cout << newgame;
	cout << newgame.play();

	return success;
}

