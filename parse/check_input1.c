/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:22:04 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/10 23:05:44 by anisabel         ###   ########.fr       */
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
		if (!is_in_quotes(line, i) && line[i] != ' ')
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
		if (!is_in_quotes(line, i) && line[i] != ' ')
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

bool	is_pipe_valid(char *line, int i, int count)
{
	if (line[i + count] && line[i + count] == '|' 
			&& !is_in_quotes(line, i + count))
		return (false);
	if (i > 0 &&  line[i - 1] == '|' 
			&& !is_in_quotes(line, i - 1)) // i > 0, ou seja nao 
		return(false);
	return (true);
}

bool	is_redir_valid(char *line)
{
	int	i;
	int	count;

	i = 0;
	while (line [i])
	{
		if (is_in_quotes(line, i))
			i++;
		else if (line[i] == '>' || line[i] == '<')
		{
			count = 1;
			while (line[i + count] && line[i + count] == line[i] 
					&& !is_in_quotes(line, i + count))
				count++;
			if (count > 2 || !is_pipe_valid(line, i, count))
				return (false);
			if (line[i + count] && (line[i + count] == '>' || line[i + count] == '<')
					&& !is_in_quotes(line, i + count))
				return (false);
			i += count;
		}
		else
			i++;
	}
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
	if (line[len - 1] == '|' || line[0] == '|')
	{ // verificar quais tirar depois line[len - 1] == '<' || line[len - 1] == '>' ||
		//print erro (syntax error near unexpected token `newline');
		return (false);
	}
	if (!is_redir_valid(line))
		return (false);
	return (true);
}

void	tab_to_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' && !is_in_quotes(line, i))
			line[i] = ' ';
		i++;
	}
}