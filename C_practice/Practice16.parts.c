#include <stdio.h>

#define NAME_LEN 20
#define MAX_PARTS 100

struct part{
	int number;
	char name[NAME_LEN];
	int on_hand;
} parts[MAX_PARTS];

int current_part = 0;

int insert(void);
int find_part(int part_number);
void search(void);
void update(void);
void print(void);



int main(int argc, char *argv[]) {
	char ch;
	
	for(;;){
		printf("Enter operation code:");
		scanf(" %c", &ch);
		while(getchar() != '\n')
		;
		switch (ch) {
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
				break;
			case 'q':
				return 0;
			default:
				printf("Error code!");
			
		}
		printf("\n");
	}
}

int insert(void){
	int part_number;
	
	if (current_part == MAX_PARTS){
		printf("Parts are full!");
		return 0;
	}
	
	printf("Enter part number:");
	scanf("%d", &part_number);
	
	if (find_part(part_number) > 0){
		printf("This part is already exist!");
		return 0;
	}
	
	parts[current_part].number = part_number;
	
	printf("Enter part name:");
	scanf("%s", parts[current_part].name);
	printf("Enter quantity on hand:");
	scanf("%d", &parts[current_part].on_hand);
	current_part++;
	return 0;
}

int find_part(int part_number){
	for (int i = 0; i < current_part; i++){
			if (parts[i].number == part_number){
				return i;
			}
		}
	return 0;
}

void update(void){
	int part_number, change;
	printf("Enter part number:");
	scanf("%d", &part_number);
	part_number = find_part(part_number);
	printf("Enter change in quantity on hand:");
	scanf("%d", &change);
	parts[part_number].on_hand += change;
}

void search(void){
	int part_number;
	printf("Enter part number:");
	scanf("%d", &part_number);
	part_number = find_part(part_number);
	if (find_part(part_number) >= 0){
		printf("Part name: %s\n", parts[part_number].name);
		printf("Quantity on hand: %d", parts[part_number].on_hand);
	}
	else{
		printf("Part not found.");
	}
}
void print(void){
	printf("Part Number   Part Name.           Quantity on Hand\n");
	for (int i = 0; i < current_part; i++){
		printf("%7d.         %-25s%11d\n", parts[i].number, parts[i].name, parts[i].on_hand);
	}
}