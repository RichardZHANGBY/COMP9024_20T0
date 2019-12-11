#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define EMPTY '.'
#define NUMOFROW 10
#define NUMOFCOL 10
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3


int main(int argc, char *argv[]) {
	char maze[NUMOFCOL][NUMOFROW], letter;
	int col, row, i, numOfDirct, randomnum;
	
	srand((unsigned) time(NULL));
	
	for (col = 0; col < NUMOFCOL; col++){
		for (row = 0; row < NUMOFROW; row++){
			maze[col][row] = EMPTY;
		}
	}
	
	col = 0; row = 0;
	for (letter = 'A'; letter <= 'Z'; letter++){
		maze[col][row] = letter;
		numOfDirct = 0;
		bool dirction[4] = {false};
		
		if (col > 0 && maze[col-1][row] == EMPTY){
			numOfDirct++;
			dirction[UP] = true;
		}
		if (col < NUMOFCOL - 1 && maze[col+1][row] == EMPTY){
			numOfDirct++;
			dirction[DOWN] = true;
		}
		if (row < NUMOFROW - 1 && maze[col][row+1] == EMPTY){
			numOfDirct++;
			dirction[RIGHT] = true;
		}
		if (row > 0 && maze[col][row-1] == EMPTY){
			numOfDirct++;
			dirction[LEFT] = true;
		}
		
		if (numOfDirct == 0){
			break;
		}
		
		while(true){
			randomnum = rand() % 4;
			if (dirction[randomnum] == true){
				switch (randomnum) {
					case UP:
						col--;
						break;
					case DOWN:
						col++;
						break;
					case RIGHT:
						row++;
						break;
					case LEFT:
						row--;
						break;
					
				}
				break;
				
			}
		}
		
	}
	
	for (col = 0; col < NUMOFCOL; col++){
		for(row = 0; row < NUMOFROW; row++){
			printf("%2c", maze[col][row]);
		}
		printf("\n");
	}	
	return 0;
}