#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <spawn.h>
#include<sys/wait.h> 

extern char **environ;
int main(int argc, char *argv[])
{

/**
*I decided to use posix_spawn insteaded of the exec family of functions 
*because posix_spawn is non-blocking while exec* are not.
*/

pid_t pid;

printf("Written by: Derrick Annor\nPaper, Scissors, Rock: %s Iterations\n", argv[1]);
char *args[] = {"/referee",argv[1], NULL};

/*Start the referee program in a seperate process*/
if (fork() > 0)			
{
 posix_spawn(&pid, "./referee.o", NULL, NULL, args, environ);
}else{
     perror("Starting referee");
     exit(EXIT_FAILURE); 
}

/*Start player 1 in a seperate process*/
if(fork() > 0){
char *args1[] = {"1", NULL}; //command argument of 1
pid_t pid1;
 posix_spawn(&pid1, "./player.o", NULL, NULL, args1, environ);
}else{
     perror("Starting player1");
     exit(EXIT_FAILURE); 
}


/*Start player 2 in a seperate process*/
if(fork() > 0){
char *args2[] = {"2", NULL}; //command argument of 1
pid_t pid2;
 posix_spawn(&pid2, "./player.o", NULL, NULL, args2, environ);
}else{
     perror("Starting player2");
     exit(EXIT_FAILURE); 
}

fflush(stdout);

return 0;

}
