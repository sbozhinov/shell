#include "history.h"
#include "../utils/myUtils.h"
#include "../linkedlist/genericData.h"



void * buildType_Args(int argc, char **argv){
	if(argc == 0 || argv[0]=='\0'){
    	exit(-99);
    }
	 struct hist *h= malloc(sizeof(history));
     h->argc = argc;
     h->argv = argv;
     return h;
}

void 	printType (void *passedIn)
{
	 struct hist *h= (struct hist*)malloc(sizeof(history));
	 h = passedIn;
	 printf("%s \n", h->argv[0]);
	 free(h);

}

void * 	buildType (FILE *fin)
{
		return NULL;
}

void * buildType_Prompt(FILE * fin)
{
	return NULL;
}

int 	compare (const void *p1, const void *p2)
{
	//Book *bk1 = p1;
	//Book *bk2 = p2;
	//if(bk1->title == bk2->title)
		return 0;
	//if(bk1->title > bk2->title)
		return 1;
	//else return -1;
}

void 	cleanType (void *ptr)
{


    free(ptr);
}
