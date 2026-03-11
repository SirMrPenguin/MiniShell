/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 03:43:03 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/11 04:04:40 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	parse_export(char **job, char **env)
{
	if (!*job || !job || !*env || !env)
		return (false);
	
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