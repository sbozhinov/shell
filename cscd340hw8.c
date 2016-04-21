#include "./pipes/pipes.h"
#include "./utils/myUtils.h"
#include "./process/process.h"
#include "./tokenize/makeArgs.h"
#include "./history/history.h"
#include "./linkedlist/listUtils.h"
#include "./linkedlist/linkedList.h"
#include "./linkedlist/genericData.h"
#include "./init/init.h"

int main()
{
	 char *pathStr;
	  LinkedList * hList = linkedList();
	  LinkedList * aList = linkedList();
    int argc, pipeCount;
    char **argv = NULL, s[MAX];
    init(&aList, &hList,&pathStr);
    printf("Default path: \n%s\n", pathStr);
  int preCount = 0, postCount = 0;
  char ** prePipe = NULL, ** postPipe = NULL;
  

  printf("command?: ");
  fgets(s, MAX, stdin);
  strip(s);

  while(strcmp(s, "exit") != 0)
  {
		pipeCount = containsPipe(s);
		if(pipeCount > 0)
		{
			prePipe = parsePrePipe(s, &preCount);
			postPipe = parsePostPipe(s, &postCount);
			pipeIt(prePipe, postPipe);
			clean(preCount, prePipe);
	        	clean(postCount, postPipe);
		}// end if pipeCount

	  argc = makeargs(s, &argv);

		if(strcmp(s, "history") == 0)
      {

		 addLast(hList, buildNode_Type(buildType_Args(argc, argv)));
         printList(hList, printType);
      }

		else if(strcmp(s, "cd") ==0)
		{
			char str[200] = "cd";
			char * c = argv[1];
			strcpy(str, c);
			chdir(str);
		}



		addLast(hList, buildNode_Type(buildType_Args(argc, argv)));
	  	if(argc != -1)
	  		forkIt(argv);

	  	clean(argc, argv);
	  	argv = NULL;


	printf("command?: ");
	fgets(s, MAX, stdin);
      	strip(s);

  }// end while



 
  return 0;

}// end main

