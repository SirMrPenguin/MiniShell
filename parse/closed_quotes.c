/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:55:03 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/25 19:52:15 by anisabel         ###   ########.fr       */
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