#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	throw_error(const char *message)
{
	perror;
	exit(EXIT_FAILURE);;
}

void	send_to_server(int pid, char *msg)
{
	size_t	j;
	size_t	len;
	size_t	index;

	len = ft_strlen(msg);
	index = -1;
	while (msg[++index])
	{
		j = -1;
		while (++j < 8)
		{
			if ((msg[index] >> j) & 1)
			{
				if (kill(pid, SIGUSR1) < 0)
					throw_error("Error sending signal to server!");
			}
			else
				if (kill(pid, SIGUSR2) < 0)
					throw_error("Error sending signal to server!");
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			throw_error("Error: PID wrong!");
		send_to_server(pid, argv[2]);
		write(1, "\n", 1);
		ft_putstr_fd("Message bytes : ", 1);
		ft_putnbr_fd(ft_strlen(argv[2]), 1);
		write(1, "\n", 1);
	}
	else
		ft_putendl_fd("Message to clinet : ", 1);
	return (0);
}
