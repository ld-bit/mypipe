#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fds[2];
    int ret=pipe(fds); 
	if(ret==-1)
	  perror("fds"),exit(0);
	pid_t pid=fork();
	if(pid==0)
	{
      dup2(fds[1],1);
	  execlp("ls","ls","-l",NULL);
	  exit(0);
	}
	else if(pid==-1)
	perror("fork"),exit(0);
	else 
	{
	  wait();
      dup2(fds[0],0);
	  char* buf=(char*) malloc(1000);
	  read(fds[0],buf,1000);
	  printf("%s",buf);
	  free(buf);
	}
}
