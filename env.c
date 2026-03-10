/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 01:10:32 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/09 02:32:50 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len_of_var(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	return (i);
}

static char	*ft_copy_path(char *str)
{
	int		i;
	int		j;
	char	*path;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_len_of_var(str);
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
