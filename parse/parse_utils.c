/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:46:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/28 03:45:29 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tab_to_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' && !is_in_quotes(line, i))
			line[i] = ' ';
		i++;
	}
}

bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int ft_strlen_no_spaces(char *str)
{
	int	i;
	int j;

	i = 0;
	while(str[i] && str[i] == SPACE) // verificar se é preciso str[i]
		i++;
	j = ft_strlen(str) - 1;
	while (str[j] == SPACE && j >= i)
		j--;
	if (j < i)
		return (0);
	return (j - i + 1);
}

int	count_chars(char *line)
{
	int 	i;
	int		counter;
	bool	flag;
	
	i = 0;
	counter = 0;
	flag = false;
	while (line[i])
	{
		if (line[i] == SPACE)
		{
			if (!flag)
			{
				counter++;
				flag = true;
			}
		}
		else
		{
			counter ++;
			flag = false;
		}
		i++;
	}
	return (counter);
}

void	init_var(t_var *var)
{
	var->i = 0;
	var->j = 0;
	var->len = 0;
	var->new = 0;
}

