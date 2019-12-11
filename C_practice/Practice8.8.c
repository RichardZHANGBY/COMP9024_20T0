#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);


int main(int argc, char *argv[]) {
	int roll_time = 0, roll_num, point;
	bool continueplay = true;
	srand((unsigned) time(NULL));
	
	
	do{
		while (true){
			roll_num = roll_dice();
			printf("You rolled:%d\n", roll_num);
			roll_time++;
			if (roll_time == 1){
				if (roll_num == 7 || roll_num == 11){
					printf("You Win!\n");
					break;
				}
				if (roll_num == 2 || roll_num == 3 || roll_num == 12){
					printf("You lose!\n");
					break;
				}
				point = roll_num;
				printf("Your point is %d\n", point);
			}
			else if (roll_num == point){
				printf("You Win!\n");
				break;
			}
			else if (roll_num == 7){
				printf("You lose!\n");
				break;
			}
		}
		roll_time = 0;
		point = 0;
		continueplay = play_game();
	}while (continueplay);
}

int roll_dice(void){
	
	return rand() % 12 + 1;
}

bool play_game(void){
	char ch;
	printf("Play again?");
	ch = getchar();
	if (ch == 'y' || ch == 'Y'){
		return true;
	}
	return false;
}