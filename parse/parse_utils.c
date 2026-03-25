/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:46:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/25 20:32:26 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_in_quotes(char *str, int pos)
{
	int	i;
	bool	in_sq;
	bool	in_dq;

	i = 0;
	in_sq = false;
	in_dq = false;
	while (i < pos)
	{
		if (str[i] == DQ && !in_sq)
			in_dq = true;
		else if (str[i] == SQ && !in_dq)
			in_sq = true;
			i++;
	}
	if (in_sq || in_dq)
		return (true);
	return (false);
}

void	remove_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '/t' && !is_in_quotes(line, i))
			line[i] = ' ';
		i++;
	}
}

v
