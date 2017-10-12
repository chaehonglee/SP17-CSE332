// common.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 4) Simgle-Player and Multi-Player Board Games
// common usage source file

#include "stdafx.h"
#include "common.h"
#include <iostream>

using namespace std;

int usage(string program_name, result_codes error)
{
	cout << "usage: " << program_name << " " << "<NineAlmonds> or <MagicSquare> or <Reversi>" << endl
		<< "purpose: plays game of Nine Almonds Magic Squares or reversi " << endl
		<< " error code " << error << endl;
	return int(error);

}
