#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	printf("Main before fork\n");
	int pid = fork();
	if (pid == 0){
		printf ("i am a child after fork\n");
		char *args[]= { "free", "-h" , NULL};
		execvp("free",args);
	}
	else {
		printf("Going to launch ps -ef\n");
		char *args[]= { "/bin/ps", "-ef" , NULL};
		execvp("/bin/ps",args);
		wait(NULL);
	}
	return 0;
		
}
