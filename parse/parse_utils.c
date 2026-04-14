/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:46:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/13 22:13:10 by anisabel         ###   ########.fr       */
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
	int				i;
	int				counter;
	bool			in_space;
	t_quote_status	status;
	
	i = 0;
	counter = 0;
	in_space = false;
	status.in_dq = false;
	status.in_sq = false;
	while (line[i])
	{
		update_quotes(line[i], &status);
		if ((status.in_dq || status.in_sq) && line[i] == ' ')
			counter ++;
		else if (!(status.in_dq || status.in_sq) && line[i] == ' ')
		{
			if (!in_space)
			{
				counter++;
				in_space = true;
			}
		}
		else
		{
			counter++;
			in_space = false;
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




c 1 - ls


ls | cat  < sjnkda | wc