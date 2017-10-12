// GameClass.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// Game base class source file

#include "stdafx.h"
#include "GameClass.h"
#include "NineAlmondsGame.h"
#include "common.h"
#include "gamePieces.h"
#include "MagicSquare.h"
#include "Reversi.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <memory>
#include <fstream>
#include <string>
using namespace std;

shared_ptr<GameClass> GameClass::smartPtr = nullptr;

shared_ptr<GameClass> GameClass::instance()
{
	if (smartPtr != nullptr) {
		return smartPtr;
	}
	else {
		throw nullptrexception;
	}
}

void GameClass::create_game(int argc, char* argv[]) {

	if (smartPtr != nullptr) {
		throw gameAlreadyExists;
	}
	if (smartPtr == nullptr) {
		//when only two arguments are passed, create a default board
		if (argc == arg_size_default) {
			if (string(argv[input_name]) == "NineAlmonds")
			{
				GameClass *P_game = new NineAlmondsGame;
				P_game->mDimHor = 5;
				P_game->mDimVer = 5;
				P_game->longest_str_len = 1;
				P_game->gameName = "NineAlmonds";
				smartPtr = shared_ptr<GameClass>(P_game);
			}
			else if (string(argv[input_name]) == "MagicSquare") {
				GameClass *P_game = new MagicSquare;
				P_game->mDimHor = 3;
				P_game->mDimVer = 3;
				P_game->longest_str_len = 1;
				P_game->starting_piece = 1;
				P_game->gameName = "MagicSquare";
				smartPtr = shared_ptr<GameClass>(P_game);
			}
			else if (string(argv[input_name]) == "Reversi") {
				GameClass *P_game = new Reversi;
				P_game->mDimHor = 8;
				P_game->mDimVer = 8;
				P_game->longest_str_len = 1;
				P_game->gameName = "Reversi";
				smartPtr = shared_ptr<GameClass>(P_game);
			}
			else {
				smartPtr = nullptr;
				throw gameNameErr;
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
					P_game->gameName = "MagicSquare";
					smartPtr = shared_ptr<GameClass>(P_game);
					//smartPtr = shared_ptr<MagicSquare>(P_game);

				}
				else {
					smartPtr = nullptr;
					throw dimErr;
				}
			}
			else {
				smartPtr = nullptr;
				throw gameNameErr;
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
						P_game->gameName = "MagicSquare";
						smartPtr = shared_ptr<GameClass>(P_game);
					}
					else {
						smartPtr = nullptr;
						throw startPieceErr;
					}
				}
				else {
					smartPtr = nullptr;
					throw dimErr;
				}
			}
			else {
				smartPtr = nullptr;
				throw gameNameErr;
			}
		}
		else
		{
			smartPtr = nullptr;
			throw argSizeErr;
		}
	}
}

int GameClass::play()
{
	
	try {
		openGame();
	}
	catch (enum result_codes err) {
		if (err == fileCannotOpen) {
			string empty_name = " ";
			string empty_sym = " ";
			//where there is no file to start, just start a new game

			for (unsigned int i = 0; i < mDimHor*mDimVer; ++i)
			{
				mVector_Game_Board.push_back(game_piece(no_color, empty_name, empty_sym));

			}

			if (gameName == "NineAlmonds") {
				for (int ver = mDimVer - 2; ver >= int(mDimVer - 4); --ver) {
					for (int hor = mDimHor - 4; hor < int(mDimHor - 1); ++hor) {
						mVector_Game_Board[mDimVer * ver + hor] = game_piece(brown, "Almond", "A");
					}
				}
			}
			else if (gameName == "Reversi") {
				int coord_x_1 = mDimHor * 3 + 3;
				int coord_x_2 = mDimHor * 4 + 4;
				int coord_o_1 = mDimHor * 3 + 4;
				int coord_o_2 = mDimHor * 4 + 3;
				mVector_Game_Board[coord_x_1] = game_piece(black, "X", "X");
				mVector_Game_Board[coord_x_2] = game_piece(black, "X", "X");
				mVector_Game_Board[coord_o_1] = game_piece(white, "O", "O");
				mVector_Game_Board[coord_o_2] = game_piece(white, "O", "O");
			}

		}
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
		++num_turns_played;
		// local_return value takes care of quit
	}

	if (this->done())
	{
		ofstream ofs;
		ofs.open(this->gameName + ".txt");
		if (!ofs.is_open())
		{
			throw(fileCannotOpen);
		}
		else {
			ofs << "NO_DATA" << endl;
		}
		ofs.close();
		cout << endl << "Game Completed, number of completed turns = " << num_turns_played << endl;
		return unsigned int(success);
	}

	else if (this->stalemate())
	{
		ofstream ofs;
		ofs.open(this->gameName + ".txt");
		if (!ofs.is_open())
		{
			throw(fileCannotOpen);
		}
		else {
			ofs << "NO_DATA" << endl;
		}
		ofs.close();
		cout << endl << "Stalemate, number of completed turns = " << num_turns_played << endl;
		return unsigned int(enum_stalemate);
	}

	else
	{
		cout << endl << "User Quit, number of completed turns = " << --num_turns_played << endl;// -- as they did not complete that turn.
		return unsigned int(enum_quit);
	}
}

bool GameClass::IsValidCoordinates(int coordinate_x, int coordinate_y)
{
	if (int(coordinate_x) > int(mDimVer) - 1 || int(coordinate_y) > int(mDimVer) - 1)
	{
		return false;
	}
	if (coordinate_x < 0 || coordinate_y < 0)
	{
		return false;
	}
	return true;
}

void GameClass::saveGame()
{
	ofstream ofs;
	ofs.open(this->gameName + ".txt");
	if (!ofs.is_open())
	{
		throw(fileCannotOpen);
	}
	else {
		bool save = true;
		bool input_is_satisfactory = false;
		string input;
		while (!input_is_satisfactory)
		{	//prompt user: save yes or no
			cout << "Do you want to save the game? Y/N " << endl;
			cin >> input;
			if (input != "y" && input != "Y" && input != "N" && input != "n")
			{
				input_is_satisfactory = false;
			}
			else
			{
				input_is_satisfactory = true;
			}
		}

		if (input == "N" || input == "n")
		{
			save = false;
		}
		if (save) {
			ofs << this->gameName << endl;
			for (unsigned int i = 0; i < mDimHor*mDimVer; ++i) {
				ofs << i << " ";
				if (mVector_Game_Board[i].piece_symbol_ == " ") {
					ofs << "!" << endl;	//special case to handle space
				}
				else {
					ofs << mVector_Game_Board[i].piece_symbol_ << endl;
				}
			}
			
			if (gameName == "Reversi") {
				ofs << this->PlayerNames << " " << num_turns_played << endl;

			}

			else 
			{
				ofs << num_turns_played << endl;

			}

		}
		else {
			ofs << "NO_DATA" << endl;
		}
		ofs.close();
	}
}

void GameClass::openGame() {
	ifstream ifs(this->gameName + ".txt");
	string gameState, line, pieceName;
	int coord;
	if (!(ifs.is_open()))
	{
		throw fileCannotOpen;
	}
	else
	{
		//initialize vector :
		for (unsigned int i = 0; i < mDimHor*mDimVer; ++i)
		{
			mVector_Game_Board.push_back(game_piece(no_color, " ", " "));
		}

		//checks if the previous game was saved or not
		getline(ifs, gameState);
		if (gameState == "NO_DATA")
		{//no game was saved, start a new game withe the initialized vector
			if (gameName == "NineAlmonds") {
				for (int ver = mDimVer - 2; ver >= int(mDimVer - 4); --ver) {
					for (int hor = mDimHor - 4; hor < int(mDimHor - 1); ++hor) {
						mVector_Game_Board[mDimVer * ver + hor] = game_piece(brown, "Almond", "A");
					}
				}
			}

			else if (gameName == "Reversi") {
				int coord_x_1 = mDimHor * 3 + 3;
				int coord_x_2 = mDimHor * 4 + 4;
				int coord_o_1 = mDimHor * 3 + 4;
				int coord_o_2 = mDimHor * 4 + 3;
				mVector_Game_Board[coord_x_1] = game_piece(black, "X", "X");
				mVector_Game_Board[coord_x_2] = game_piece(black, "X", "X");
				mVector_Game_Board[coord_o_1] = game_piece(white, "O", "O");
				mVector_Game_Board[coord_o_2] = game_piece(white, "O", "O");
			}

		}
		else
		{//game was saved, restore the state through parsing and rebuilding
			string temp, temp2;
			int counter = 0;
			while (getline(ifs, line))
			{
				istringstream iss(line);
				if (counter == mDimHor*mDimVer) { 
					if (gameState == "Reversi") {
						iss >> temp >> temp2;

						PlayerNames = temp + " " + temp2;
						cout << PlayerNames << endl;
					}
					iss >> num_turns_played;
	


					cout << endl;
				}
				if (!(iss >> coord >> pieceName)) {
					throw corruptGameState;
				}
				else {
					if (pieceName == "!") {
						pieceName = " "; //converts special case back to space
					}
					mVector_Game_Board[coord] = game_piece(brown, pieceName, pieceName);
					if (gameState == "MagicSquare") {
						mVector_Game_Board[coord] = game_piece(no_color, pieceName, pieceName);
						if (pieceName != " ") {
							msExisting.insert(stoi(pieceName));
						}
					}
				}
				++counter;
			}
		}
	}
	ifs.close();
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