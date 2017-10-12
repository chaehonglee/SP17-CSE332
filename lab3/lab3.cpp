// lab3.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : main source file

#include "stdafx.h"
#include "common.h"
#include "NineAlmondsGame.h"
#include "GameClass.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	{
		string program_name = argv[prog_name];
		auto pgame = GameClass::create_game(argc, argv);
		if (pgame == nullptr) 
		{
			return usage(program_name, enum_wrong_arg);
		}
		auto val = pgame->play();
		delete pgame;
		return val;
	}
}

