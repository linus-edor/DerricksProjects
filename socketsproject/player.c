#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <string.h> 
#include <unistd.h>
#include <time.h>
#define PORT 9000 

/**
*The Player program.
*Each player instance started will establish a TCP/IP connection to the socket connection created by the referee program.
*/
int main(int argc, char *argv[]) 
{ 
	
	printf("\tPlayer %s: Ready\n",argv[0]);
	struct sockaddr_in address; 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 
	
	//Establish connection to the referee (server) here.

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	//Send the READY message here	
	char *msg = "READY"+'\0';
	send(sock , msg , strlen(msg) , 0 ); 
	srand(getpid());//initialize the pseudo-random number generator by 	
			//passing a seed value

	/*until player receives a STOP, it should continue to choose and send 	
	  an option each time it receives a GO*/ 
	char *options[] = {"Paper", "Scissors", "Rock"};
	int stop = 0;
	while(stop==0&&read( sock , buffer, 1024)>0){
	     if(strcmp(buffer,"GO")==0){
		 char *option = options[rand()%3]+'\0';
	         send(sock , option , strlen(option) , 0 ); 
	     }else if(strcmp(buffer,"STOP")==0){
		//Close the tcp connection here upon receiving a STOP from 	
			//referee
		stop=1;	
		close(sock);	
	     }
	} 

     return 0;
} 

