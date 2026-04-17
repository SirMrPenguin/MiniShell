/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:08:23 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/17 05:06:34 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_redir_type(t_token *token)
{
	return (token->type == REDIR_IN || token->type == REDIR_IN2 
			|| 	token->type == REDIR_OUT || token->type == REDIR_OUT2);
}

bool	validate_tokens(t_token *token)
{
	t_token	*tmp;
	
	tmp = token;
	while (tmp)
	{
		if (is_redir_type(tmp))
		{
			if (!tmp->next || tmp->next->type != WORD)
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

t_redir	*new_redir(t_type type, char *content)
{
	t_redir *new;

	new = calloc(1, sizeof(t_redir));
	if (!new)
		return (NULL);
	new->type = type;
	new->content = ft_strdup(content);
	if (!new->content)
		return (free(new), NULL); // free do node se nao conseguir alocar o content
	new->next = NULL;
	return (new);
}

void	add_redir(t_redir **list, t_redir *new)
{
	t_redir	*tmp;

	tmp = *list;
	if (!*list)
	{
		*list = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;	
}

bool	build_redir(t_commands *command)
{
	t_token		*tmp;
	t_redir		*new;

	command->redir = NULL;
	tmp = command->token;
	while (tmp)
	{
		if (is_redir_type(tmp))
		{
			new = new_redir(tmp->type, tmp->next->content);
			if (!new)
			{
				free_redirs(); //!!!!!!!!!!!!!!
				return (false);
			}
			add_redir(&command->redir, new);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (true);
}