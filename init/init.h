#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linkedlist/listUtils.h"

void init(LinkedList **aList, LinkedList **hList, char **pathStr);

void initBatch(FILE * rcFile, LinkedList **aList, LinkedList **hList, char **pathStr);

FILE *openShellFiles(int mode, char *filename);
