#include "test.h"
int main()
{
	char *app = "hello";
	pid_t pid = fork();
	if (pid == 0)
	{
		ttu_app_create(app);
	}
	else
	{
		sleep(5);
		ttu_app_stop(app);

	}

	return 0;
}
