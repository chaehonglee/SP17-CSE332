========================================================================
    CONSOLE APPLICATION : Lab 3 Project Overview
	CREATED BY	: Annie Lee (annie.lee@wustl.edu)
			  Jeremiah Lorentz(j.lorentz@wustl.edu)
			  Jairaj Mathur(Jairaj.mathur@wustl.edu)
========================================================================
This program plays two games: Nine Almonds Game and Magic Square.

Files included:

1. lab3.cpp
	This code includes the main function of the program, which
	runs the program
	  
2. common.cpp
	This is a file that contains the usage function

3. common.h
	This is the header file for the common source containing 
	array index enums, return enums, and usage function signature

4. game_pieces.cpp
	This code includes a function to make a game piece 
5. game_pieces.h
	This is the header file of the game piece source file
	It includes a struct for a game piece and an enum for
	piece color

6. GameClass.cpp
	This code includes :
	A createGame function, play function, isValidCoordinates 
	function, and prompt for coordinates function

7. GameClass.h
	This is the header file for the GameClass source file. 
	Contains the GameClass class containing public pure virtual function
	signatures for print, done, stalemate, turn, and setupBoard functions.
	Also contains public virtual function signatures for 
	isValidCoordinates and prompt functions. Contains public createGame and 
	play function signature. Contains protected variables for unsigned int 
	dimensions, int starting piece, unsigned int longest string length, and 
	vector for the gameboard.
		

8. MagicSquare.cpp
	This code includes:
	Done, prompt for which piece to play, stalemate, turn, print, 
	setupBoard, isInTheSet and ostream operator functions
	
9. MagicSquare.h
	This is the header file for MagicSquare source file.
	Contains MagicSquare class containing public virtual function
	signatures for stalemate, turn, print, setupBoard, and done.
	Contains public isInTheSet function signature, int starting piece
	initializer, and set of the available game pieces. Also contains 
	private ostream operator signature (friend).
10. NineAlmondsGame.cpp
	This code includes:
	Done, stalemate, turn, print, setupBoard, ostream operator, and 
isValidMove functions.
	
11. NineAlmondsGame.h
	This is the header file for NineAlmonds source file.
	Contains NineAlmonds class containing public virtual function
	signatures for stalemate, turn, print, setupBoard, and done.
	Contains public isValidMove function signature and private 
	Ostream operator signature (friend).

/////////////////////////////////////////////////////////////////////////////
Test cases:

Incorrect game listed / no game listed / too many arguments
	(does not fit the MagicSquare extra credit format)

	ex: lab3.exe SuperSmashBros
	This returns the usage message 
     2.    NineAlmonds
	
	ex lab3.exe NineAlmonds (only works with this input)
	This plays the NineAlmonds game; game operates as should
	and outputs an error message when the user messes up a 
	coordinate input, move, or continues turn.  Game correctly
	identifies completed game, stalemate, or when the user quits
	and outputs the outcome with the number of turns played.
     3. MagicSquare
	
	ex lab3.exe MagicSquare
	This plays the MagicSquare game; game operates as should
	and outputs an error message when the user incorrectly inputs 
	coordinates or piece to play and if the piece has been used
	or there is a piece in the inputted coordinate. Game correctly 
	identifies a completed game, stalemate, or when the user quits 
	and outputs the outcome with the number of turns played. 
	Game is played with default dimensions (3x3) and pieces (1-9).
    
/////////////////////////////////////////////////////////////////////////////
EXTRA CREDIT:
We did extra credit

Adjusted createGame method to differentiate which mode to play depending on number of arguments. Ie. when there are only two arguments either play NineAlmondsGame or Square in default mode. When there are three arguments, play MagicSquare with specified board dimension. When there are four arguments, play MagicSquare with specified board dimension and starting piece. After doing so, I added a member variable in MagicSquare class to assign a specific starting piece.

Adjusted the done and stalemate method so that the sum of the values 
in each row,column, and diagonal was not compared to a value but instead 
stored in a set. If the sets size is greater than 1, the done method returns false;
if it equals 1 then the done method returns true (opposite for the stalemate
method).
/////////////////////////////////////////////////////////////////////////////
Test cases:
 MagicSquare (standard)
	
	ex lab3.exe MagicSquare
	This plays the MagicSquare game; game operates as should
	and outputs an error message when the user incorrectly inputs 
	coordinates or piece to play and if the piece has been used
	or there is a piece in the inputted coordinate. Game correctly 
	identifies a completed game, stalemate, or when the user quits 
	and outputs the outcome with the number of turns played. 
	Game is played with default dimensions (3x3) and pieces (1-9).


      2.  MagicSquare with specified dimensions
	
	ex lab3.exe MagicSquare 5
	This plays the MagicSquare game with a 5x5 board; game operates
	as should and outputs an error message when the user incorrectly 
	specifies the board dimensions, piece to play, or coordinate to place
	the piece. Also outputs an error message if the inputted piece has
	already been used or there is a piece in the inputted coordinate.
	Game correctly identifies a completed game, stalemate, or when 
	the user quits, and outputs the outcome with the number of turns played.
	Game is played with default pieces (1-9)
      3.    MagicSquare with specified dimensions and starting piece

	ex lab3.exe MagicSquare 4 3
	This plays the MagicSquare game with 4x4 board and pieces (3-18);
	game operates as should and outputs error message when the user
	Incorrectly specifies the board dimensions (0 or negative), starting piece
	(a), piece to play, or coordinate to place the piece. Also outputs an error 
	message if the inputted piece has already been used or there is a piece 
	in the inputted coordinate. Game correctly identifies a completed game, 
	stalemate, or when the user quits and outputs the outcome with the 
	number of turns played.
/////////////////////////////////////////////////////////////////////////////
WE ARE NOT USING TRY CATCH BECAUSE
After discussion with a TA, we understood that using try catch is expensive 
in regards to memory, so it’s not efficient. Thus having an int return type is better.