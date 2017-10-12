// game piece.h
// Annie Lee : annie.lee@wustl.edu
// (Lab 2) header of the game piece source

#pragma once
#ifndef ALMONDGAME_H
#define ALMONDGAME_H
#include "Lab 2.h"
#include "almond game.h"
#include "game piece.h"
#include <string>
#include <iostream>
using namespace std;

class NineAlmondsGame {
	friend ostream & operator << (ostream &out, const NineAlmondsGame& game);

public:
	NineAlmondsGame();							  //default contructor
	bool done();								  //checks if the game is done
	bool stalemate();							  //checks for a stalemate
	bool noAlmondMoves(unsigned int& startIndex); //checks if there are possible moves
	int prompt(unsigned int &x, unsigned int &y); //prompts the user to enter coordinates
	int turn();									  //one turn for a single almond
	int play();									  //plays the game until it is over
	int valid(unsigned int & startIndex, 
		unsigned int & finishIndex);			  //checks if a move is valid

private:
	vector<game_piece> almonds;					  //vector that holds the game pieces
	game_piece almond1;							  //9 almond game piece:
	game_piece almond2;
	game_piece almond3;
	game_piece almond4;
	game_piece almond5;
	game_piece almond6;
	game_piece almond7;
	game_piece almond8;
	game_piece almond9;
	unsigned const int hor;
	unsigned const int ver;
};
ostream & operator << (ostream &out, const NineAlmondsGame& game);



#endif
