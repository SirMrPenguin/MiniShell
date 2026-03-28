/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:35:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/28 03:52:33 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void trim_spaces(char *line)
{
	int i;
	int j;
	int n;
	int len;
	char *new;

	i = 0;
	len = ft_strlen_no_spaces(line);
	new = calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (line[i] == SPACE)
		i++;
	n = len + i;
	j = 0;
	while (i < n)
		new[j++] = line[i++];
	free(line);
	*line = new;
}

void only_one_space()
{
	
}

	char *remove_extra_spaces(char **line)
{
	t_var *var;
	bool in_space;

	init_var(var);
	in_space = false;
	var->new = calloc(count_chars(*line) + 1, sizeof(char));
	if (!var->new)
		return (NULL);
	trim_spaces(line);
	only_one_space(line);

	while (line[var->i])
	{
		if (line[var->i] == SPACE)
		{
			if (in_space)
				var->i++;
			continue;
		}
		else if ()
			var->new[var->j++] = line[var->i++];
	}

	free(*line);
	return (var->new);
}
