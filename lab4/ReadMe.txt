=======================================================================
    CONSOLE APPLICATION : Lab 4 Project Overview
		CREATED BY	 : Annie Lee (annie.lee@wustl.edu)
				  Jeremiah Lorentz(j.lorentz@wustl.edu)
				  Jairaj Mathur(Jairaj.mathur@wustl.edu)
=======================================================================
This program plays two games: Nine Almonds Game and Magic Square.

Files included:

1. lab4.cpp
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
This code includes :A createGame function, play function, isValidCoordinates function, and prompt for coordinates function For this lab, we created methods called saveGame and openGame. saveGame creates a text file with current Game’s name and stores information of the game’s status. openGame opens the game and checks if there is a saved game from before and restores that game. If there is no game saved, we created a default board and pushed it to our game class vector that contains game pieces.

7. GameClass.h
	This is the header file for the GameClass source file. 
	Contains the GameClass class containing public pure virtual function
	signatures for print, done, stalemate, turn, and setupBoard functions.
	Also contains public virtual function signatures for 
	isValidCoordinates and prompt functions. Contains public createGame and 
play function signature. Contains protected variables for unsigned int 
dimensions, int starting piece, unsigned int longest string length, and 
vector for the gameboard. Contains declaration for saveGame and openGame.
	

8. MagicSquare.cpp
	This code includes:
	Done, prompt for which piece to play, stalemate, turn, print, 
setupBoard, isInTheSet and ostream operator functions
	
9. MagicSquare.h
	This is the header file for MagicSquare source file.
	Contains MagicSquare class containing public virtual function
 signatures for stalemate, turn, print, setupBoard, and done. 
Contains public isInTheSet function signature, int starting piece
initializer, and set of the available game pieces. Also contains private ostream operator signature (friend). To save game and open game properly, we had to add msExisting member variable that contains the delete pieces that are already on the board from numPieces vector.
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
12. Reversi.cpp
	This code includes: 
done() and stalemate() methods to determine when to end the game, turn method to play the game with alternating turns, areValidMovesX/O to determine if there are moves available for each user.
13. Reversi.h
	This is the header file of the Reversi game source file.

/////////////////////////////////////////////////////////////////////////////
Test cases:

Incorrect game listed / no game listed / too many arguments
	(does not fit the MagicSquare extra credit format)

	ex: lab4.exe SuperSmashBros
	This returns the usage message 
     2.    NineAlmonds
	
	ex lab4.exe NineAlmonds (only works with this input)
	This plays the NineAlmonds game; game operates as should
	and outputs an error message when the user messes up a 
	coordinate input, move, or continues turn.  Game correctly
	identifies completed game, stalemate, or when the user quits
	and outputs the outcome with the number of turns played.
     3. MagicSquare
	
	ex lab4.exe MagicSquare
	This plays the MagicSquare game; game operates as should
	and outputs an error message when the user incorrectly inputs 
	coordinates or piece to play and if the piece has been used
or there is a piece in the inputted coordinate. Game correctly 
identifies a completed game, stalemate, or when the user quits 
and outputs the outcome with the number of turns played. 
Game is played with default dimensions (3x3) and pieces (1-9).
     4. Reversi

	Ex lab4.exe Reversi
	This plays the Reversi game. It first prompts the users to enter 
	their usernames. Then alternate turns to place pieces on the 
	board. A user’s turn is skipped if there is no available moves for
	that user. Ends game if there are no possible moves available
	for both users or if the board if completely filled.
    
/////////////////////////////////////////////////////////////////////////////
Errors we ran into:

When I first made the open game method, since I only stored what pieces were on the board, when I tried to open saved game for MagicSquare, the default pieces were printing without reflecting what pieces are already on the board. So I had to create another msExisting vector of ints to store what is already on the board and delete those from numPieces that gets created in set up board.
For saving the usernames, I had to create another string member variable called miscellenious in the gameClass. In save game, if we are saving Reversi, I write an additional line of usernames in the text file. Then when opening the game, I read those line and using istringstream to store the usernames in miscellenious and calls that string in set up board in Reversi Class.
In setting up the board with the information from the previous game, I had to restore the vector of game pieces in each classes from the game base class itself. If I didn’t do this, the board was empty for Reversi.

/////////////////////////////////////////////////////////////////////////////
Copy Control Design Decisions:
In our game class, we create a smart pointer that points to a nullpointer when instantiated, and assign different game classes(nine almonds game, magic square, reversi) in create game function(copy constructor). Play function is called on the smart pointer after a game object is assigned. We didn’t need any copy/move constructor or operators because we create a new instance of each game class object in create game, and using shared_ptr<GameClass> we assign the object to the smart pointer. Also, we didnt need a seperate destructor for each class because the smart pointer takes care of destructing the class object.
