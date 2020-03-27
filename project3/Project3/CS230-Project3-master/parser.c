#ifndef PARSER_H
#define PARSER_H
#include "parser.h"
#endif //PARSER_H

/*
//I need to find a way to move from word to word. Once that happens can easily increment it
struct BSTNode fileTokenization(int fd){
//int fd = open("pathname",flags, mode);
struct *parsedWord = NULL;
char buffer[50];
//use lseek to find position
char *c;
//curr = lseek(fd,malloc(sizeOf(char *c),SEEK_CUR);
//read(fd,buffer,count
c = read(fd,buffer,malloc(sizeof(char *c)));
//pass position to helper funtion to get next word
addWord(parsedWord->word);
close(fd);
//return BST
}
*/
Node* fileTokenizer(int fileDes, Node* root){
	//Prototypes	
	off_t lseek(int,off_t, int);
	ssize_t read(int, void *, size_t );
	char *strtok(char *,const char *);
	struct Node* addWord(Node*, char*);
	char* strstr(const char*, const char*);
	Node* newTree(char *);
	char* addEOS(char*);
	//End Prototypes

	Node** temp = &root;

	if(fileDes == -1){
		return *temp;
	}

	//***Use lseek to jump to end of file record num bytes then jump back to beginning offset***//
	//***Uses file size to create char buffer array the size of the file***//
	//***copies the contents of the file into buffer***//

		
	int fileSize = (int) lseek(fileDes,0,SEEK_END);
	char buffer[fileSize+1];
	int beginning = lseek(fileDes,0,SEEK_SET);
	if(fileSize==-1){
		return *temp;	
	}
	
	int bufIndex = 0;
	while(read(fileDes,buffer+bufIndex, 10))
	bufIndex+=10;
	buffer[fileSize]='\0';

	//***split into smaller words***//
	char *nextWord = strtok(buffer," ");
	while(nextWord != NULL){
		if(strstr(".,;:?\?/!*\"\\@#$%^&)(_+-=\n\t",&nextWord[0]) != NULL){
			nextWord++;
		}
		if(strstr(".,;:?\?/!*\"\\@#$%^&)(_+-=\n\t",&nextWord[strlen(nextWord)-1]) !=NULL){
			nextWord[strlen(nextWord)-1] = '\0';
		}
		if(*temp == NULL){
			char* input = addEOS(nextWord);
			*temp = newTree(input);
			//free(input);
		}
		else{
			char* input = addEOS(nextWord);			
			addWord(*temp, input);
			//free(input);
		}
		nextWord = strtok(NULL," ");
	}
	//use lseek to get size of file, use read to pull entire file into an giant string, split up string into smaller 
	//words
	return root;
}

//Adds the end of string NULL character to the end of the string
//Free the pointer after it has been used
char* addEOS(char* input){
	char* output = (char*) malloc(sizeof(input)+1);
	strcpy(output, input);
	strcat(output, "\0");
	return output;
}
