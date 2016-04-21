CC=gcc

mssh:	cscd340hw8.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./history/history.o ./pipes/pipes.o ./init/init.o
	gcc -g cscd340hw8.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./history/history.o ./pipes/pipes.o ./init/init.o -o mssh

makeArgs.o:	./tokenize/makeArgs.c ./tokenize/makeArgs.h
	gcc -g -c ./tokenize/makeArgs.c

myUtils.o:	./utils/myUtils.c ./utils/myUtils.h
	gcc -g -c ./utils/myUtils.c

process.o:	./process/process.c ./process/process.h
	gcc -g -c ./process/process.c	

linkedList.o:	./linkedlist/linkedList.h ./linkedlist/linkedList.c ./linkedlist/genericData.h ./linkedlist/requiredIncludes.h
	gcc -g -c ./linkedlist/linkedList.c

listUtils.o:	./linkedlist/listUtils.c ./linkedlist/listUtils.h
	gcc -g -c ./linkedlist/listUtils.c

history.o:	./history/history.c
	gcc -g -c ./history/history.c

pipes.o:	./pipes/pipes.c ./pipes/pipes.h
	gcc -g -c ./pipes/pipes.c

init.o:		./init/init.c ./init/init.h
	gcc -g -c ./init/init.c

clean:
	rm ./pipes/pipes.o	
	rm ./utils/myUtils.o
	rm ./process/process.o
	rm ./tokenize/makeArgs.o
	rm ./init/init.o
	rm ./linkedlist/linkedList.o
	rm ./linkedlist/listUtils.o

	rm mssh


