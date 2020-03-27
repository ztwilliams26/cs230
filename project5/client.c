#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>


int main(int argc, char* argv[]){
//Check to ensure that the correct number of arguments are passed and handled
	if(argc !=4){
		printf("Usage: <NetId>@umass.edu port ipAddress\n");
		exit(-1);
	}	
	const char* spireID = argv[1];	
	const int port = atoi(argv[2]);
	const char* ipAddress = argv[3];
	
//Create socket, including creating sockaddr_in to be used for the connection
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		perror("Error: ");
		exit(-1);
	}
	struct sockaddr_in server;
	struct in_addr server_addr;
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	if(!inet_pton(AF_INET, ipAddress,&server_addr.s_addr)){
		printf("Not a valid network address\n");
		exit(-1);
	}
	server.sin_addr=server_addr;
	
//Connect to the server socket, make that connection!!!
	if(connect(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0){
		perror("Error: ");
		exit(-1);
	}
	
//Send the identifying message and prepare to receive responses
	char* concat(const char*, const char*);	
	int doMath(char*);
	int mySend(int, char*);
	char* identity = concat("cs230 HELLO ",spireID);
	char* identityMsg = concat(identity,"\n");
	free(identity);
	char servReply[2000];
	mySend(sockfd, identityMsg);
	free(identityMsg);
	
//Start receiving messages, calculating the answer, and sending the answer. Stop when we don't receive another math problem
	int condition= 1;
	while(condition){
//Look for a response from server
		if(recv(sockfd, servReply, 2000, 0) <0){
			printf("Failed to receive message from server\n");
			return -1;
		}
		printf("Received message: %s \n", servReply);
//Copy that response so that strtok can be used to check the second word without breaking the string. If that word isn't status we are finished and can leave the while loop		
		char replyCpy[strlen(servReply)+1];
		strcpy(replyCpy, servReply);
		strtok(replyCpy, " \n");
		char* status = strtok(NULL, " \n");
		char* STATUS = "STATUS";
		if(strcmp(status, STATUS)){			
			condition=0;
			continue;
		}		
//Otherwise we compute the math and ship it back to the server!	
		char answerMsg[20];
		sprintf(answerMsg, "cs230 %i\n", doMath(servReply));
		mySend(sockfd, answerMsg);
		
	}
	close(sockfd);
}


//Uses strtok to parse the message and the proceeds to do computations
int doMath(char* input){
	int num1, num2;
	char op;

	strtok(input, " \n");
	strtok(NULL, " \n");
	char* numb1 = strtok(NULL, " \n");
	char* opp = strtok(NULL, " \n");
	char* numb2 = strtok(NULL, " \n");

	op = *opp;	
	num1 = atoi(numb1);
	num2 = atoi(numb2);
	
	if(op == '+'){
		return num1+num2;
	}
	if(op == '-'){
		return num1-num2;
	}
	if(op == '/'){
		return num1/num2;
	}
	if(op == '*'){
		return num1*num2;
	}

	return 0;
}

//Concats strings. I used this before I realized I could use sprintf but hey, this worked fine too. Keeping it because I am too lazy to change my code / get rid of it.
char* concat(const char *str1, const char *str2){
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

//Sends a message while checking for errors. Just made it a separate function for my convenience while writing / reading the code. Only used twice I believe so this really wasn't necessary
int mySend(int fd, char* message){
	if(send(fd, message, strlen(message), 0) <0){
		printf("Message failed to send\n");
		exit(-1);
	}
	printf("Sent message:     %s \n", message);
}
