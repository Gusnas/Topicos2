#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int sign)
{
	if(sign = SIGUSR1)
	{
		write(0,"OK\n",3);
	}
}

int main(){
	signal(SIGUSR1, sig_handler);
	while(1){
		sleep(1);
	}
	return 0;
}
