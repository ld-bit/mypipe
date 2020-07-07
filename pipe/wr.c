#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int fds[2];
	int ret=pipe(fds);
	if(ret==-1)
	  perror("ret"),exit(0);
	pid_t pid=fork();
	if(pid==0)
	{
		close(1);
		sleep(3);
		write(fds[1],"dongge\n",7);
        close(fds[1]);
	}
	else 
	{
		close(0);
		char buf[100];
		read(fds[0],buf,sizeof(buf));
		close(fds[0]);
		printf("%s",buf);
	}
}
