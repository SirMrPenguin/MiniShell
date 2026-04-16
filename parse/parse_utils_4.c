/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:08:23 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/15 23:20:43 by anisabel         ###   ########.fr       */
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
	t_token	*curr;
	
	curr = token;
	while (curr)
	{
		if (is_redir_type(curr))
		{
			if (!curr->next || curr->next->type != WORD)
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}