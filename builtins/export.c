/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 03:43:03 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/11 04:18:20 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	parse_export(char **job, char **env)
{
	int	i;
	int	j;

	if (!*job || !job || !*env || !env)
		return (false);
	i = 1;
	while (job[i])
	{	
		if (ft_isdigit(job[i][j]))
			return (false);
		j = 1;
		while (job[i][j])
		{
			if (job[i][j])
			
		}
		
	}
}


int	export(t_jobs *job, t_env *env)
{
	char **new_env;
	int				i;
	bool			flag;

	if (!job->job[1])
	{
		imprimir a lista de env;
	}

	parse_export(job->job, env->env);
}