#include <stdio.h>

int main(int argc, char *argv[]) {
	char phone[30];
	int i = 0;
	
	printf("Enter phone number:");
	gets(phone);
	printf("\n");
	
	while (i <= 30){
		if (phone[i] >= 'A' && phone[i] <= 'C'){
			phone[i] = '2';                                                                                                    
		}
		else if (phone[i] >= 'D' && phone[i] <= 'F'){
			phone[i] = '3';                                                                                                    
		}
		else if (phone[i] >= 'G' && phone[i] <= 'I'){
			phone[i] = '4';                                                                                                    
		}
		else if (phone[i] >= 'J' && phone[i] <= 'L'){
			phone[i] = '5';                                                                                                    
		}
		else if (phone[i] >= 'M' && phone[i] <= 'O'){
			phone[i] = '6';                                                                                                    
		}
		else if (phone[i] >= 'P' && phone[i] <= 'S'){
			phone[i] = '7';                                                                                                    
		}
		else if (phone[i] >= 'T' && phone[i] <= 'V'){
			phone[i] = '8';                                                                                                    
		}
		else if (phone[i] >= 'W' && phone[i] <= 'Y'){
			phone[i] = '9';                                                                                                    
		}
		printf("%c", phone[i]);
		i++;
	}
}