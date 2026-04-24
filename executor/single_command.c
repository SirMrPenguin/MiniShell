/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:58:11 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/24 16:07:08 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_external(t_commands *command, t_env *env) // core tudo o que nao seja builtin
{
	char	**envp;
	char	*path;


	envp = create_env_array(command->env);
	if (!envp)
		exit (1); // ??????
	path = get_command_path(envp, command, env);

	if (!path)
		exit (127); // não existe
	
	execve(path, command->arg, envp);
	exit(126); // existe mas falha
}


/*
Executa um único comando; se for builtin, executa em parent, 
os restantes executa num child
*/
int	execute_single_command(t_commands *command, t_env **env)
{
	pid_t	pid;
	int		status;
	
	if (!command || !command->arg || !command->arg[0])
		return (0);
	
	if (is_builtin (command->arg[0]))
		return (execute_builtin_parent(command, env));

	pid = fork();
	if (pid < 0)
		return (perror("fork"), 1);

	if (pid == 0)
	{
		setup_child_signals();
		if (!apply_redirections(command->redir))
			exit (1); // exit pq está no child
		execute_external(command, env);
	}
	waitpid(pid, &status, 0);
	return (exit_status(status));
}

