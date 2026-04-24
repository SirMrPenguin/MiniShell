/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:46:11 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/21 03:52:25 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_env(t_env **env, t_env *new_node)
{
	t_env	*current;

	if (!env || !new_node)
		return ;
	if (!*env)
	{
		*env = new_node;
		return ;
	}
	current = *env;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_env	*new_env_node(char *key, char *value, int visible)
{
	t_env	*new_node;

	if (!key)
		return (NULL);
	new_node = calloc(1, sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	if (!new_node->key)
		return (free(new_node), NULL);
	if (value)
	{
		new_node->value = ft_strdup(value);
		if (!new_node->value)
		{
			free(new_node->key);
			free(new_node);
			return (NULL);
		}
	}
	new_node->visible = visible;
	// new_node->next = NULL; como foi usado calloc, e redundante
	return (new_node);
}

int	ft_len_till_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	/* 	if (str[i] == '=')
	i++; */
	return (i);
}


 /*
void	print_array(char **array)
	{
		int	i;
		int	j;
		
		if (!array)
			return ;
		i = 0;
		while (array[i])
		{
			ft_putstr(array[i]);
			i++;
		}
	}  */