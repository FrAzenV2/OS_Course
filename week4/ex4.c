#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_SIZE 100

int main(){
	char shell_command[COMMAND_SIZE];
	while(1){
		char directory[COMMAND_SIZE];
		getcwd(directory, sizeof(directory));
		printf("shell:%s: ", directory);
		fgets(shell_command, COMMAND_SIZE, stdin);
		shell_command[strlen(shell_command) - 1] = '\0';
		if(strcmp(shell_command, "exit") == 0){
			break;
		} else {
	  	system(shell_command);
		}
	}
	return 0;
}
