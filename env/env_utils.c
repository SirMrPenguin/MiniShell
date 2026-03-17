/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:46:11 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/14 20:37:57 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void	print_array(char **array)
{
	int	i;
	int	j;
	
	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		i++;
	}
} */

bool	ft_is_env_var_valid(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			return (true);
	}
		return (false);
}

int	ft_len_till_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
/* 	if (str[i] == '=')
		i++; */
	return (i);
}
