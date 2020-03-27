#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void main(){
		srand(time(0));
		int randNum=  rand() % 7;
		printf("%i\n",randNum);
		srand(time(0));
		randNum=  rand() % 7;
		printf("%i\n",randNum);
		srand(time(0));
		randNum=  rand() % 7;
		printf("%i\n",randNum);
		srand(time(0));
		randNum=  rand() % 7;
		printf("%i\n",randNum);
		srand(time(0));
		randNum=  rand() % 7;
		printf("%i\n",randNum);
	
}
