/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 02:41:52 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/11 03:40:13 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_utils(char **target, char **env)
{
	int	i;
	int j;

	i = 0;
	while (target[i])
	{
		j = 0;
		while (env[j] && env && ft_strncmp(target[i], env[j], ft_strlen(target[i])))
			j++;
		if (!env[j])
			return ;
		free(env[j]);
		while (env[j])
		{
			env[j] = env[j + 1];
			j++;
		}
		// free (env[j + 1]) ???? 
		i++;
	}
}

int unset(t_jobs *job, t_env *env)
{
	if (!job->job[1])
		return (0);
	unset_utils(job->job + 1, env->env);
	return (0);
}
