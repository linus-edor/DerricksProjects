#include <unistd.h> 
#include <stdio.h> 
#include<sys/wait.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 9000

/*Function copy a character array in a c-style string*/
char * copyBuffer(char buf[]){
   char *str = (char *) malloc(sizeof(char) * strlen(buf)); 
   for(int i = 0; i < strlen(buf); i++){
      str[i] = buf[i];
   }
   return str;
} 

int main(int argc, char *argv[]) 
{

	/* The referee application uses TCP/IP instead of named socket.*/  
	
	int server_fd, new_socket1, new_socket2, valread1, valread2; 

	int turns1 = atoi(argv[1]);
	int turns2 = turns1;
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	

	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port 9000 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
	// Forcefully attaching socket to the port 9000 
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 

	int j=0, k=0;
	
	//String arrays to store the respective choices of the players 
	char* player1Choices[turns1];
	char* player2Choices[turns1];

	    /*Accept connection from first player and begin game when both 	
		players are ready*/
	    if ((new_socket1 = accept(server_fd, (struct sockaddr 				*)&address, (socklen_t*)&addrlen))<0) 
	    { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
       	    }else{
		char buffer[1024] = {0}; 
	        valread1 = recv( new_socket1 , buffer, 1024, 0);
	        if(strcmp(buffer,"READY")==0){
	    	   send(new_socket1 , "GO" , 2 , 0 ); 
	        }
		while(turns1 > 0){
		    char buffer1[1024] = {0}; 
	            valread1 = recv(new_socket1 , buffer1, 1024, 0); 
		    if(valread1 > 0){
			player1Choices[j] = copyBuffer(buffer1);  
		    	send(new_socket1 , "GO" , 2 , 0 ); 
		    }else{
			perror("Read failed. Exiting game");
		    }
		    j++;
		    turns1--;
		}
		send(new_socket1 , "STOP" , 4 , 0 ); 

	   }

	   /*Wait for 10 milliseconds to allow second player to fully start and 	
		establish connection*/
	    int *wait_time = (int*)10;
	    wait(wait_time);
	

	    /*Accept connection from second and begin game when both players 	
		are ready*/
	    if ((new_socket2 = accept(server_fd, (struct sockaddr 				*)&address, (socklen_t*)&addrlen))<0) 
	    { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
       	    }else{
		char buffer[1024] = {0}; 
	        valread2 = recv( new_socket2 , buffer, 1024, 0);
	        if(strcmp(buffer,"READY")==0){
	    	   send(new_socket2 , "GO" , 2 , 0 ); 
	        }
		while(turns2 > 0){
		    char buffer2[1024] = {0}; 
	            valread2 = recv(new_socket2 , buffer2, 1024, 0); 
			if(valread2 > 0){
			player2Choices[k] = copyBuffer(buffer2);  

		    	send(new_socket2 , "GO" , 2 , 0 ); 
		    }else{
			perror("\nRead failed. Exiting game");
		    }
		    k++;
		    turns2--;
		}
		send(new_socket2 , "STOP" , 4 , 0 ); 
	   }

	
	/*Game session is over. Compute and display the results.*/
	int player1Score=0, player2Score=0;
	printf("\n");
	for (int i = 0; i < sizeof(player1Choices)/sizeof(player1Choices[0]); 			i++){
		printf("Go Players [%d]", i+1);
		printf("\n\tPlayer 1: %s\n\tPlayer 2: %s\n",player1Choices[i],player2Choices[i]);
		if(strcmp(player1Choices[i],player2Choices[i])==0){
		    printf("\tPlayers Draw\n");
		    continue;
		}else{ 
		    if(strcmp("Rock",player1Choices[i])==0 && 		   
			strcmp("Scissors",player2Choices[i])==0){
			player1Score++;
			printf("\tPlayer 1 Wins\n");
		     }else if(strcmp("Paper",player1Choices[i])==0 && 
			strcmp("Rock",player2Choices[i])==0){
			player1Score++;
			printf("\tPlayer 1 Wins\n");
		     }else if(strcmp("Scissors",player1Choices[i])==0 && 
			strcmp("Paper",player2Choices[i])==0){
			player1Score++;
			printf("\tPlayer 1 Wins\n");
		     }else if(strcmp("Rock",player2Choices[i])==0 && 		
			strcmp("Scissors",player1Choices[i])==0){
			player2Score++;
			printf("\tPlayer 2 Wins\n");
		     }else if(strcmp("Paper",player2Choices[i])==0 && 
			strcmp("Rock",player1Choices[i])==0){
			player2Score++;
			printf("\tPlayer 2 Wins\n");
		     }else if(strcmp("Scissors",player2Choices[i])==0 && 
			strcmp("Paper",player1Choices[i])==0){
			player2Score++;
			printf("\tPlayer 2 Wins\n");
		     }

		}
	}

	printf("\nFinal Score:");
	printf("\n\tPlayer 1: %d\n\tPlayer 2: %d\n", player1Score,player2Score);

	if(player1Score==player2Score){
	   printf("\nPlayers Draw\n");
	}else if(player1Score>player2Score){
	   printf("\nPlayers 1 Wins\n");
	}else{
	   printf("\nPlayers 2 Wins\n");
	}
	
	return 0;
} 

