/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:35:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/31 17:07:19 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void trim_spaces(char **line)
{
	int i;
	int j;
	int n;
	int len;
	char *new;

	i = 0;
	len = ft_strlen_no_spaces(*line);
	new = calloc(len + 1, sizeof(char));
	if (!new)
		return ;
	while ((*line)[i] == SPACE)
		i++;
	n = len + i;
	j = 0;
	while (i < n)
		new[j++] = (*line)[i++];
	free(*line);
	*line = new;
}

void only_one_space(char **line, char **new, t_var v)
{
	bool	in_space;
	
	in_space = false;
	while ((*line)[v.i])
	{
		if ((*line)[v.i] == SPACE)
		{
			if (in_space)
			{
				v.i++;
				continue;		
			}
			in_space = true;
			(*new)[v.j++] = (*line)[v.i++];
		}
		else
		{
			(*new)[v.j++] = (*line)[v.i++];
			in_space = false;
		}
	}
	free(*line);
	*line = *new;
}

void	remove_extra_spaces(char **line)
{
	t_var	v;
	char *new;
	bool in_space;

	init_var(&v);
	trim_spaces(line); // antes de alocar memória 
	new = calloc(count_chars(*line) + 1, sizeof(char));
	if (!new)
		return ;
	only_one_space(line, &new, v);
}
