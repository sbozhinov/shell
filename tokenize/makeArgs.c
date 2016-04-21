#include "makeArgs.h"

void clean(int argc, char **argv)
{
    int i;
    for (i = 0; i < argc; i++) {
        free(argv[i]);
        argv[i] = NULL;
    }
    
    free(argv);

}// end clean

void printargs(int argc, char **argv)
{
	int x;
	for(x = 0; x < argc; x++)
		printf("%s\n", argv[x]);

}// end printargs

int makeargs(char *s, char *** argv){

    if(s[0] == '\0'){
    	exit(-99);
    }
	char copy[MAX];
	strcpy(copy,s);
	int count = 0,x = 1;

	char * token = strtok(copy," ");
	while(token!= NULL){
	count++;
	token = strtok(NULL, " ");
	}//endwhile

	(*argv) = (char**)calloc(count + 1, sizeof(char*));

	token = strtok(s," ");
	(*argv)[0] = (char*)calloc(strlen(token)+1,sizeof(char));
	strcpy((*argv)[0], token);
	

	for( ;x<count; x++){
		token = strtok(NULL," ");
		(*argv)[x]=(char*)calloc(strlen(token)+1,sizeof(char));
		strcpy((*argv)[x], token);
	}

	return count;
}
