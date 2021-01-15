#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <spawn.h>

extern char **environ;
int main(int argc, char *argv[])
{

*argv++;

printf("Written by Derrick Annor\n");
//char* p0[] = {*argv++,NULL};
char *args[] = {"/referee",*argv++, NULL};

pid_t pid;
if (fork() > 0)			
{

 posix_spawn(&pid, "./referee", NULL, NULL, args, environ);

//     execl("./referee", "/referee", *argv++, (char*)NULL);		/* Create the referee process */
}else{
     perror("Starting referee");
     exit(EXIT_FAILURE); 
}

//char* p1[] = {"1",NULL};
//char* p2[] = {"2",NULL};

if(fork() > 0){
char *args1[] = {"1", NULL};
pid_t pid1;
 posix_spawn(&pid1, "./player", NULL, NULL, args1, environ);

}else{
     perror("Starting player1");
     exit(EXIT_FAILURE); 
}

if(fork() > 0){
char *args2[] = {"2", NULL};
pid_t pid2;
 posix_spawn(&pid2, "./player", NULL, NULL, args2, environ);



/* Create the player 2 process */
}else{
     perror("Starting player2");
     exit(EXIT_FAILURE); 
}

return 0;
}
