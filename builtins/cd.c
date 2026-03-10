/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:08:54 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/09 02:34:28 by anisabel         ###   ########.fr       */
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
	
	getcwd(temp, PATH_SIZE);
	if (!temp)
		return (ft_printf_fd(2, "minishell: getcwd() error \n"), NULL);
	cwd = ft_strdup(temp);
	if (!temp)
		return (NULL);
	return (temp);
}


void	cd(t_jobs *job, t_env *env)
{
	char	*cwd; // guardar o pwd para que vai mudar
	char	*old_wd; //vai guardar o dir atual antes de chdir

	if (job->job[1] && job->job[2])
		return (cd_error(ft_strdup("too many arguments"), NULL, NULL, env));
	old_wd = ft_get_cwd();
	if (!job->job[1])
	{
		cwd = ft_get_env("HOME", env->env);
		if (chdir(cwd))
			return (cd_error(ft_strdup("No such file or directory"), 
				cwd, old_wd, env));
	}
	else
	{
		cwd = ft_strdup(job->job[1]);
		if (chdir(cwd))
			return (cd_error(ft_strdup("No such file or directory"), 
				cwd, old_wd, env));
	}
	atualizar oldpwd e pwd no env

	libertar o que for necessário e retornar

}