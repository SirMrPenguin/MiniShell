/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:22:04 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/31 02:34:06 by anisabel         ###   ########.fr       */
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

bool	space_between_redir(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] != '<' && line[i] != '>')
			i++;
		if (!line[i])
			break;
		while (line[i] == '<' || line[i] == '>')
			i++;
		while (line[i] == SPACE)
			i++;
		if (line[i] == '<' || line[i] == '>')
		{
			if (line[i] == '<')
				// msg de erro - syntax error near unexpected token `<'
			else
				// msg de erro - syntax error near unexpected token '>'
			return (false);
		}		
	}
	return (true);
}


bool	check_redirections(char **line)
{
	int	len;

	len = ft_strlen(line);
	if (is_all_redir(*line))
		return (false);
	if ((*line)[len - 1] == '<' || (*line)[len - 1] == '>')
	{
		//print erro (syntax error near unexpected token `newline');
		return (false);
	}
	if (space_between_redir(*line))
		return (false);
	
	



	mais redir do que << ou >>

	redirs sem conteúdo entre eles
	



	
}