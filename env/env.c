/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:10:32 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/15 23:40:46 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**create_env(void)
{
	char	**new_env;
	char	*path;
	char	temp[PATH_SIZE];

	new_env = calloc(3, sizeof(char *));
	if (!new_env)
		return (ft_printf_fd(2, "Error allocating env\n"), NULL);
	path = "PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:/snap/bin:";
	new_env[0] = ft_strdup(path);
	if (!new_env[0])
		return (ft_printf_fd(2, "Error allocating PATH\n"), free_array(new_env), NULL);
	if (!getcwd(temp, PATH_SIZE))
		return (ft_printf_fd(2, "Error getting cwd\n"), free_array(new_env), NULL); //free_array?
	new_env[1] = ft_strjoin("PWD=", temp);
	if (!new_env[1])
		return (ft_printf_fd(2, "Error allocating cwd\n"), free_array(new_env), NULL);
	return (new_env);
}

char **copy_env(char **envp)
{
	int		i;
	char	**new_env;
	char	*shlevel;

	new_env = calloc(count_strings(envp) + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHLVL=", 6) == 0) // char para int, somar 1 e passar para char de novo
		{
			shlevel = ft_itoa(ft_atoi(envp[i] + 6) + 1);
			new_env[i] = ft_strjoin("SHLVL=", shlevel);
			if (!new_env[i])
				return (free_array(new_env), NULL);
			free(shlevel);
		}
		else
			new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
			return (free_array(new_env), NULL);
		i++;
	}
	return (new_env);
}

t_env env_init(char **envp)
{
	t_env	env;

	env.status = 0;
	env.redir_error = 0;
	
	if (!envp)
	{
		env.env = create_env();
		return (env);
	}
	else
		env.env = copy_envp(envp);
	return (env);
}

static char	*ft_copy_path(char *str)
{
	int		i;
	int		j;
	char	*path;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_len_till_equal(str);
	path = malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (!path)
		return (NULL);
	while (str[j + i])
	{
		path[i] = str[j + i];
		i++;
	}
	path[i] = '\0';
	return (path);
}

char	*ft_get_env(char *str, char	**env)
{
	int		i;
	char	*path;
	
	if (!env || !*env || !str || !*str)
		return NULL;
	i = 0;
	while (env[i])
	{
		/* temp = ft_strndup(env[i], ft_len_of_var(env[i])); // dup env[i] if (ft_strncmp(env[i], str, ft_strlen(str)) == 0 && env[i][ft_strlen(str)] == '=')
		if (!temp)
			return (NULL); */
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0 && env[i][ft_strlen(str)] == '=') // enconttou home no env
		{
			path = ft_copy_path(env[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
