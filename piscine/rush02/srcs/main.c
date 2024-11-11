/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:54:58 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:11:58 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "validation.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	char	*dict_name;
	char	*number;
	int		ret_type;

	if (argc == 2)
	{
		number = argv[1];
		dict_name = "numbers.dict";
	}
	else if (argc == 3)
	{
		number = argv[2];
		dict_name = argv[1];
	}
	else
		return (ft_exit("Argument Error\n", 1));
	ret_type = check_params(dict_name, number);
	return (ret_type);
}
