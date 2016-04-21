#include "process.h"

void forkIt(char ** argv){
	pid_t  child;

    child = fork();
    if(child==0)

    {
       //child process
	//execv("/bin/ls", argv);
              if(!execvp(*argv, argv) ){
		exit(-99);
		}

    }

    else if(child>0)
    {
        int status;
        waitpid(-1, &status, 0);
        
    }
    else
    {
       
       printf("forkFailed\n");
    }

}

    
