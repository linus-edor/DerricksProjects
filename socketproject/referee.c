#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
int main(int argc, char *argv[]) 
{ 
	
	int server_fd, new_socket1, new_socket2, valread1, valread2; 

	int turns1 = atoi(argv[1]);
	int turns2 = turns1;
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer1[1024] = {0}; 
	char buffer2[1024] = {0}; 
	

	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
	// Forcefully attaching socket to the port 8080 
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
	char* player1Choices[turns1];
	char* player2Choices[turns1];

	    if ((new_socket1 = accept(server_fd, (struct sockaddr 				*)&address, (socklen_t*)&addrlen))<0) 
	    { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
       	    }else{
	        valread1 = read( new_socket1 , buffer1, 1024);
		printf("\n%s\n",buffer1); 
	        if(strcmp(buffer1,"READY")==0){
	    	   send(new_socket1 , "GO" , 2 , 0 ); 
	        }
		while(turns1 > 0){
	            valread1 = read(new_socket1 , buffer1, 1024); 
		    if(valread1 > 0){
			player1Choices[j] = buffer1;  
		    	send(new_socket1 , "GO" , 2 , 0 ); 
		    }else{
			perror("Read failed. Exiting game");
			//exit(EXIT_FAILURE);
		    }
		    j++;
		    turns1--;
		}
		send(new_socket1 , "STOP" , 4 , 0 ); 

	   }


	    if ((new_socket2 = accept(server_fd, (struct sockaddr 				*)&address, (socklen_t*)&addrlen))<0) 
	    { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
       	    }else{
	        valread2 = read( new_socket2 , buffer2, 1024);
		printf("\n%s\n",buffer2); 
	        if(strcmp(buffer2,"READY")==0){
	    	   send(new_socket2 , "GO" , 2 , 0 ); 
	        }
		while(turns2 > 0){
	            valread2 = read(new_socket2 , buffer2, 1024); 
		    if(valread2 > 0){
			player2Choices[k] = buffer2;  
		    	send(new_socket2 , "GO" , 2 , 0 ); 
		    }else{
			perror("\nRead failed. Exiting game");
			//exit(EXIT_FAILURE);
		    }
		    k++;
		    turns2--;
		}
		send(new_socket2 , "STOP" , 4 , 0 ); 
	   }
	printf("Game session over. \nResult:\n");
	for (int i = 0; i < sizeof(player1Choices)/sizeof(player1Choices[0]); 			i++){
		printf("%s:%s\n",player1Choices[i],player2Choices[i]);
	}
	return 0;

} 

