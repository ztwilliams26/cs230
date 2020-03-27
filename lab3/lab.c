#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//The data structure we would use as it will only need as much space for words as necessary. Will do the parsing later but that should be easy
struct parsedWord{
	char* word;
	struct parsedWord* next;
};

int main(int argc, char *argv[]){
	int fileOpen=open(argv[1], O_RDONLY);
	if(fileOpen==-1){
		perror("Error");
		exit(-1);
	}
	//max buffer size ~100kb or 100k characters
	char buffer[100000];
	int bytesReturned;
	while(read(fileOpen, buffer, 10))
	printf("%s", buffer);
	int fileClosed = close(fileOpen);
	if(fileClosed==-1){
		perror("Error");
		exit(-1);
	}
	return 0;
}



