// NineAlmondsGame.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : nine almonds game source file

#include "stdafx.h"
#include "NineAlmondsGame.h"
#include <iostream>
#include <memory>
#include "MagicSquare.h"
using namespace std;

#define xCenter 2
#define yCenter 2

bool NineAlmondsGame::done()
{
	for (int i = 0; i < int (xCenter + mDimVer*yCenter); ++i)
	{
		if (mVector_Game_Board[i].piece_symbol_ != " ")
		{
			return false;
		}

	}

	for (int i = xCenter + mDimVer*yCenter + 1; i < int(mDimVer*mDimVer); ++i)
	{
		if (mVector_Game_Board[i].piece_symbol_ != " ")
		{
			return false;
		}
		
	}

	if (mVector_Game_Board[xCenter + mDimVer*yCenter].piece_symbol_ != "A")
	{
		return false;
	}

	return true;

}

bool NineAlmondsGame::stalemate()
{
	if (this->done())
	{
		return false;
	}

	for (int ver = mDimVer - 1; ver >= 0; --ver)
	{
		for (int hor = 0; hor < int(mDimVer); ++hor)
		{
			if (mVector_Game_Board[hor + mDimVer*ver].piece_symbol_ == "A")
			{

				auto neighbor_hor_left = hor - 1;
				auto neighbor_hor_same = hor;
				auto neighbor_hor_right = hor + 1;

				auto neighbor_ver_up = ver + 1;
				auto neighbor_ver_same = ver;
				auto neighbor_ver_down = ver - 1;

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_up].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_up].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_up))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_up].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_up + 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_up + 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}

				//this was for top 3, if they exist, now check bottom 3






				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_down))
				{


					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_down].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_down - 1))
						{

							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_same + mDimVer*neighbor_ver_down].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_same, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_same + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}

				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_down))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_down].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_down - 1))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_down - 1)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}
				// now check left and right				

				if (IsValidCoordinates(neighbor_hor_left, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_left + mDimVer*neighbor_ver_same].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_left - 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_left - 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}


				if (IsValidCoordinates(neighbor_hor_right, neighbor_ver_same))
				{
					if (mVector_Game_Board[neighbor_hor_right + mDimVer*neighbor_ver_same].piece_symbol_ == "A")
					{
						if (IsValidCoordinates(neighbor_hor_right + 1, neighbor_ver_same))
						{
							if (mVector_Game_Board[neighbor_hor_right + 1 + mDimVer*(neighbor_ver_same)].piece_symbol_ == " ")
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	


	return true;
}

int NineAlmondsGame::turn()
{
	unsigned int
		coordinate_initial_x, coordinate_initial_y,
		coordinate_final_x, coordinate_final_y,
		coordinate_middle_x, coordinate_middle_y;

	string list_of_moves = " ";
	
	bool extract_x_and_y_success = false;

	int counter = 0;

	int prompt_output;

	while (extract_x_and_y_success != true || counter != 2)
	{
		counter = 0;
		//extract first pair
		cout << "Enter first pair x,y or enter quit " << endl;
		prompt_output = prompt(coordinate_initial_x, coordinate_initial_y);

		if (prompt_output == enum_quit)
		{
			return enum_quit;
		}
		 
		++counter;

		//extract second pair;
		cout << "Enter second pair x,y or enter quit " << endl;
		prompt_output = prompt(coordinate_final_x, coordinate_final_y);

		if (prompt_output == enum_quit)
		{
			return enum_quit;
		}

		++counter;

		bool is_valid_move;
		is_valid_move = IsValidMove(
			coordinate_initial_x, coordinate_initial_y,
			coordinate_final_x, coordinate_final_y);



		if (is_valid_move)
		{

			extract_x_and_y_success = true;
		}

		else 
		{
			cout << " Invalid Move" << endl;
		}
	}
	



	string empty_name = " ";
	string empty_sym = " ";


	// check for quit
	// check validity
	// coordinates now obtained

	bool continue_turn = true;

	list_of_moves =to_string( coordinate_initial_x);
	list_of_moves = list_of_moves + ",";
		list_of_moves = list_of_moves + to_string (coordinate_initial_y);


	while (continue_turn != false)
	{

		coordinate_middle_x =unsigned int(0.50* (coordinate_final_x + coordinate_initial_x));
		coordinate_middle_y = unsigned int(0.50* (coordinate_final_y + coordinate_initial_y));

		mVector_Game_Board[coordinate_middle_y * mDimVer + coordinate_middle_x] 
			 =	game_piece(no_color, empty_name, empty_sym);//remove middle
		 
		mVector_Game_Board[coordinate_final_y * mDimVer + coordinate_final_x]
			 = mVector_Game_Board[coordinate_initial_y * mDimVer + coordinate_initial_x];//move the piece

		mVector_Game_Board[coordinate_initial_y * mDimVer + coordinate_initial_x]
			 = game_piece(no_color, empty_name, empty_sym);//remove initial

		print();
		cout << endl;

		list_of_moves = list_of_moves + " to ";
		list_of_moves = list_of_moves + to_string(coordinate_final_x);
		list_of_moves = list_of_moves + ",";
		list_of_moves = list_of_moves + to_string(coordinate_final_y);

		cout << list_of_moves << endl;

		bool input_is_satisfactory = false;
		string input;
	
		while (!input_is_satisfactory)
		{
			cout << "Do you want to continue turn? Enter Y/y/N/n or quit " << endl;
			 
			cin >> input;

			if (input == "quit")
			{
				return enum_quit;
			}


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
			return success;
		}
		
		//else, continue
		 

		continue_turn = true;

		coordinate_initial_x = coordinate_final_x;
		coordinate_initial_y = coordinate_final_y;


		counter = 0;
		extract_x_and_y_success = false;

		while (extract_x_and_y_success != true || counter != 1)
		{
			counter = 0;


			//extract second pair;
			cout << "Enter second pair " << endl;
			prompt_output = prompt(coordinate_final_x, coordinate_final_y);



			if (prompt_output == enum_quit)
			{
				return enum_quit;
			}

			++counter;

			if (IsValidMove(
				coordinate_initial_x, coordinate_initial_y,
				coordinate_final_x, coordinate_final_y))
			{
				extract_x_and_y_success = true;
			}

			else
			{
				cout << "invalid move ";
			}
		}




	}

	return (int(unknown_error));
}

void NineAlmondsGame::print()
{
	cout << *this << endl;
}

void NineAlmondsGame::setup_board()
{


	for (int ver = mDimVer - 2; ver >= int(mDimVer - 4); --ver)
	{
		for (int hor = mDimHor - 4; hor < int(mDimHor - 1); ++hor)
		{
			mVector_Game_Board[mDimVer * ver + hor] = game_piece(brown, "Almond", "A");
		}

	}

}

 bool NineAlmondsGame::IsValidMove(
	 unsigned int coordinate_initial_x, unsigned int coordinate_initial_y, 
	 unsigned int coordinate_final_x, unsigned int coordinate_final_y)
 {

	 if (coordinate_initial_x > mDimVer - 1 || coordinate_initial_y > mDimVer - 1||
		 coordinate_final_x > mDimVer - 1 || coordinate_final_y > mDimVer - 1)
	 {
		 return false;
	 }

	 if (coordinate_initial_x < 0 || coordinate_initial_y < 0 || coordinate_final_x < 0 || coordinate_final_y < 0)
	 {
		 return false;
	 }



	 if (abs(int(coordinate_initial_y) - int(coordinate_final_y)) != 2 &&
		 abs(int(coordinate_initial_y) - int(coordinate_final_y)) != 0)
	 {


		 return false;
	 }

	 if (abs(int(coordinate_initial_x) - int(coordinate_final_x)) != 2 &&
		 abs(int(coordinate_initial_x) - int(coordinate_final_x)) != 0)
	 {

		 return false;
	 }



	 if (abs(int(coordinate_initial_y) - int(coordinate_final_y)) != 2 &&
		 abs(int(coordinate_initial_y) - int(coordinate_final_y)) == 0)
	 {
		 if (abs(int(coordinate_initial_x) - int(coordinate_final_x)) != 2)
		 {
			 return false;
		 }
	 }

	 if (abs(int(coordinate_initial_x) - int(coordinate_final_x)) != 2 &&
		 abs(int(coordinate_initial_x) - int(coordinate_final_x)) == 0)
	 {
		 if (abs(int(coordinate_initial_y) - int(coordinate_final_y)) != 2)
		 {
			 return false;
		 }
	 }



	 if (mVector_Game_Board[mDimVer * coordinate_final_y + coordinate_final_x].piece_symbol_ != " ")
	 {
		 return false;
	 }
	 
	unsigned int coordinate_middle_x = unsigned int(0.50*(coordinate_final_x + coordinate_initial_x));
	unsigned int coordinate_middle_y = unsigned int(0.50*(coordinate_final_y + coordinate_initial_y));
	 
	 
	 if (mVector_Game_Board[mDimVer * coordinate_initial_y + coordinate_initial_x].piece_symbol_ == " ")
	 {
		 return false;
	 }
	 
	 if (mVector_Game_Board[mDimVer * coordinate_final_y + coordinate_final_x].piece_symbol_ != " ")
	 {
		 return false;
	 }

	 if (mVector_Game_Board[mDimVer * coordinate_middle_y + coordinate_middle_x].piece_symbol_ == " ")
	 {
		 return false;
	 }

	 return true;

 }

ostream & operator<<(ostream & out, const NineAlmondsGame & rGame)
{
	unsigned int dim = rGame.mDimHor;//get board dimesnions before this
	unsigned int longest_str_len = rGame.longest_str_len;
	

	for (int ver = int (dim - 1); ver >= 0; --ver)
	{
		out << ver << " ";
		for (int hor = 0; hor < int(dim); ++hor)
		{
			out << rGame.mVector_Game_Board[dim * ver + hor].piece_symbol_;
			int str_length = rGame.mVector_Game_Board[dim * ver + hor].piece_symbol_.length();
			string spaces_to_insert="";
			for (int i = str_length;  i <= int(longest_str_len); ++i)
			{
				spaces_to_insert += " ";
			}

			out << spaces_to_insert;

			// add a for loop to insert spaces
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

