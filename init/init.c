#include "init.h"


void init(LinkedList **aList, LinkedList **hList, char **pathStr) {

	FILE * rcFile = openShellFiles( 0, ".msshrc");
	FILE * histFile = openShellFiles( 0, ".msshrc_history");

	if (rcFile != NULL) {

		initBatch(rcFile, aList, hList, pathStr);
		fclose(rcFile);
	} else {

		putenv("HISTCOUNT=100");
		putenv("HISTFILECOUNT=1000");
		*pathStr = (char *) calloc(strlen(getenv("PATH")) + 1, sizeof(char));
		*pathStr = getenv("PATH");

	}

	if (histFile != NULL) {
		char histStr[MAX];
		int i = 0;
		while (fgets(histStr, MAX, histFile) != NULL) {
			i++;
		}

		fclose(histFile);
	}
}


FILE *openShellFiles(int mode, char *filename) {
	FILE * shellFile = NULL;
	if (mode == 0) {
		shellFile = fopen(filename, "r");
	} else if (mode == 1) {
		shellFile = fopen(filename, "w+");
	} else if (mode == 2) {
		shellFile = fopen(filename, "a");
	}

	if (shellFile == NULL) {

		printf("Failed to open file %s\n", filename);
		return shellFile;
	}

	return shellFile;

}

void initBatch(FILE * bFile,
		LinkedList **aList,
		LinkedList **hList,
		char **pathStr)
{
	char s[MAX];

	fgets(s, MAX, bFile);
	strip(s);
	putenv(s);

	fgets(s, MAX, bFile);
	strip(s);
	putenv(s);

	while (fgets(s, MAX, bFile) != NULL) {
		if (strstr(s, "alias") != NULL) {
			strip(s);
			//TBD
		}

	}

}


