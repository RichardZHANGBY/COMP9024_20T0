#include <stdio.h>

typedef struct{
	int day;
	int month;
	int year;
	int minute;
	int hour;
} date;


typedef struct{
	int transaction_number;
	date date_time;
	enum {T,B} mode;
	char details[66];
	int journey_number;
	bool fare_applied;
	float fare;
	float discount;
} information_ride;

int main(int argc, char *argv[]) {
	
}