#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#endif //MAIN_H

//NEED TO ADD ERROR HANDLING FOR OPEN AND CLOSE
int main(int argc, char* argv[]){
	//Prototypes start
	Node* fileTokenizer(int, Node*);
	void printTree(Node*);	
	//Prototypes end

	Node* freqTree = NULL;

	//parse environmental variable if it exists
	char* wordFreakEnv = getenv("WORD_FREAK");
	if(wordFreakEnv != NULL){
		int envFD = open(wordFreakEnv, 0x0000);	
		if(envFD==-1){
			char* errStr = strerror(errno);
			write(1, errStr, strlen(errStr));
			exit(-1);
		}		
		freqTree = fileTokenizer(envFD, freqTree);		
		
		close(envFD);
			
		//ADD ERROR CHECK
	}	

	//parse main arguments if they exist
	for(int i=1; i<argc; i++){
		int currentArgFile = open(argv[i], 0x0000);
		if(currentArgFile==-1){
			char* errStr = strerror(errno);
			write(1, errStr, strlen(errStr));
			exit(-1);
		}		
		freqTree = fileTokenizer(currentArgFile, freqTree);
		close(currentArgFile);

		//ADD ERROR CHECK
	}
	
	//parse stdin for any contents (might not have any)
	//open(stdin) ~~~ already open as file descriptor 0	
	freqTree = fileTokenizer(0, freqTree);
	//close(stdin) ~~~ doesn't need to be closed

	printTree(freqTree);
	
}
