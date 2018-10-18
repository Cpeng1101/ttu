#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "test.h"
//pid_t app_pid;

int ttu_app_create(char *app_name)
{
	int ret;
	pid_t pid;

	if (NULL == app_name)
	{
		printf("app name is NULL\n");
		return -1;
	}

	char App_Name[20] = "./";
	strcat(App_Name, app_name);
	printf("app is %s\n", App_Name);

	pid = fork();
	if (pid < 0)
	{
		printf("fork error\n");
		return -1;
	}
	else if (0 == pid)
	{
		app_pid = getpid();	
		printf("child pid is %d\n", app_pid);
		execl("/bin/sh", "sh", "-c", App_Name, (char *)0);
	}
	else
	{
		waitpid(pid, NULL, 0);
	} 

	return 0;
}

/*
int ttu_app_stop(char *app_name)
{
	int ret;
	printf("pid is %d\n", app_pid);
	ret = kill(app_pid, SIGINT);	
	if (-1 == ret)
	{
		printf("kill error%d:%s\n", errno, strerror(errno));
		return -1;	
	}

	return 0;
}
*/
int ttu_app_stop(char *app_name)
{
	int ret;
	printf("pid is %d\n", app_pid);
	ret = kill(app_pid, SIGSTOP);	
	if (-1 == ret)
	{
		printf("kill error%d:%s\n", errno, strerror(errno));
		return -1;	
	}

	return 0;
}
