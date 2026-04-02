/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:55:03 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/01 23:49:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	closed_quotes(char *line)
{
	int	i;
	bool	in_sq;
	bool	in_dq;
	

	i = 0;
	in_sq = false;
	in_dq = false;
	while (line[i])
	{
		if (line[i] == DQ && !in_sq)
			in_dq = !in_dq;
		else if (line[i] == SQ && !in_dq)
			in_sq = !in_sq;
		i++;
	}
	if (in_dq || in_sq)
	{
		ft_printf_fd(2, "Unclosed quotes\n");
		return (false);
	}
	return (true);
}

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
			in_dq = !in_dq;
		else if (str[i] == SQ && !in_dq)
			in_sq = !in_sq;
		i++;
	}
	if (in_sq || in_dq)
		return (true);
	return (false);
}
