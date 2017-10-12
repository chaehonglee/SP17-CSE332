========================================================================
    CONSOLE APPLICATION : Lab 1 Project Overview
========================================================================

Coded by Annie Lee : annie.lee@wustl.edu

/////////////////////////////////////////////////////////////////////////////
This program reads a text file and converts the information into
game pieces that has color, name, display and location
and prints out the game board.

Files included:

1. Lab 1.cpp
	This code includes the main function of the program
	functions include:
	  main : runs the program
	  convetLower : this function converts a string into all lowercase
	  usagemsg: prints out a guide to the user
	  
2. lab1header.h
	This is the header file for the main source

3. game_pieces.cpp
	This code incdlues a function to make a game piece and covert 
	a enum of a color into string and vice versa.

4. game_pieces.h
	This is the header file of the game piece source file
	It includes a struct for a game piece

5. game_board.cpp
	This code includes :
	  dimensions : reads the dimensions of the board
	  read_pieces : reads lines from the file and converts the
	    information into a game piece
	  print_borad : prints out the board

6. game_board.h
	This is the header file for the game_board source file

/////////////////////////////////////////////////////////////////////////////
Errors I ran into:

1. When I was extracting dimensions from a text file, I also included
calling on that function in the if statement. This resulted in deleting
a line that contains information about a game piece so the first game piece
was not registering. I fixed it by not having duplicate function method called.

2. This is trivial, but I didn't include using namespaces in the header files.
It called an error.

3. read_gamepiece function was doing its job, it was storing each value but
when I tried to print out the board, nothing was printed. It turns out I was
not using a reference to vector<game_piece>. So in the function, it was creating
a new vector of game pieces but the information was never trasfered to the 
main function

/////////////////////////////////////////////////////////////////////////////
Test cases:

1. no dimensions

---------txt-----------
s
black checker X 8 7
red checker O 5 5
-----------------------

this returns: this file contains no dimensions

2. two arguments/ no arguments

"Lab 1.exe" chess.txt checkers.txt
this returns: enter only one file name

"Lab 1.exe" dog.txt
this returns: the file does not exist

3. no color/ invalid color

---------txt-----------
10 10 
BLACK checker X 8 7
yellow checker X 6 6
red checker O 5 5
-----------------------

this just skips the yellow piece and only prints out a valid piece

4. no valid game piece

---------txt-----------
10 10 
s d f s
s d f s
-----------------------

just prints out an empty board of size 10*10

5.out of range

---------txt-----------
10 10
black checker X 11 12
red checker O 5 5
-----------------------

since the black checker is out of range, skips over that line.














