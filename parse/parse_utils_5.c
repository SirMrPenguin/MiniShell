/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 04:17:56 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/18 23:06:49 by anisabel         ###   ########.fr       */
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
		if (is_redir_type(tmp))
		{
			tmp = tmp->next;
			if (tmp)
				tmp = tmp->next;
		}
		else
		{
			if (tmp->type == WORD)
				counter++;
			tmp = tmp->next;			
		} 
	}
	return (counter);
}

t_token	*skip_redir_and_target(t_token *tmp)
{
	if (!tmp)
		return (NULL);
	tmp = tmp->next;
	if (tmp)
		tmp = tmp->next;
	return (tmp);
}

bool	add_word_to_argv(char **argv, char *word, int *i)
{
	argv[*i] = ft_strdup(word);
	if (!argv[*i])
		return (false);
	(*i)++;
	return (true);
}

bool	build_argv(t_commands *command)
{
	int	i;
	t_token		*tmp;

	i = 0;
	tmp = command->token;
	command->arg = calloc(count_args(tmp) + 1, sizeof(char*));
	if (!command->arg)
		return (false);
	while (tmp)
	{
		if (is_redir_type(tmp))
			tmp = skip_redir_and_target(tmp);
		else
		{
			if (tmp->type == WORD && !add_word_to_argv(command->arg, tmp->content, &i))
				return (free_argv(), false);// funcao free do argv ja construido ;; !!! dangling pointers
			tmp = tmp->next;
		}
	}
	command->arg[i] = NULL;
	return (true);
}




