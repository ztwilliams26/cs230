#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int gameDriver();
  gameDriver();
}
//This is the function that acts as the Game Driver to run the game
int gameDriver(){
  void createBoard(char board[6][7]);
  void printBoard(char board[6][7]);
  char firstMove();
  int makeMove(char board[6][7], int column, char playerPiece);
  int playerMove(char board[6][7]);
  int aiMove(char board[6][7], char aiChar, char playerChar);
  void addToMoves(char* moves,int i,char column);
  char colNumMapper(int column);
  int isGameOver(char board[6][7]);
  void printEndGame(char board[6][7], char* moves, char* winner, int turns);
  char board[6][7];
  char moves[42];
  int turnNum = 0;
  createBoard(board);
  printBoard(board);
  char curMove = firstMove();
  while(!isGameOver(board)){
    //first turn of each round
    if(curMove == 'P'){
      int columnNum = playerMove(board);
      makeMove(board, columnNum, 'X');
      addToMoves(moves, turnNum, colNumMapper(columnNum));
      turnNum++;
      curMove = 'C';
      printBoard(board);
      if(isGameOver(board)){
        printEndGame(board, moves, "Player", turnNum);
      }
    }
    else if(curMove=='C'){
		int columnNum =  aiMove(board, 'X', 'O');  //change to aiMove() once we make it
		makeMove(board, columnNum, 'X');
		addToMoves(moves, turnNum, colNumMapper(columnNum));
		turnNum++;
		printf("CPU Player's Move:\n%c\n",colNumMapper(columnNum));
		curMove = 'P';
		printBoard(board);
	    if(isGameOver(board)){
		    printEndGame(board, moves, "CPU", turnNum);
	    }
    }
    // second turn of each round
    if(curMove == 'C' && !isGameOver(board)){
		int columnNum = aiMove(board, 'O', 'X');  //change to aiMove() once we make it
		makeMove(board, columnNum, 'O');
		addToMoves(moves, turnNum, colNumMapper(columnNum));
		turnNum++;
		printf("CPU Player's Move:\n%c\n",colNumMapper(columnNum));
		curMove = 'P';
	    printBoard(board);
	    if(isGameOver(board)){
		    printEndGame(board, moves, "CPU", turnNum);
	    }
	  }
    else if(curMove =='P' && !isGameOver(board)){
		int columnNum = playerMove(board);
		makeMove(board, columnNum, 'O');
		addToMoves(moves, turnNum, colNumMapper(columnNum));
		turnNum++;
		curMove = 'C';
	    printBoard(board);
	    if(isGameOver(board)){
		    printEndGame(board, moves, "Player", turnNum);
	    }
    }
  }

  return 1;
}

//Creates the board. Takes an empty 2D array with proper dimensions as input
void createBoard(char board[6][7]){
	for(int i =0; i<6;i++){
		for(int j=0;j<7;j++){
			board[i][j] = '.';
		}
	}
}

//print the gamestate
void printBoard(char board[6][7]){
	printf("   A B C D E F G\n");
	for(int i = 0;i<6;i++){
		printf("%2i", 6-i);
		for(int j = 0; j<7;j++){
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
}

//choose who goes first
char firstMove(){
	int stringEq(char* str1, char* str2);
	while(1){
		printf("Input 'P' to go first, input 'C' for the computeer to go first\n");
		char input[20];
		scanf("%s", input);
		if(stringEq(input, "P") ||  stringEq(input, "p")){
			return 'P';
		}
		if(stringEq(input, "C") || stringEq(input, "c")){
			return 'C';
		}
	}
  return 'c';
}

//input to update gamestate (from user or AI) assuming valid move (checked before passed in). Raises the respective player's token into lowest row (checks for availability bottom up)
int makeMove(char board[6][7], int column, char playerPiece){
	for(int i=6; i>=0; i--){
		if(board[i][column] == '.'){
			board[i][column]=playerPiece;
			return 0;
		}	
	}
	return 0;
}

//the player makes a move based on their input. Returns the index of the column they choose
int playerMove(char board[6][7]){
  int isValidMove(char board[6][7],int column);
  int charMapper(char* c);
  int columnNum = -1;
  char input[20];
  while(columnNum < 0){
    printf("What column do you want? (A,B,C,...G)\n");
    scanf("%s", input);
    columnNum = charMapper(input);
    if(columnNum == -1 || !isValidMove(board, columnNum)){
      columnNum = -1;
    }
  }
  return columnNum;
}


//takes in the list of moves, with the index to be added and the column letter and adds the letter to the list
void addToMoves (char* moves,int i,char column){
  moves[i] = column;
}

//checks to see if the move attempting to be made is valid
int isValidMove(char board[6][7],int column){
  if(0<= column && column < 7 && board[0][column] == '.'){
    return 1;
  }
  return 0;
}

//returns 1 if two strings are equal, 0 if they are not
int stringEq(char* str1, char* str2){
  int index = 0;
  while(1){
    if(str1[index]=='\0' && str2[index]=='\0'){
      return 1;
    }
    if(str1[index]=='\0' || str2[index]=='\0'){
      return 0;
    }
    if(str1[index] != str2[index]){
      return 0;
    }
    else{
      index++;
    }
  }
}

//maps the column letter to a number
int charMapper (char* c){
  int stringEq(char* str1, char* str2);
  if(stringEq(c,"A") || stringEq(c,"a")){
    return 0;
  }
  if(stringEq(c,"B") || stringEq(c,"b")){
    return 1;
  }
  if(stringEq(c,"C") || stringEq(c,"c")){
    return 2;
  }
  if(stringEq(c,"D") || stringEq(c,"d")){
    return 3;
  }
  if(stringEq(c,"E") || stringEq(c,"e")){
    return 4;
  }
  if(stringEq(c,"F") || stringEq(c,"f")){
    return 5;
  }
  if(stringEq(c,"G") || stringEq(c,"g")){
    return 6;
  }
  return -1;
}

//changes the column number back into the choresponding move letter
char colNumMapper(int column){
  char columns[7]={'A','B','C','D','E','F','G'};
  return columns[column];
}

//determines if end condition is achieved
int isGameOver(char board[6][7]){
  int noAvailableMoves();
  int rowChecker();
  int columnChecker();
  int diagonalChecker();
  int noMoves = noAvailableMoves(board);
  int checkRows = rowChecker(board);
  int checkColumns = columnChecker(board);
  int checkDiagonals = diagonalChecker(board);
  int isOver = noMoves + checkRows + checkColumns + checkDiagonals;
  if(isOver != 0){
    return 1;
  }
  return 0;
}

//available moves, checks to see if there are any possible moves. Returns 1 if there aren't any
int noAvailableMoves(char board[6][7]){
  int moves=0;
  for(int i = 0; i<7;i++){
    if(board[0][i] == '.'){
      moves++;
    }
  }
  if(moves>0){
	return 0;  
  }
  return 1;
}

//check rows
int rowChecker (char board[6][7]){
  for(int i=0;i<6;i++){
    for(int j =0; j<4;j++){
          if((board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && (board[i][j] == board[i][j+3]) && board[i][j] != '.'){
			return 1;
          }
    }
  }
  return 0;
}

//check columns
int columnChecker (char board[6][7]){
  for(int i=0;i<3;i++){
    for(int j=0;j<7;j++){
      if((board[i][j] == board[i+1][j]) && (board[i][j] == board[i+2][j]) && (board[i][j] == board[i+3][j]) && board[i][j] != '.'){
		return 1;
      }
    }
  }
  return 0;
}

//check diagonals
int diagonalChecker (char board [6][7]){
  //check left
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      if((board[i][j] == board[i+1][j+1]) && (board[i][j] == board[i+2][j+2]) && (board[i][j] == board[i+3][j+3]) && board[i][j] != '.'){
		return 1;
      }
    }
  }
  //check right
  for(int i=0;i<3;i++){
    for(int j=6;j>2;j--){
      if((board[i][j] == board[i+1][j-1]) && (board[i][j] == board[i+2][j-2]) && (board[i][j] == board[i+3][j-3]) && board[i][j] != '.'){
		return 1;
      }
    }
  }
  return 0;
}

//print endgame stats
void printEndGame(char board[6][7], char* moves, char* winner, int turns){
	int noAvailableMoves(char board[6][7]);
  if(noAvailableMoves(board)){
    printf("\n\n------------------\n%s Draws!\n", winner);
  }
  else{
    printf("\n\n------------------\n%s Wins!\n", winner);
  }
	printf("The final game board state is:\n\n");
	printBoard(board);
	printf("\nMoves: [");
	for(int i=0; i<turns-1; i++){
		printf("%c, ", moves[i]);
	}
  	printf("%c]\n", moves[turns-1]);
}

//copies the current board (first parameter) values into a second board (second parameter) passed in
void copyBoard(char board[6][7], char copiedBoard[6][7]){
	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			copiedBoard[i][j] = board[i][j];
		}
	}
}



//the ai makes a move based on whether it will either win them the game or whether an opponent has a chance to win based off of any of those moves (it will only make a move that doesn't have a chance of losing the game)
int aiMove(char board[6][7], char aiChar, char playerChar){
	int isValidMove(char board[6][7],int column);
	void copyBoard(char board[6][7], char copiedBoard[6][7]);
	int makeMove(char board[6][7], int column, char playerPiece);
	int isGameOver(char board[6][7]);
	
	srand(time(0));
	int possibleMoves[7];
	char copiedBoard[6][7];
	for(int i=0; i<7; i++){
		copyBoard(board, copiedBoard);
		makeMove(copiedBoard, i, aiChar);      //currently broken. adding it to top of secondCopiedBoard on i>0??? Most likely mispointing to memory somewhere
		if(i>0){
			makeMove(copiedBoard, i, aiChar);  //temporary fix, no effect on functionality or stability of the program outside of being an extra line of code to be run
		}
		//if any move made by us (the ai) can end the game, we want that move
		if(isGameOver(copiedBoard)){
			return i;
		}
		possibleMoves[i]=1;
		char secondCopiedBoard[6][7];
		//if any move (given a move made by us) made by the opponent (the player) ends the game, we want to avoid our move that could lead to that
		for(int j=0; j<7; j++){
			copyBoard(copiedBoard, secondCopiedBoard);
			makeMove(secondCopiedBoard, j, playerChar);
			if(isGameOver(secondCopiedBoard)){
				possibleMoves[i]=0;
			}
		}
	}

	int noPossibles = 1;
	for(int i=0; i<7; i++){
		if (possibleMoves[i]){
			noPossibles=0;
		}
	}
	while(1){
		int isValidMove();
    int randNum= rand() % 7;
		if(noPossibles && isValidMove(board,randNum)){
			return randNum;
		}
		if(possibleMoves[randNum] && isValidMove(board, randNum)){
			return randNum;
		}
	}
}