/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 01:50:48 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/07 11:08:58 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_quotes(char c, t_quote_status *status)
{
	if (c == SQ && !status->in_dq)
		status->in_sq = !status->in_sq;
	if (c == DQ && !status->in_sq)
		status->in_dq = !status->in_dq;
}

t_token *read_redirection_token (char *cmd, int *i)
{
	if (cmd[*i] == '<')
	{
		while (cmd[*i] == '<')
			(*i)++;
	}
	else if (cmd[*i] == '>')
	{
		while (cmd[*i] == '>')
			(*i)++;
	}
	
}

t_token	*create_token(char	*str, int type)
{
	t_token	*token;
	
	if (!str)
		return (NULL);
	token = calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = str;
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*read_word_token(t_token **head, char	*cmd, int *i)
{
	int				begin;
	int				end;
	char			*str;
	t_type			type;
	t_quote_status	*status;

	status->in_dq = false;
	status->in_sq = false;
	begin = *i;
	while (cmd[*i]) // incrementa até chegar a um stop, inclusive
	{
		if (!status->in_dq && !status->in_sq && 
				(cmd[*i] == 32 || cmd[*i] == '<' || cmd[*i] == '>'))
			break;
		update_quotes(cmd[*i], status);	
		(*i)++;
	}
	end = *i;
	str = ft_substr(cmd, begin, end - begin);
	if (!str)
		return (NULL);
	return (create_token(str, WORD)); // create_token("ls", WORD); não pode ser feito, pois ls nao é uma strig alocada na heap
}

