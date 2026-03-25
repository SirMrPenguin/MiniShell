/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:10:32 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/25 19:33:08 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_env(t_env **env, char **envp)
{
	*env = NULL;

	if (!envp || !envp[0]) // criar env a partir do sistema
	{
		if (!create_env(env)) // alterar create_new para ja dar free e anular o ponteiro internamente
			*env = NULL;
	}
	else if (!copy_env(env, envp))
	{
		clear_env(*env);
		*env = NULL;
	}
	
}

int	add_var_to_env(t_env **env, char *key, char *value, int visible)
{
	t_env	*new_node;

	new_node = new_env_node(key, value, visible);
	if (!new_node)
		return (0);
	add_to_env(env, new_node);
	return (1);
}

int create_env(t_env **env)
{
	char temp[PATH_SIZE];
	char *cwd;

	*env = NULL;
	cwd = getcwd(temp, PATH_SIZE);
	if (cwd && !add_var_to_env(env, "PWD", cwd, 1)) // pq n ao !cwd
		return (clear_env(*env), 0);
	if (!add_var_to_env(env, "SHLVL", "1", 1))
		return (clear_env(*env), 0);
	if (!add_var_to_env(env, "_", "/usr/bin/env", 1))
		return (clear_env(*env), 0);
	if (!add_var_to_env(env, "PATH",
			"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", 1))
		return (clear_env(*env), 0);
	return (1);
}

int	copy_env(t_env **env, char	**envp)
{
	int	i;
	int	equal_len;
	char	*key;
	char	*value;
	
	i = 0;
	while (envp[i])
	{
		equal_len = ft_len_till_equal(envp[i]);
		key = ft_substr(envp[i], 0, equal_len);
		if (!key)
			return (0);
		value = NULL;
		if (envp[i][equal_len] == '=')
			value = envp[i] + equal_len + 1;
		if (!add_var_to_env(env, key, value, 1))
			return (free(key), 0);
		free(key);
		i++;
	}
	return (1);
}
