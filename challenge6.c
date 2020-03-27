#include <stdio.h>
#include <stdlib.h>

int main(void){
	void filePrint();
	char fileName[50];
	scanf("%s", fileName);
	filePrint(fileName);
	return 0;
}

void filePrint(char *fileName){
	int breakpoint = 0;
	FILE *file = fopen(fileName, "r");
	char userInput[1];
	
	while(userInput[0] != 'q' || userInput[0] != 'Q'){
		for(int i=0; i<20; i++){
			if(feof(file)){
				printf("\n\nEnd of file, exiting...\n");
				exit(1);
			}
			char buffer[100];	
			fgets(buffer, 100, file);
			printf("%s\n", buffer);
		}
		scanf(" %c", userInput);
	}
	
}