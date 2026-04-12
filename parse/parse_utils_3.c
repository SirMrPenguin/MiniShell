/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 01:50:48 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/10 14:19:35 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*create_token(char	*str, int type)
{
	t_token	*token;
	
	if (!str)
		return (NULL);
	token = calloc(1, sizeof(t_token));
	if (!token)
	{
		free(str);	// fica com ownership da string
		return (NULL);
	}
	token->content = str;
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*create_redir_token(char *redir)
{
	if (redir[0] == '>')
	{
		if (redir[1])
			return (create_token(redir, REDIR_OUT2));
		return (create_token(redir, REDIR_OUT));
	}
	else if (redir[0] == '<')
	{
		if (redir[1])
			return (create_token(redir, REDIR_IN2));
		return (create_token(redir, REDIR_IN));
	}
	return (NULL);
}

t_token *read_redirection_token (char *cmd, int *i)
{
	int				begin;
	int				end;
	char			*str;
	t_type			type;
	
	begin = *i;
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
	end = *i;
	str = ft_substr(cmd, begin, end - begin);
	if (!str)
		return (NULL);
	return (create_redir_token(str)); 

}

t_token	*read_word_token(char	*cmd, int *i)
{
	int				begin;
	int				end;
	char			*str;
	t_type			type;
	t_quote_status	status;

	status.in_dq = false;
	status.in_sq = false;
	begin = *i;
	while (cmd[*i]) // incrementa até chegar a um stop, inclusive
	{
		if (!status.in_dq && !status.in_sq && 
				(cmd[*i] == 32 || cmd[*i] == '<' || cmd[*i] == '>'))
			break;
		update_quotes(cmd[*i], &status);	
		(*i)++;
	}
	end = *i; // a contar com o delimiter ou fim da string
	str = ft_substr(cmd, begin, end - begin);
	if (!str)
		return (NULL);
	return (create_token(str, WORD)); 
	// create_token("ls", WORD); não pode ser feito, pois ls nao é uma strig alocada na heap
}
// retorna um token

void	add_token(t_token **list, t_token *new_token)
{
	t_token	*tmp;

	if (!*list)
	{
		*list = new_token;
		return ;
	}
	tmp = *list;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
}
