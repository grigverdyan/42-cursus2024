#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

void	throw_error(const char *message)
{
	perror(message);
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
		ft_printf("\nMessage bytes : \n", ft_strlen(argv[2]));
	}
	else
		ft_printf("Message to clinet : ");
	return (0);
}
