#include <unistd.h>
#include <stdlib.h>

/*  init─┬─init───bash───pstree
     └─{init}
*   Before the first pstree command forks and creates its copy. Parent on the left, child on the right side.
*   init─┬─init───bash───pstree
*     └─2*[{init}]
*   Between the first and the second pstree command both of the process created earlier forks themself.
*   So, all in all it creates 8 processes;
*
*   If we will change amount of loops, amount of processes will be 2^loops.
*/
int main(){
	for(int i = 0; i < 3; i++){
		fork();
		sleep(5);
	}
}
