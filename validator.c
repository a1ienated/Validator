#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VERSION "1.1"

void cmdHelp(void);
void cmdVer(void);
char * allowFlags[] = {"--help", "--version"};
int volArrFlags = sizeof allowFlags/sizeof allowFlags[0];


void checkValidateFlags(int vol, char ** arr) {
	bool statusFlag = false;
	char errFlag = -1;
	for(int i = 1; i < vol; i++) {
		statusFlag = false;
		for(int j = 0; j < volArrFlags; j++) {
			if(strcmp(arr[i], allowFlags[j]) == 0) {
				statusFlag = true;
				errFlag = -1;
				break;
				//printf("True\n");
			}
			else {
				errFlag = i;
				//printf("false\n");
				//statusFlag = false;
			}			
		}
		/*if(statusFlag)
			printf("True\n");*/
		if(!statusFlag) {
			printf("Invalid flag entry: %s\n", arr[errFlag]);
			exit(EXIT_FAILURE);
		}
		//printf("\r\n");		
	}
}

void execCommands(int counter, char ** commands) {

}

void cmdHelp(void) {
	printf("Help.\n");
}

void cmdVer() {
	printf("Ver. %s\n", VERSION);
}

int main (int argc, char ** argv) {

	if(argc > 1) checkValidateFlags(argc, argv);
	else printf("Login to the program.\n");

	execCommands(argc, argv);	
	
	return EXIT_SUCCESS;
}