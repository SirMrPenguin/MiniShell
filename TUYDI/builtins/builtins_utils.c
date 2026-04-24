/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:26:16 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/15 02:35:19 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_strings(char **array)
{
    int i;

    i = 0;
    if (!array)
        return (0);
    while (array[i])
	{
        i++;
	}
	return (i);
}
