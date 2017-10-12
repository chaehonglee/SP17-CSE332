// common.cpp
// Annie Lee : annie.lee@wustl.edu
// Jeremiah Lorentz : j.lorentz@wustl.edu
// Jairaj Mathur : jairaj.mathur@wustl.edu
// (Lab 3) Multiple Games : common usage source file

#include "stdafx.h"
#include "common.h"
#include <iostream>

using namespace std;

int usage(string program_name, result_codes error)
{
	cout << "usage: " << program_name << " " << "<NineAlmonds> or <MagicSquare>" << endl
		<< "purpose: plays game of Nine Almonds or Magic Squares " << endl
		<< " error code " << error << endl;
	return int(error);
	
}
