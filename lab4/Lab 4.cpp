// Lab 4.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// main source file

#include "stdafx.h"
#include "common.h"
#include "GameClass.h"
using namespace std;


int main(int argc, char * argv[])
{
	string program_name = argv[prog_name];
	try {
		
		GameClass::create_game(argc, argv);
		auto pgame = GameClass::instance();
		auto val = pgame->play();
		return val;
	}
	catch (result_codes err) {
		return usage(program_name, err);
	}
}