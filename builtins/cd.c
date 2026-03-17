/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:08:54 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/12 02:11:25 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	cd_error(char *str, char *cwd, char *oldpwd, t_env *env)
{
	if (str)
	{
		ft_printf_fd(2, "minishell: cd: %s", str);
		free(str);
	}
	if(cwd)
		free(cwd);
	if(oldpwd)
		free(oldpwd);
	env->status = 1;
}

static char	*ft_get_cwd(void)
{
	char	temp[PATH_SIZE];
	char	*cwd;
	
	if (!getcwd(temp, PATH_SIZE))
		return (ft_printf_fd(2, "minishell: getcwd() error \n"), NULL);
	cwd = ft_strdup(temp);
	if (!cwd)
		return (NULL);
	return (cwd);
}

char	**add_to_env(char **env)
{
	int		i;
	char	**new_env;

	if (!new_env || !env || !env[0])
		return (NULL);
	i = 0;
	new_env = calloc(count_strings(env) + 2, sizeof(char *));
	if (!new_env)
		reuturn (NULL);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			i = 0;
			while (new_env[i])
				free (new_env[i++]);
			free(new_env);
			return (NULL);	
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

static void	update_wd(t_env *env, char *prefix, char *path) // corrrigir, a partir de getcwd
{
	int		i;
	char	dir[PATH_SIZE];
	char	*new_var;

	i = 0;
	while (env->env[i])
	{
		if (ft_strncmp(env->env[i], prefix, ft_strlen(prefix)) == 0)
			break ;
		i++;
	}
	if (!env->env[i])
	{
		env->env = add_to_env(env->env);
		if (!env->env)
			return ;
	}
	if (!path)
		path = getcwd(dir, PATH_SIZE);
	if (!path)
		return (free(new_var));
	new_var = ft_strjoin(prefix, path);
	free (env->env[i]);
	env->env[i] = new_var;
}

void	cd(t_jobs *job, t_env *env)
{
	char	*dir; // guardar o pwd para que vai mudar
	char	*old_dir; //vai guardar o dir atual antes de chdir

	if (job->job[1] && job->job[2])
		return (cd_error(ft_strdup("too many arguments"), NULL, NULL, env));
	old_dir = ft_get_cwd(); // guarda path atual
	if (!job->job[1])
	{
		dir = ft_get_env("HOME", env->env);
		if (chdir(dir))
			return (cd_error(ft_strdup("No such file or directory"), 
				dir, old_dir, env));
	}
	else
	{
		dir = ft_strdup(job->job[1]);
		if (chdir(dir))
			return (cd_error(ft_strdup("No such file or directory"), 
				dir, old_dir, env));
	}
	update_wd(env, "OLDPWD=", old_dir);
	update_wd(env, "PWD=", NULL);
	free(dir);
	free(old_dir);
	return ;
}
