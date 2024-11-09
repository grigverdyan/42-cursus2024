#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str)
{
    size_t  len = 0;

    while (str[len])
        ++len;
    return len;
}

void error_msg(const char *str)
{
	write(2, str, ft_strlen(str));
}

void handle_error(const char *str)
{
	error_msg(str);
	exit(1);
}

int cd(char **argv, int i)
{
	if (i != 2)
	{	
		error_msg("error: cd: bad arguments\n");
		return 1;
	}
	if (chdir(argv[1]) == -1)
	{
		error_msg("error: cd: cannot change directory to ");
		error_msg(argv[1]);
		error_msg("\n");
		return 1;
	}
	return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		handle_error("error: fatal\n");
}

int	exec(char **argv, int i, char **envp)
{
	int fd[2];
	int has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))
		return cd(argv, i);
	if (has_pipe && pipe(fd) == -1)
		handle_error("error: fatal\n");

	int pid = fork();
	if (pid == -1)
		handle_error("error: fatal\n");
	if (!pid)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));
		execve(*argv, argv, envp);
		error_msg("error: cannot execute ");
		error_msg(*argv); 
		error_msg("\n");
		exit(1);
	}
	int status;
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0, status = 0;

	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, envp);
	}
	return status;
}