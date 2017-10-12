========================================================================
    CONSOLE APPLICATION : Lab 2 Project Overview
========================================================================
Coded by Annie Lee : annie.lee@wustl.edu

/////////////////////////////////////////////////////////////////////////////
This is a program that play nine almonds game. A user enters which almond
to start with and enters where it should land. Remove eight of the almonds 
and leave the ninth in the central square. Make the removals by jumping 
one almond over another to the vacant square beyond and taking off the 
one jumped over. You can jump in any direction, and not diagonally only. 

Files included:

1. Lab 2.cpp
	This is the source file that contains the main function of the 
	program. This source file contains the uage message function
	that prints out a helpful guide for the user and a main function
	which plays the game.

2. Lab 2.h
	This is the header file of the main source file.

3. almond game.cpp
	This is the source file that contains primary functions fo
	playing the game. This file contains several functions:
	NineAlmondsGame : This is the default constructor of the game.
		initializes the almond game pieces and pushes back
		the game pieces in the main almond vector. Also sets
		up the default game board.
	done(): this is a method that determine whether the game has
		been successfully played.
	stalemate(): this method determines whether if there are any
		more valid moves left.
	noAlmondMoves(): this method checks if the passed almond has
		any possible moves. returns false if the almond doesn't
		have any valid moves.
	prompt(): this method prompts the user to enter a coordinate (x,y)
		re-prompts if the format or the range of a coordinate
		is invalid.
	turn(): this method asks the user to input two coordinates, 
		the starting and the destination coordinates and if 
		they are valid, moves the almond to the destination.
		allows the user to keep using the same almond. If an
		almond doesn't have any possible moves, quits the method
		by returning "no_possible_moves". The user can also quit
		game without entering coordinates. Also prints out past
		moves.
	play(): this method repeatedly calls on the turn method until
		the game is done (done()) or stalemate (stalemate())	
		have been reached. If the user quits the game during a 	
		play, the game is immediately ended.
	valid():this method checks if the move, from a starting point
		and to the ending point, is valid. A move is valid if
		the starting point has an almond, the finishing point
		is empty and two away, and there is an almond in the 
		middle. the method first checks if the staring point
		and the finishing point are different.
	operator << : this operator allows to print out a game board
		using "<<" symbol. It copies string on an output stream.

4. almond game.h
	This is the header file of the almond game source file. It	
	contains the NineAlmondsGame class.

5. game piece.cpp
	This is the source file of a game piece. It contains a function
	that creates a game piece with certain properties.

6. game piece.h
	This is the header file of the game piece source file. It 
	contains a struct of a game piece.

/////////////////////////////////////////////////////////////////////////////
Errors I ran into:

I didn't run into errors while building this program because I was 
debugging after each modifications. I did run into many unsigned mismatch
errors.


/////////////////////////////////////////////////////////////////////////////
Test cases:

1. arguement number error / input arguement error
>>"Lab 2.exe" NineAlmonds yay / "Lab 2.exe" yay
	prompts the user to type in (NineAlmonds) to start the game

2. start index without an almond
>>1,1
	prompts the user to re-type the starting almond

3. start index and finish index the same/ invalid finish index
>>2,2
>>2,2
	tells the user that the move is not a valid move and prompt the
	user to retype in the destination

4. invalid answer to "Continue this turn?"
>> wassup
	just re-prints "Continue this turn?" until the user enter (YyNn)

5. continuing the turn when the almond has no more possible moves
>> Continue this turn (YyNn)? y
	Tells the user that there are no possible moves with the almond,
	and prompts the user to enter a coordinate of a different almond.

6. wrong-ly formatted coordinate/ out of range coordinate
>>2,,,2
	since the program changes the ',' into ' ' this case is successfully
	passed.
>>///4///223
	tells the user to enter a valid coordinate of the form (x,y)
>>6,6
	tells the user to enter a coordinate within the range

7. continuing the turn when the game reached stalemate
>> "Continue this turn (YyNn)?
	tells the user the game is over.
	
	

/////////////////////////////////////////////////////////////////////////////
