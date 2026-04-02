/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:46:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/02 01:00:21 by anisabel         ###   ########.fr       */
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

int	count_chars_one_space(char *line)  // conta os espaços apenas 1 vez
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
	var->new = NULL;
	var->begin = 0;
	var->end = 0;
}

