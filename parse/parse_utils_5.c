/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 04:17:56 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/17 05:14:42 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(t_token *token)
{
	int		counter;
	t_token	*tmp;

	counter = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == WORD)
			counter++;
		if (is_redir_type(tmp))
			tmp = tmp->next;
		tmp = tmp->next;			
	}
	return (counter);
}

void	build_argv(t_commands *command)
{
	t_token		*tmp;

	command->arg = NULL;
	command->arg = calloc(count_args(tmp) + 1, sizeof(char*));
	if (!command->arg)
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
		if (is_redir_type(tmp->type))
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


