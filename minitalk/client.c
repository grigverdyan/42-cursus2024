#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

void	throw_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);;
}

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = (character >> i);
		if (temp_char % 2 != 0)
		{
			if (kill(pid, SIGUSR1) < 0)
				throw_error("Error sending signal to server!");
		}
		else if (kill(pid, SIGUSR2) < 0)
				throw_error("Error sending signal to server!");
		usleep(100);
	}
}
/*
void	handle_server_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal != SIGUSR1)
		throw_error("Message did not reached to the server successfully\n");
	else
		ft_printf("Message reached to the server successfully\n");
	exit(EXIT_SUCCESS);
}
*/
int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*message;
	size_t		i;
//	struct sigaction sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		throw_error("Error getting valid server PID!");
	message = argv[2];
	i = -1;
//    sa.sa_sigaction= handle_server_signal;
//    sigemptyset(&sa.sa_mask);
//    sa.sa_flags = 0;
//    sigaction(SIGUSR1, &sa, NULL);
	while (message[++i])
		send_signal(server_pid, message[i]);
	send_signal(server_pid, message[i]);
//	pause();
	return (0);
}
