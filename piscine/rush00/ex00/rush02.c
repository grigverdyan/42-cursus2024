/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:39:32 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/14 23:06:50 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (i == 0 && (j == 0 || j == col - 1))
				ft_putchar('A');
			else if (i == row - 1 && (j == 0 || j == col - 1))
				ft_putchar('C');
			else if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
