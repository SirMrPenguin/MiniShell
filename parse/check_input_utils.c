/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:22:04 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/02 03:41:31 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_all_redir(char *line)
{
	int		i;
	bool	has_redir;
	
	i = 0;
	has_redir = false;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] != '<' && line[i] != '>')
				return (false);
			has_redir = true;
		}
		i++;
	}
	if (has_redir)
	{
		// syntax error near unexpected token `newline'
		return (true);
	}
	return (false);
}

bool	is_all_pipe(char *line)
{
	int		i;
	bool	has_pipe;
	
	i = 0;
	has_pipe = false;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] != '|')
				return (false);
			has_pipe = true;
		}
		i++;
	}
	if (has_pipe)
	{
		// syntax error near unexpected token '|'
		return (true);
	}
	return (false);
}

bool	is_redir_valid(char *line)
{
	int	i;

	i = 0;
	if ((line[i] == '>' || line[i] == '<') && (line[i + 1] == '>' || line[i + 1] == '<') && (line[i + 2] == '>' | line[i + 2] == '<'))
		return (false);
	else if ((line[i] == '>' && line [i + 1] == '<') || (line[i] == '<' && line [i + 1] == '>'))
		return (false);
	else if ((line[i] == '>' ||line [i + 1] == '<') && line[i] == '|')
		return (false);
	return (true);
}

bool	check_redirections_pipes(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (is_all_redir(line)) // printa erro
		return (false);
	if (is_all_pipe(line))
		return (false);
	if (line[len - 1] == '<' || line[len - 1] == '>' || line[len - 1] == '|' || line[0] == '|')
	{
		//print erro (syntax error near unexpected token `newline');
		return (false);
	}
	if (!is_redir_valid(line))
		return (false);
	return (true);
}
