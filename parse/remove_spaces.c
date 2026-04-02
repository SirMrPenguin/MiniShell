/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:35:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/02 03:04:27 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strlen_no_spaces(char *str)
{
	int	i;
	int j;
	
	if (!str)
		return (0);
	i = 0;
	while(str[i] && str[i] == ' ') // verificar se é preciso str[i]
		i++;
	j = ft_strlen(str) - 1;
	while (j >= i && str[j] == ' ')
		j--;
	if (j < i)
		return (0);
	return (j - i + 1);
}

void trim_spaces(char **line)
{
	int i;
	int j;
	int n;
	int len;
	char *new;
	
	if (!line || !*line)
		return ;
	i = 0;
	len = ft_strlen_no_spaces(*line);
	new = calloc(len + 1, sizeof(char));
	if (!new)
		return ;
	while ((*line)[i] == ' ')
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
		if ((*line)[v.i] == ' ')
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
	new = calloc(count_chars_one_space(*line) + 1, sizeof(char));
	if (!new)
		return ;
	only_one_space(line, &new, v);
}
