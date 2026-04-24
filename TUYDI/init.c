/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 22:25:09 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/05 01:20:38 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_var(t_var *var)
{
	var->i = 0;
	var->j = 0;
	var->len = 0;
	var->new = NULL;
	var->begin = 0;
	var->end = 0;
}

void	init_token_null(t_token	*token)
{
		
}