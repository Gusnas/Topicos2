#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

const char *filename = "teste.x";

void sigusr1();

int main(void)
{
    int pid;
  
    /* get child process */
    if ((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) 
    { /* child */
	signal(SIGUSR1,sigusr1);
        for (;;); /* loop for ever */
        
    }
    
    else /* parent */
    {
	while(1){
	    	if(access(filename, F_OK) == 0)// file exists
		{
			printf("File exists!\n");
			kill(0,SIGUSR1);		
		}
		else// file doesn't exist
		{
			printf("File doesn't exist!\n");
		}
	}
    }
}

void sigusr1()
{
	signal(SIGUSR1, sigusr1);
	printf("OK\n");
}
