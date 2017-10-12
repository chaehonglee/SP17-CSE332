// game piece.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) header of the game piece source

#include "stdafx.h"
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

//default constructor of the game
NineAlmondsGame::NineAlmondsGame()
	: hor(5), ver(5),
	almond1(brown, "almond 1", "A"),
	almond2(brown, "almond 2", "A"),
	almond3(brown, "almond 3", "A"),
	almond4(brown, "almond 4", "A"),
	almond5(brown, "almond 5", "A"),
	almond6(brown, "almond 6", "A"),
	almond7(brown, "almond 7", "A"),
	almond8(brown, "almond 8", "A"),
	almond9(brown, "almond 9", "A")
{
	//pushes back empty piece into the private vector
	game_piece defaultpiece(no_color, "empty", " ");
	unsigned int board_size = ver*hor;
	for (unsigned int i = 0; i < board_size; ++i) {
		almonds.push_back(defaultpiece);
	}
	//overwrties the nine pieces in the vector
	almonds[6] = almond1;
	almonds[7] = almond2;
	almonds[8] = almond3;
	almonds[11] = almond4;
	almonds[12] = almond5;
	almonds[13] = almond6;
	almonds[16] = almond7;
	almonds[17] = almond8;
	almonds[18] = almond9;
}

//method to check if the game was successfully finished
bool NineAlmondsGame::done() {
	bool isdone = true;
	//goes through the game piece vector and see if exactly one piece 
	//is on the center of the board
	for (unsigned int i = 0; i < almonds.size(); ++i) {
		if (i <= 11 || i >= 13) {
			if (almonds[i].color_ != no_color) {
				isdone = false;
			}
		}
		else if (i == 12) {
			if (almonds[i].color_ != brown) {
				isdone = false;
			}
		}
	}
	return isdone;
}

//method to check if there is anymore valid move
bool NineAlmondsGame::stalemate() {
	bool isStalemate = true;
	//goes through all the possible moves and see if there are any valid moves
	for (unsigned int start = 0; start < almonds.size(); ++start) {
		for (unsigned int finish = 0; finish < almonds.size(); ++finish) {
			if (valid(start, finish) == isvalid) {
				isStalemate = false;
			}
		}
	}
	return isStalemate;
}

//checks to see if an almond has any possible moves to be made
bool NineAlmondsGame::noAlmondMoves(unsigned int& startIndex) {
	bool nomoves = true;
	for (unsigned int i = 0; i < almonds.size(); ++i) {
		if (valid(startIndex, i) == isvalid) {
			nomoves = false;
		}
	}
	return nomoves;
}

//method to prompt the user to enter a next move
int NineAlmondsGame::prompt(unsigned int &x, unsigned int&y) {
	string str;
	cout << "Enter the coordinates (x,y) or quit game (quit) :";
	//repeatedly prompts the user to enter valid coordinates
	while (true)
	{
		getline(cin, str);
		//checks if the user wants to end game
		if (str == "quit")
		{
			cout << "You have ended the game." << endl;
			return user_quit_game;
		}
		
		//changes all the commas into spaces
		for (unsigned int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ',') {
				str[i] = ' ';
			}
		}
		istringstream iss(str);
		if ((iss >> x >> y))
		{
			//checks if the coordinates are within the range
			if (((x >= 0) && (x < hor)) && ((y >= 0) && (y < ver)))
			{
				return valid_coordinates;
			}
			else
			{
				cout << "Enter a valid coordinate (x,y) within the range : ";
			}
		}
		else
		{
			cout << "Enter a valid coordinate of the form (x,y) : ";
		}
	}
}

//one turn of a game with a single almond
int NineAlmondsGame::turn() {

	//instance variables------------------------------------------
	bool continueTurn = true;
	bool yesno = false;
	ostringstream validMoves;
	unsigned int start_x;
	unsigned int start_y;
	unsigned int finish_x;
	unsigned int finish_y;
	game_piece defaultpiece(no_color, "empty", " ");
	//------------------------------------------------------------


	//prompts the user to enter a starting piece and an ending spot
	cout << "Which almond should move? " << endl;
	if (prompt(start_x, start_y) == user_quit_game) {
		return user_quit_game;
	}
	//converts coordinates into vector index
	unsigned int startIndex = hor*(hor - start_y - 1) + start_x;
	//checks if there are possible moves left with this almond
	if(noAlmondMoves(startIndex)){
		cout << "There are no possible moves with this almond. " << endl;
		return no_possible_moves;
	}

	cout << "Where should it go? " << endl;
	if (prompt(finish_x, finish_y) == user_quit_game) {
		return user_quit_game;
	}
	//converts coordinates into vector index
	unsigned int finishIndex = hor*(hor - finish_y - 1) + finish_x;
	unsigned int middleIndex = (startIndex + finishIndex) / 2;
	validMoves << start_x << "," << start_y;
	while (continueTurn)
	{
		//prompts the user to input a valid move until does
		while (!(valid(startIndex, finishIndex) == isvalid))
		{
			cout << "That is not a valid move." << endl;
			if (prompt(finish_x, finish_y) == user_quit_game)
			{
				return user_quit_game;
			}
			//converts coordinates into vector index
			finishIndex = hor*(hor - finish_y - 1) + finish_x;
			middleIndex = (startIndex + finishIndex) / 2;
		}
		//if the move is valid, move the almond, remove the jumped over almond
		almonds[finishIndex] = almonds[startIndex];
		almonds[startIndex] = defaultpiece;
		almonds[middleIndex] = defaultpiece;
		//change the starting index to where it just landed
		startIndex = finishIndex;
		validMoves << " to " << finish_x << "," << finish_y;
		cout << *this << endl;
		cout << validMoves.str() << endl;
		cout << endl;
		while (!yesno || stalemate())
		{
			if (done()) {
				return game_over;
			}
			cout << "Continue this turn (YyNn)? ";
			string str;
			getline(cin, str);
			//if the user chooses to stop the turn, end the turn
			if ((str == "n") || (str == "N"))
			{
				//checks if there are possible moves left with this almond
				if (noAlmondMoves(startIndex)) {
					cout << "There are no possible moves with this almond. " << endl;
					return no_possible_moves;
				}
				continueTurn = false;
				yesno = true;
			}
			//if the user chooses to continue, allow to enter the next move
			else if ((str == "y") || (str == "Y"))
			{
				//checks if there are possible moves left with this almond
				if (noAlmondMoves(startIndex)) {
					cout << "There are no possible moves with this almond. " << endl;
					return no_possible_moves;
				}

				cout << "Where should it go next? " << endl;
				if (prompt(finish_x, finish_y) == user_quit_game)
				{
					return user_quit_game;
				}
				yesno = true;
				//converts coordinates into vector index
				finishIndex = hor*(hor - finish_y - 1) + finish_x;
				middleIndex = (startIndex + finishIndex) / 2;
			}
		}
		yesno = false;
	}
	return success;
}

//play game until it is done or get a stalemate
int NineAlmondsGame::play() {
	unsigned int count = 0;
	while (!done() && !stalemate()) {
		++count;
		if (turn() == user_quit_game) {
			cout << "The game took " << count << " turns." << endl;
			return user_quit_game;
		}
	}
	if (done()) {
		cout << "You took " << count << " turns to complete the game." << endl;
		return game_over;
	}
	else if (stalemate()) {
		cout << "Stalemate. There are no more available moves." << endl;
			cout << "The game took " <<count << " turns." << endl;
		return isstalemate;
	}
	return success;
}

//checks if the move is valid
int NineAlmondsGame::valid(unsigned int & startIndex, unsigned int & finishIndex) {
	unsigned int middleIndex = (startIndex + finishIndex) / 2;
	unsigned int start_x = startIndex % hor;
	unsigned int start_y = startIndex / hor;
	unsigned int finish_x = finishIndex % hor;
	unsigned int finish_y = finishIndex / hor;
	//checks if starting index and finish index are different
	if (startIndex != finishIndex)
	{
		//checks if the starting index has an almond
		if (almonds[startIndex].color_ == brown)
		{
			//checks if the finish index is two away from the start
			if ((finish_x == start_x - 2) && (finish_y == start_y + 2)||  //upper left corner
				(finish_x == start_x) && (finish_y == start_y + 2) ||	  //directly above
				(finish_x == start_x + 2) && (finish_y == start_y + 2)||  //upper right corner
				(finish_x == start_x - 2) && (finish_y == start_y) ||	  //direct left
				(finish_x == start_x + 2) && (finish_y == start_y) ||	  //direct right
				(finish_x == start_x - 2) && (finish_y == start_y - 2)||  //lower left corner
				(finish_x == start_x) && (finish_y == start_y - 2) ||	  //direct below
				(finish_x == start_x + 2) && (finish_y == start_y - 2))   //lower right corner
			{
				//checks if the finish index is empty
				if (almonds[finishIndex].color_ == no_color)
				{
					//checks if the middle index has an almond
					if (almonds[middleIndex].color_ == brown)
					{
						return isvalid;
					}
					else { return no_middle_almond; }
				}
				else { return finishIndex_occupied; }
			}
			else { return not_two_away; }
		}
		else { return startIndex_without_almond; }
	}
	else { return startIndex_finishIndex_same; }
}

//<<operator for the game
ostream & operator << (ostream &out, const NineAlmondsGame& game) {
	unsigned int count = 0;
	unsigned int row = 0;
	while (count < game.hor*game.ver) {
		out << (game.hor - row - 1);
		for (unsigned int j = 0; j <= game.hor - 1; ++j)
		{
			out << " " << game.almonds[count].display_;
			++count;
		}
		++row;
		out << endl;
	}
	out << "X 0 1 2 3 4" << endl;
	return out;
}
