// GameClass.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : Game base class source file

#include "stdafx.h"
#include "GameClass.h"
#include "NineAlmondsGame.h"
#include "common.h"
#include "game_pieces.h"
#include "MagicSquare.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <memory>
using namespace std;

GameClass* GameClass::create_game(int argc, char* argv[]) {

	//when only two arguments are passed, create a default board
	if (argc == arg_size_default) {
		if (string(argv[input_name]) == "NineAlmonds")
		{
			GameClass *P_game = new NineAlmondsGame;
			P_game->mDimHor = 5;
			P_game->mDimVer = 5;
			P_game->longest_str_len = 1;
			return P_game;
		}
		else if (string(argv[input_name]) == "MagicSquare") {
			GameClass *P_game = new MagicSquare;
			P_game->mDimHor = 3;
			P_game->mDimVer = 3;
			P_game->longest_str_len = 1;
			P_game->starting_piece = 1;
			return P_game;
		}
		else {
			GameClass *singPointer = 0;
			return singPointer;
		}
	}
	
	//when three arguments are passed, the user defines the dimension of MS game
	else if (argc == arg_size_ms_boardsize) {
		if (string(argv[input_name]) == "MagicSquare") {
			string temp = argv[board_size];
			istringstream iss(temp);
			int boardDim;
			if ((iss >> boardDim) && (boardDim > 0)) { //if only the dimension is a number > 0
				GameClass *P_game = new MagicSquare;
				P_game->mDimHor = boardDim;
				P_game->mDimVer = boardDim;
				P_game->longest_str_len = 1;
				P_game->starting_piece = 1;
				return P_game;
			}
			else {
				GameClass *singPointer = 0;
				return singPointer;
			}
		}
		else {
			GameClass *singPointer = 0;
			return singPointer;
		}
	}

	//when four arguments are passed, the user defines the dimension and the starting piece
	else if (argc == arg_size_ms_startpeice) {
		if (string(argv[input_name]) == "MagicSquare") {
			string temp = argv[board_size];
			istringstream iss(temp);
			int boardDim;
			if ((iss >> boardDim) && (boardDim > 0)) {
				temp = argv[start_piece];
				istringstream iss2(temp);
				int startPiece;
				if (iss2 >> startPiece) { //if only the starting piece is a number
					GameClass *P_game = new MagicSquare;
					P_game->mDimHor = boardDim;
					P_game->mDimVer = boardDim;
					P_game->longest_str_len = 1;
					P_game->starting_piece = startPiece;
					return P_game;
				}
				else {
					GameClass *singPointer = 0;
					return singPointer;
				}
			}
			else {
				GameClass *singPointer = 0;
				return singPointer;
			}
		}
		else {
			GameClass *singPointer = 0;
			return singPointer;
		}
	}
	else
	{
		GameClass *singPointer = 0;
		return singPointer;
	}
}

int GameClass::play()
{
	//game board should be initialized here
	string empty_name = " ";
	string empty_sym = " ";
	int num_of_turns = 0;
	for (unsigned int i = 0; i < mDimHor*mDimVer; ++i)
	{
		mVector_Game_Board.push_back(game_piece(no_color, empty_name, empty_sym));
	}
	
	//add method for setting up board
	int local_quit = 1;	// this method would be called just once,
						// thus we can initialize it to 1.
						//cout << *this << endl;
						//print out game board;
	setup_board();
	print();
	

	while (!this->done() && !this->stalemate() && local_quit != int(enum_quit))
	{
		local_quit = this->turn();	
		++num_of_turns;
		// local_return value takes care of quit
	}
	
	if (this->done())
	{
		cout << endl << "Game Completed, number of completed turns = " << num_of_turns << endl;
		return unsigned int(success);
	}

	else if (this->stalemate())
	{
		cout << endl << "Stalemate, number of completed turns = " << num_of_turns << endl;
		return unsigned int(enum_stalemate);
	}

	else
	{
		cout << endl << "User Quit, number of completed turns = " << --num_of_turns << endl;// -- as they did not complete that turn.
		return unsigned int(enum_quit);
	}
}

bool GameClass::IsValidCoordinates(unsigned int coordinate_x, unsigned int coordinate_y)
{
	if (int(coordinate_x) > int(mDimVer) - 1 || int(coordinate_y) > int(mDimVer) - 1)
	{
		return false;
	}
	if (int(coordinate_x) < 0 || int(coordinate_y) < 0)
	{
		return false;
	}
	return true;
}

int GameClass::prompt(unsigned int & x_coord, unsigned int & y_coord)
{
	// will check if coordinates are valid.
	string input_string;


	bool check_length = false, check_comma = false, check_coord_validity = false;
	int check_digitL = 0, check_digitR = 0;
	int what = 0;
	while (
		(check_length != true && check_digitL != 1 && check_digitR != 1 && check_comma != true) ||
		check_coord_validity != true)
	{
		cin >> input_string;


		if (input_string == "quit")
		{
			return enum_quit;
		}

		check_length = (int(input_string.length()) == int(length_input_string));

		if (check_length)
		{
			check_digitL = (isdigit(input_string.at(0)));
			check_digitR = (isdigit(input_string.at(2)));

			check_comma = (input_string.at(1) == ',');

			if (check_digitL && check_digitR && check_comma)
			{

				int input1 = input_string.at(0);
				int input2 = (input_string.at(2));
				input1 = input1 - 48;// converting ascii to numbers
				input2 = input2 - 48;// converting ascii to numbers


				check_coord_validity = IsValidCoordinates(input1, input2);
				if (check_coord_validity != true)
				{
					cout << " invalid coordinates. Enter again" << endl;
				}
			}

			else
			{
				cout << " Wrong format. Enter again" << endl;
				
			}
		}

		else
		{
			cout << " Wrong format. Enter again" << endl;
		}
		

	}

	x_coord = input_string.at(0);
	x_coord = x_coord - 48;
	y_coord = input_string.at(2);
	y_coord = y_coord - 48;

	return success;

}
