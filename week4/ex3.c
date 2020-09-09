#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_SIZE 100


int main(){
	char shell_command[COMMAND_SIZE];
	while(1){
		char dir[COMMAND_SIZE];
		getcwd(dir, sizeof(dir));
		printf("shell:%s: ", dir);
		scanf("%s", shell_command);
		if(strcmp(shell_command, "exit") == 0){
			break;
		} else {
	  	system(shell_command);
		}
	}
	return 0;
}
