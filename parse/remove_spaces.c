/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:35:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/28 00:39:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strlen_no_spaces(char *str)
{
	int	i;
	int j;

	i = 0;
	while(str[i] && str[i] == SPACE) // verificar se é preciso str[i]
		i++;
	j = ft_strlen(str) - 1;
	while (str[j] == SPACE && j >= i)
		j--;
	if (j < i)
		return (0);
	return (j - i + 1);
}

char	*remove_spaces(char *line)
{
	int		i;
	int		j;
	int		n;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen_no_spaces(line);
	new = calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (line[i] == SPACE)
		i++;
	n = len + i;
	j = 0;
	while (i < n)
		new[j++] = line[i++];
	free(line);
	return (new);
}