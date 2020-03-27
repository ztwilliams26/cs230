#ifndef JIMMY_FALLON_H
#define JIMMY_FALLON_H
#include "jimmy_fallon.h"
#endif //JIMMY_FALLON_H

//Global variables needed, both static
static sem_t connected_lock, operators;
static int next_id=0;

//Driver function. Creates and executes the calls as separate threads, then waits for them to all complete and join them to end them.
int main(){
	//Necessary constant values
	const int PHONE_CALLS = 10;
	const int NUM_OPERATORS = 3;	

	//Function prototype
	void* phonecall(void*);	

	//Initialize different semaphores
	sem_init(&connected_lock,0,1);
	sem_init(&operators, 0, NUM_OPERATORS);

	//Create phone calls
	pthread_t phonecalls [PHONE_CALLS];	
	for(int i=0; i<PHONE_CALLS; i++){
		pthread_create(&phonecalls[i], NULL, phonecall, NULL);
	}

	//Wait for all calls to complete and close those threads
	for(int i=0; i<PHONE_CALLS; i++){
		pthread_join(phonecalls[i], NULL);
	}

	//Destroy semaphors and finish the program
	sem_destroy(&connected_lock);
	sem_destroy(&operators);
	return 0;
}

//Thread function, acts as an individual phone call
void* phonecall(void* vargp) {
	//Necessary constants within this scope. Would be more memory efficient as a global variable but we're minimizing global variables :-/
	const int NUM_LINES = 5;
	static int connected = 0;

	//Local variables for each thread. Doesn't need synchronization as it assigns the value immediately with incrementation, then creates its own thread specific value explicitly
	int id = ++next_id;
	int connectedBool = 0;

	//Phone call management. Tries connecting until it connects. Only one call can make a connection at a time, with a max of 5 calls - increments connected once it connects and updates the connectedBool variable to allow it to continue into the code once it does so. connectedBool also indicates it is able to leave the while loop
	printf("Call %i starting!\n", id);
	while(connectedBool == 0){
		printf("Call %i is trying to connect!\n", id);
		sem_wait(&connected_lock);
			if(connected<5){
				connected++;
				connectedBool=1;
			}  
			else{
				printf("Call %i could not connect, all lines are busy. Retrying...\n",id);
				sleep(1);
			}
		//leaves the semaphor so that the next individual call can connect		
		sem_post(&connected_lock);
			
		//Once it has connected calls will wait until picked up by an available operator, managed by a counting semaphor. Once it is, the ticket is processed and then the call is finished. connected is also decremented to allow a next call.
		if(connectedBool){
			printf("Call %i has connected! \n", id);
			sem_wait(&operators);
				//*critcal section*
				printf("Call %i is speaking with operator.\n", id);
				sleep(3);
				printf("Call %i has bought a ticket\n", id);
			sem_post(&operators);
			printf("Call %i has hung up \n",id);
			connected--;
		}
	}
	//The thread exits, nothing to return.
	pthread_exit(NULL);
}
