/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:13:59 by joabotel          #+#    #+#             */
/*   Updated: 2026/01/29 16:14:02 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft_updated/libft.h"

static int ft_flag(char *arg)
{
	int i;

	i = 1;
	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int echo(char **arg)
{
	int i;
	int j;

	if (!arg)
		return (ft_putchar_fd('\n', 1), 0);
	j = 1;
	i = 1;
	while (arg[i] && ft_flag(arg[i]))
	{
		j = 0;
		i++;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (j)
		ft_putchar_fd('\n', 1);
	return (0);
}

/*
int	main(int ac, char **av){
	echo(av);
}*/
