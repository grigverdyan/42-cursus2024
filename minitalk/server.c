#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
	(void)info;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("\n");
	//		kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
		//if (signal == SIGUSR1) {
          //  kill(info->si_pid, SIGUSR1);
        //}
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
