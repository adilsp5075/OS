#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  pid_t pid;
  pid = fork();
  if (pid < 0)
  {
    printf("Error\n");
  }
	if (pid == 0)
  {
      printf("hello from child process\n");
      printf("Child process id : %d\n",getpid());
      printf("parent process id : %d\n",getppid());
      fflush(stdout);
      execlp("./add.exe",NULL);
      exit(0);
  }
	else
	{
	   printf("hello from parent process\n");
     printf("Child process id (from parent) : %d\n",getpid());
     printf("parent process id (from parent) : %d\n",getppid());
	   wait(NULL);
	   printf("child process terminated\n");
	}
	return 0;
}
