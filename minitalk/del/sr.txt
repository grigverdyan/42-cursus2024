#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"

void	handle_signal(int sig)
{
	static unsigned char	msg = 0;
	static int				size_bit = 0;

	++size_bit;
	msg = msg >> 1;
	if (sig == SIGUSR1)
		msg = msg | 128;
	if (size_bit == 8)
	{
		ft_printf("%s", msg);
		size_bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Process ID : %d\n", pid);
	while (1)
		pause();
	return (0);
}
