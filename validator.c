#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * allowFlags[] = {"/help", "/flag"};
int volAllowFlags = sizeof allowFlags/sizeof allowFlags[0];

void checkValidateFlags(int vol, char ** arr) {
	bool statusFlag = false;
	char errFlag = -1;
	for(int i = 1; i < vol; i++) {
		statusFlag = false;
		for(int j = 0; j < volAllowFlags; j++) {
			if(strcmp(arr[i], allowFlags[j]) == 0) {
				statusFlag = true;
				errFlag = -1;
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

int main (int argc, char ** argv) {

	if(argc > 1) checkValidateFlags(argc, argv);
	
	if(argc == 2)
		for(int i = 1; i < argc; i++)
			if(strcmp(argv[i], "/help") == 0) {
				printf("\r\nUsing:\r\n");
				printf("    %-15s        %s %s\r\n", argv[0], "[/help]", "[/flag]");
				printf("\r\n");
				printf("Parameters:\r\n");
				printf("    %-15s        %-25s\r\n", "/help", "call help");
			}
	
	return EXIT_SUCCESS;
}