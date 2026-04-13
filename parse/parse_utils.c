/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:46:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/13 01:06:13 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	int		i;
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

int count_pipes(char *line)  
{
    int i;
    int counter;
    
    i = 0;
	counter = 0;
    while (line[i])
	{
		if (line[i] == '|' && !is_in_quotes(line, i))
			counter++;
		i++;
	}
	return (counter);
}

/* int	count_char (int begin, int end)
{
	if (end < begin)
		return (0);
	return (end - begin);
} */
