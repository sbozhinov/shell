#include "pipes.h"

int containsPipe(char *s){

int count = 0;
	while(*s){
	if (*s++ == '|') 
	++count;
	}
return count;
}

char ** parsePrePipe(char *s, int * preCount){

        char *temp = strdup(s);
        strstr(temp, "|")[0] = 0; 
        char **ret = NULL;
        makeargs(temp, &ret); 
        free(temp); 
        return ret;
}

char ** parsePostPipe(char *s, int * postCount){
        char *temp = strdup(s); 
        char *second = strstr(temp, "|"); 
        char **ret =NULL;
	makeargs(second + 1, &ret); 
        free(temp); 
        return ret;
}

void pipeIt(char ** prePipe, char ** postPipe){

	pid_t pid;
	int fd[2], res, status;

	res = pipe(fd);

	if(res < 0)
	{
		printf("Pipe Failure\n");
		exit(-1);
	}// end if

	pid = fork();

	if(pid != 0)
	{
		close(fd[1]); 
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]); 
		execvp(*postPipe, postPipe);
	}// end if AKA parent
	else
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execvp(*prePipe,prePipe);
	}// end else AKA child
}



