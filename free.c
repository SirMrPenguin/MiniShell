/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 02:13:27 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/09 19:58:40 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **array)
{
	int	i;
	
	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

void	clear_env(t_env *env)
{
	t_env	*temp;
	
	if (!env)
		return ;	
	while (env)
	{
		temp = env->next;
		free(env->key);
		free(env->value);
		free (env);
		env = temp;
	}
}

void	free_tokens(t_token **token)
{
	t_token	*current;
	
	while (*token)
	{
		current = (*token)->next;
		free((*token)->content);
		free(*token);
	    *token = current; 
		// no fim, o pointer q originalmente apontava para a head da lista, passa a ser NULL (dangling pointer)
	}
}