// Reversi.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// reversi source file

#include "stdafx.h"
#include "Reversi.h"
#include "GameClass.h"
#include <iostream>
#include <sstream>
using namespace std;

ostream & operator<<(ostream & out, const Reversi & rGame)
{
	unsigned int dim = rGame.mDimHor;//get board dimesnions before this
	unsigned int longest_str_len = rGame.longest_str_len;

	for (int ver = int(dim - 1); ver >= 0; --ver)
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
		}
		out << endl;
	}
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
	return out;
}

void Reversi::setup_board()
{
	//if a game was saved, call the usernames that were saved
	if (PlayerNames != "") {
		istringstream temp(PlayerNames);
		temp >> user1 >> user2;
	}
	//if was not saved, prompts users to enter new usernames
	else {
		//saves the username
		cout << "first username : ";
		cin >> user1;
		cout << "second username : ";
		cin >> user2;
		PlayerNames = user1 + " " + user2;
	}
	
	//***neccessary*** call's the saved information
	for (int ver = 0; ver < mDimVer; ++ver) {
		for (int hor = 0; hor < mDimHor; ++hor) {
			mVector_Game_Board[mDimVer * ver + hor] = GameClass::mVector_Game_Board[mDimVer * ver + hor];
		}
	}
}

void Reversi::print()
{
	cout << *this << endl;
}

int Reversi::turn()
{
	userTurn = num_turns_played;
	unsigned int posit_x, posit_y, vector_index;
	bool extract_x_and_y_success = false;

	//prompts the user until correct coordinates are entered
	while (extract_x_and_y_success != true) {
		//User1's turn :
		if (userTurn % 2 == 0) {
			if (AreValidMovesRemainingX() == false) {
				++userTurn;
				return success;
			}
			cout << user1 << ", where do you want to place a piece?" << endl;
		}

		//User2's turn :
		else {
			if (AreValidMovesRemainingO() == false) {
				++userTurn;
				return success;
			}
			cout << user2 << ", where do you want to place a piece?" << endl;
		}

		int prompt_output = GameClass::prompt(posit_x, posit_y);
		if (prompt_output == enum_quit) {
			saveGame();
			return enum_quit;
		}
		//User1's turn : 
		if (userTurn % 2 == 0) {
			if (mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ == " ") {
				int neighbor_hor_left = posit_x - 1;
				int neighbor_hor_same = posit_x;
				int neighbor_hor_right = posit_x + 1;

				int neighbor_ver_up = posit_y + 1;
				int neighbor_ver_same = posit_y;
				int neighbor_ver_down = posit_y - 1;

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				//this was for top 3, if they exist, now check bottom 3
				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}
				// now check left and right 
				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == "X")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "X";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ = "X";
								++userTurn;
								break;
							}
						}
					}
				}
			}
		}

		//User2's turn :
		else {
			if (mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ == " ") {
				int neighbor_hor_left = posit_x - 1;
				int neighbor_hor_same = posit_x;
				int neighbor_hor_right = posit_x + 1;

				int neighbor_ver_up = posit_y + 1;
				int neighbor_ver_same = posit_y;
				int neighbor_ver_down = posit_y - 1;

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				//this was for top 3, if they exist, now check bottom 3
				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}
				// now check left and right 
				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == "O")
							{
								mVector_Game_Board[posit_x + mDimHor*posit_y].piece_symbol_ = "O";
								mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ = "O";
								++userTurn;
								break;
							}
						}
					}
				}
			}
		}
		cout << "That is not a valid move." << endl;
	}
	print();
	cout << endl;
	return success;
}

bool Reversi::AreValidMovesRemainingX()
{
	for (int ver = int(mDimVer - 1); ver >= 0; --ver)
	{
		for (int hor = 0; hor < int(mDimVer); ++hor)
		{
			if (mVector_Game_Board[hor + mDimVer*ver].piece_symbol_ == "X")
			{

				auto neighbor_hor_left = hor - 1;
				auto neighbor_hor_same = hor;
				auto neighbor_hor_right = hor + 1;

				auto neighbor_ver_up = ver + 1;
				auto neighbor_ver_same = ver;
				auto neighbor_ver_down = ver - 1;

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				//this was for top 3, if they exist, now check bottom 3

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}
				// now check left and right 

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}


				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ == "O")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}
			}
		}
	}



	return false;
}

bool Reversi::AreValidMovesRemainingO()
{
	for (int ver = int(mDimVer - 1); ver >= 0; --ver)
	{
		for (int hor = 0; hor < int(mDimVer); ++hor)
		{
			if (mVector_Game_Board[hor + mDimVer*ver].piece_symbol_ == "O")
			{
				auto neighbor_hor_left = hor - 1;
				auto neighbor_hor_same = hor;
				auto neighbor_hor_right = hor + 1;

				auto neighbor_ver_up = ver + 1;
				auto neighbor_ver_same = ver;
				auto neighbor_ver_down = ver - 1;

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				//this was for top 3, if they exist, now check bottom 3

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}
				// now check left and right 

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}


				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ == "X")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Reversi::done()
{
	if (this->AreValidMovesRemainingX() == false && this->AreValidMovesRemainingO() == false)
	{
		int X_counter = 0;
		int O_counter = 0;

		for (int i = 0; i < mDimHor*mDimVer; ++i)
		{
			if (mVector_Game_Board[i].piece_symbol_ == "X")
			{
				++X_counter;
			}

			if (mVector_Game_Board[i].piece_symbol_ == "O")
			{
				++O_counter;
			}
		}

		if (X_counter != O_counter)
		{
			if (X_counter > O_counter) {
				cout << user1 << " won." << endl;
			}
			else if (X_counter < O_counter) {
				cout << user2 << " won." << endl;
			}
			else {
				cout << "tie." << endl;
			}
			return true;
		}
	}
	return false;
}

bool Reversi::stalemate()
{
	if (this->AreValidMovesRemainingX() == false && this->AreValidMovesRemainingO() == false)
	{
		int X_counter = 0;
		int O_counter = 0;

		for (int i = 0; i < mDimHor*mDimVer; ++i)
		{
			if (mVector_Game_Board[i].piece_symbol_ == "X")
			{
				++X_counter;
			}

			if (mVector_Game_Board[i].piece_symbol_ == "O")
			{
				++O_counter;
			}
		}

		if (X_counter == O_counter)
		{
			return true;
		}
	}

	return false;
}