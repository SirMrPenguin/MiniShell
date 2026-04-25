/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:45:04 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/25 02:23:33 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_external(t_commands *cmd, t_env *env) // core tudo o que nao seja builtin
{
	char	**envp;
	char	*path;

	envp = create_env_array(cmd->env);
	if (!envp)
		exit (1); // ??????
	path = get_command_path(cmd->arg[0], env);
	if (!path)
	{
		free_array(envp);
		exit (127); // não existe
	}
	execve(path, cmd->arg, envp);
	perror("cmd->arg[0]");
	free(path);
	free_array(envp);
	exit(126); // existe mas falha
}
