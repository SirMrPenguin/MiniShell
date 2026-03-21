/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 02:13:27 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/21 03:15:17 by anisabel         ###   ########.fr       */
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
	//t_env	*current;
	
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