/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 03:08:36 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/19 03:08:55 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	envp_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->visible = 1)
			i++;
		env = env->next;
	}
	return (i);
}

char	*join_env(t_env *env)
{
	char	*tmp;
	char	*s;

	tmp = ft_strjoin(env->key, "=");
	if (!tmp)
		return (NULL);
	if (env->value)
		s = ft_strjoin(tmp, env->value);
	else
		s = ft_strjoin(tmp, "");
	if (!s)
		return (free(tmp), NULL);
	free(tmp);
	return (s);
}

char	**create_env_array(t_env	*env)
{
	int		i;
	int		size;
	char	**envp;

	i = 0;
	size = envp_size(env);
	envp = calloc(size + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	while (env)
	{
		if (env->visible)
		{
			envp[i] = join_env(env);
			if (!envp[i])
				return (free_array(envp), NULL);
			i++;
		}
		env = env->next;
	}
	envp[i] = NULL;
	return (envp);
}