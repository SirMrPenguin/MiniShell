/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:22:04 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/28 02:51:58 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_all_redir(char *line)
{
	int		i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] != SPACE)
		{
			if (line[i] != '<' && line[i] != '>')
				return (false);
		}
		i++;
	}
	return (true);
}



bool	check_redirections(char **line)
{
	if (is_all_redir(*line))
	{
		
	}



	
	se a string nao é apenas redir

	se existem no inicio e no fim 

	mais redir do que << ou >>

	redirs sem conteúdo entre eles
	



	
}