#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

char* params[20];
char *token;


void tokenize(char*);

int main(int argc, char* argv[])
{


	char buff[256],*m;


	int pid[12];
	int x;

	for(int index; index<12; index++)
	{
		pid[index]=-10;
	}

	pid[0]=getpid(); 


	


	if(pid[0]==getpid()) 
	{
		x=fork();  //create 1
		if(x==0)
		pid[1]=getpid();
		
	}

	if(pid[0]==getpid()) 
	{
		x=fork(); //create 2
		if(x==0)
		pid[2]=getpid();
	}

	if(pid[1]==getpid()) 
	{
		x=fork(); //create 3
		if(x==0)
		pid[3]=getpid();

	}

	if(pid[2]==getpid()) 
	{
		x=fork(); //create 4
		if(x==0)
		pid[4]=getpid();
	}

	if(pid[2]==getpid()) 
	{
		x=fork();  //create 5
		if(x==0)
		pid[5]=getpid();
	}

	if(pid[3]==getpid()) 
	{	
		x=fork(); //create 6
		if(x==0)
		pid[6]=getpid();
	}


	if(pid[4]==getpid()) 
	{	
		x=fork(); //create 7
		if(x==0)
		pid[7]=getpid();
	}

	if(pid[4]==getpid()) 
	{	
		x=fork(); //create 8
		if(x==0)
		pid[8]=getpid();
	}


	if(pid[5]==getpid()) 
	{	//sleep(1);
		x=fork(); //create 9
		if(x==0)
		pid[9]=getpid();
	}

	if(pid[5]==getpid()) 
	{
		x=fork(); //create 10
		if(x==0)
		pid[10]=getpid();
	}

	if(pid[5]==getpid()) 
	{
		x=fork(); //create 11
		if(x==0)
		pid[11]=getpid();
	}


for(int i=11;i>=0;i--)
{	
	if(pid[i]==getpid())
	{
		
		printf("\nnode_no.: %d, pid: %d , parent_id: %d\n\n",i,getpid(), getppid());
		
		FILE *file = fopen("commands", "r");
		
		int lineNumber=11-i;
		int count = 0;
   		 while ((fgets(buff, 256, file)) != NULL) /* read a line */
    	{
        	if (count == lineNumber)
        	{
             	break;
        	}
        	else
        	{
            count++;
        	}
    	}

    	fclose(file);
    	tokenize(buff);
    	execvp(params[0], params);
    	perror("error");
	}
	else
	{
		usleep(2000);
	}

	
}

while(wait(NULL)!=-1);


return 0;

}


void tokenize(char* line)
{
	int i = 0;
	params[i] = strtok(line," ");

	do
	{
		i++;
		params[i] = strtok(NULL, " ");
	}while(params[i] != NULL);
	strtok(params[i-1], "\n");
}
