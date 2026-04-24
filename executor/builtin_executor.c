/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:11:45 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/24 03:13:49 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (cmd == "cd")
		return (true);

	if (cmd == "echo")
		return (true);
	
	if (cmd == "exit")
		return (true);
	
	if (cmd == "export")
		return (true);

	if (cmd == "pwd")
		return (true);
	
	if (cmd == "unset")
		return (true);
	return (false);
}

int execute_builtin_parent(t_commands *cmd, t_env **env)
{
    
}