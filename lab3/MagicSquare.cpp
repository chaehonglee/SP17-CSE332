// MagicSquare.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : magic square source file

#include "stdafx.h"
#include "GameClass.h"
#include "NineAlmondsGame.h"
#include "common.h"
#include "game_pieces.h"
#include "MagicSquare.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <memory>
using namespace std;

bool MagicSquare::done()
{
	for (int i = 0; i < int(mDimHor*mDimVer); ++i)
	{
		if (mVector_Game_Board[i].piece_symbol_ == " ")
		{
			return false;
		}
	}
	set<int> sums;

	for (int ver = 0; ver < int(mDimVer); ++ver)
	{
		int sum = 0;
		for (int hor = 0; hor < int(mDimHor); ++hor)
		{
			int temp;
			istringstream iss(mVector_Game_Board[hor + mDimVer*ver].piece_symbol_);
			iss >> temp;
			sum = sum + temp;
		}

		sums.insert(sum);
	}

	for (int hor = 0; hor < int(mDimHor); ++hor)
	{
		int sum = 0;
		for (int ver = 0; ver < int(mDimVer); ++ver)
		{
			int temp;
			istringstream iss(mVector_Game_Board[hor + mDimVer*ver].piece_symbol_);
			iss >> temp;
			sum = sum + temp;
		}

		sums.insert(sum);
	}


	int sum = 0;
	for (int i = 0; i < int(mDimHor); ++i) {
		int temp;
		istringstream iss(mVector_Game_Board[i * int(mDimHor + 1)].piece_symbol_);
		iss >> temp;
		sum = sum + temp;
	}
	sums.insert(sum);
	sum = 0;
	for (int i = 1; i < int(mDimHor + 1); ++i) {
		int temp;
		istringstream iss(mVector_Game_Board[i * int(mDimHor - 1)].piece_symbol_);
		iss >> temp;
		sum = sum + temp;
	}
	sums.insert(sum);

	if (sums.size() == 1) {
		return true;
	}
	return false;
}

int MagicSquare::prompt(int & number)
{
	string str;
	cout << "Which piece?" << endl;
	//repeatedly prompts the user to enter valid piece
	while (true) {
		getline(cin, str);
		//the user quit
		if (str == "quit") {
			cout << "You have ended the game." << endl;
			return enum_quit;
		}
		//checks if only one number has been entered
		istringstream iss(str);
		if (iss >> number) {
			//checks if the piece is yet played
			/*change true to a function that tries to
			look for that number in the set, if
			you do find it in the set, the input value
			is a vaid piece, so exits out of the method.
			if the input is not in the set, that piece is
			already played, so prompts the user to enter
			another number that hasn't been played
			I created a seperate method for it*/
			if (isInTheSet(number)) {
				return valid_piece;
			}
			else {
				cout << "That piece is unavailable" << endl;
			}
		}
		//no number has been entered
		else {
			cout << "Enter a valid piece" << endl;
		}
	}

}

bool MagicSquare::stalemate()
{
	for (int i = 0; i < int(mDimHor*mDimVer); ++i)
	{
		if (mVector_Game_Board[i].piece_symbol_ == " ")
		{
			return false;
		}
	}
	set<int> sums2;

	for (int ver = 0; ver < int(mDimVer); ++ver)
	{
		int sum = 0;
		for (int hor = 0; hor < int(mDimHor); ++hor)
		{
			int temp;
			istringstream iss(mVector_Game_Board[hor + mDimVer*ver].piece_symbol_);
			iss >> temp;
			sum = sum + temp;
		}

		sums2.insert(sum);
	}

	for (int hor = 0; hor < int(mDimHor); ++hor)
	{
		int sum = 0;
		for (int ver = 0; ver < int(mDimVer); ++ver)
		{
			int temp;
			istringstream iss(mVector_Game_Board[hor + mDimVer*ver].piece_symbol_);
			iss >> temp;
			sum = sum + temp;
		}

		sums2.insert(sum);
	}

	int sum = 0;
	for (int i = 0; i < int(mDimHor); ++i) {
		int temp;
		istringstream iss(mVector_Game_Board[i * int(mDimHor + 1)].piece_symbol_);
		iss >> temp;
		sum = sum + temp;
	}
	sums2.insert(sum);
	sum = 0;
	for (int i = 1; i < int(mDimHor + 1); ++i) {
		int temp;
		istringstream iss(mVector_Game_Board[i * int(mDimHor - 1)].piece_symbol_);
		iss >> temp;
		sum = sum + temp;
	}
	sums2.insert(sum);

	if (sums2.size() == 1) {
		return false;
	}
	return true;
}

int MagicSquare::turn()
{
		unsigned int posit_x, posit_y, vector_index;
		int numPiece;
		//prompts the user to enter a position to place a piece
		
		bool extract_x_and_y_success = false;
		
		while (extract_x_and_y_success != true )
		{
			cout << "Where do you want to place a piece?" << endl;
			int prompt_output = GameClass::prompt(posit_x, posit_y);

			if (prompt_output == enum_quit)
			{
				return enum_quit;
			}

			
			if (mVector_Game_Board[posit_x + mDimVer*posit_y].piece_symbol_ == " ")
			{
				extract_x_and_y_success = true;
			}

			else
			{
				cout << " Invalid spot" << endl;
			}
		}
		
		//converts coordinates into vector index
		vector_index = mDimVer*posit_y + posit_x;
		//prompts the user which piece to place
		prompt(numPiece);
		//puts the piece on the desired position
		mVector_Game_Board[vector_index] = game_piece(no_color, to_string(numPiece), to_string(numPiece));
		numPieces.erase(numPiece);
		print();
		cout << endl;
		return success;
	
}

void MagicSquare::print()
{
	cout << *this << endl;
}

void MagicSquare::setup_board()
{
	for (unsigned int ver = 0; ver < mDimVer; ++ver)
	{
		for (unsigned int hor = 0; hor < mDimHor; ++hor)
		{
			mVector_Game_Board[mDimVer * ver + hor] = game_piece(no_color, " ", " ");
		}

	}
	MagicSquare::starting_piece = GameClass::starting_piece;
	for (int i = starting_piece; i < starting_piece + int(mDimHor*mDimVer); ++i)
	{
		//string to_insert = to_string(i);
		numPieces.insert(i);
	}
}

bool MagicSquare::isInTheSet(int &number) {
	bool inTheSet = false;
	std::set<int>::iterator it = numPieces.begin();
	while (!(it == numPieces.end())) {
		if ((*it) == number) {

			inTheSet = true;
		}
		++it;
	}
	return inTheSet;
}

ostream & operator<<(ostream & out, const MagicSquare & rGame)
{
	unsigned int dim = rGame.mDimHor;//get board dimensions before this
	unsigned int longest_str_len = rGame.longest_str_len;

	out << endl;
	for (int i = 0;i < dim*dim; ++i) {
		int current = rGame.mVector_Game_Board[i].piece_symbol_.length();
		if (current > longest_str_len) {
			longest_str_len = current;
		}
	}
	for (int ver = (int)dim - 1; ver >= 0; --ver)
	{
		out << ver << " ";
		for (int hor = 0; hor < int(dim); ++hor)
		{
			out << rGame.mVector_Game_Board[dim * ver + hor].piece_symbol_;
			int str_length = rGame.mVector_Game_Board[dim * ver + hor].piece_symbol_.length();
			string spaces_to_insert = "";
			for (int i = str_length; i <= int(longest_str_len); ++i)
			{
				spaces_to_insert += " ";
			}

			out << spaces_to_insert;

			// a for loop to insert spaces
		}

		out << endl;
	}
	out << endl;
	out << "X ";

	string spaces_to_insert2 = "";
	for (int i = 1; i <= int(longest_str_len);++i)
	{
		spaces_to_insert2 += " ";
	}
	for (int i = 0;i < int(dim);++i) {
		out << i << spaces_to_insert2;
	}
	out << endl;
	out << endl;
	out << "Available pieces: ";

	for (auto i = rGame.numPieces.begin(); i != rGame.numPieces.end(); ++i)
	{
		out << (*i) << spaces_to_insert2;
	}
	out << endl;
	return out;

}


