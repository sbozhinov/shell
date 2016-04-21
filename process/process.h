#ifndef PROCESS_H
#define PROCESS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void forkIt(char ** argv);
#endif
