/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 03:08:36 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/25 01:46:10 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	envp_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->visible == 1)
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

char	*join_path(char *path, char *command)
{
	char	*full;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, command);
	if (!full)
		return (free(tmp), NULL);
	free(tmp);
	return (full);
}

char	*find_path(char **paths, char *command)
{
	int	i;
	char	*command_path;
	
	i = 0;
	while (paths[i])
	{
		command_path = join_path(paths[i], command);
		if (!command_path)
			return(NULL);
		if (check_access(command_path))
			return (command_path);
		free(command_path);
		i++;
	}
	return (NULL);
}

bool	check_access(char *command_path)
{
	if (access(command_path, X_OK) == 0)
		return (true);
	return (false);
}


char	*get_command_path(char *command, t_env *env)
{
	char	**paths;
	char	*command_path;
	
	if (!command)
		return (NULL);
	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		return (NULL);
	}
	while (env && ft_strncmp("PATH", env->key, 4) != 0)
		env = env->next;
	if (!env || !env->value)
		return (NULL);
	paths = ft_split(env->value, ":");
	if (!paths)
		return (NULL);
	command_path = find_path(paths,command);
	if (!command_path)
		return (free_array(paths), NULL);
	return (free_array(paths), command_path);
}