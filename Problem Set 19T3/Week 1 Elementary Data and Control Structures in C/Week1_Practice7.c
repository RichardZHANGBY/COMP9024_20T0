#include <stdio.h>
#include <assert.h>

typedef struct{
	int end;
	int item[MAXITEMS];
} intquene;

static intquene quene;

void QueneInit(){
	quene.end = 0;
}

int QueneIsEmpty(){
	return quene.end == 0;
}

void QueneEnqueue(int num){
	assert(quene.end < MAXITEMS - 1);
	quene.item[quene.end++] = num;
}

int QueneDequene(){
	int result = quene.item[0];
	for (int i = 1; i < end; i++){
		quene.item[i-1] = quene.item[i];
	}
	return result;
}