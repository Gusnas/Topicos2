#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

const char *filename = "/home/osboxes/Topicos/tarefa1/observed/teste.x";

void main()
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
    	if(access(*filename, F_OK) == 0
	{
		kill(pid, SIGUSR1);
		// file exists
	}
	else
	{
		// file doesn't exist
	}
        for (;;); /* loop for ever */
    }
    else /* parent */
    { 

    }
}

void sigusr1()
{
	signal(SIGUSR1, sigusr1);
	printf("SIGUSR1");
}
