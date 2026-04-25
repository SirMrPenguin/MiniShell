/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:11:45 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/25 02:13:18 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);

	if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	
	if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	
	if (ft_strcmp(cmd, "export") == 0)
		return (true);

	if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	
	if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	return (false);
}

bool is_parent_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	if (ft_strcmp(cmd, "export") == 0)
		return (true);
	if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}

// verifica qual builtin e executa
int	builtin_dispatch(t_commands *cmd, t_env **env)
{
	if (ft_strcmp(cmd->arg[0], "cd") == 0)
		return (builtin_cd(cmd, env));
	if (ft_strcmp(cmd->arg[0], "echo") == 0)
		return (builtin_echo(cmd, env));
	if (ft_strcmp(cmd->arg[0], "exit") == 0)
		return (builtin_exit(cmd, env));
	if (ft_strcmp(cmd->arg[0], "export") == 0)
		return (builtin_export(cmd, env));
	if (ft_strcmp(cmd->arg[0], "pwd") == 0)
		return (builtin_pwd(cmd, env));
	if (ft_strcmp(cmd->arg[0], "unset") == 0)
		return (builtin_unset(cmd, env));
	return (1);
}