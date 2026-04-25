/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:58:11 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/25 03:08:46 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Executa um único comando; se for builtin, executa em parent, 
os restantes executa num child
*/
int	execute_single_command(t_commands *cmd, t_env **env)
{
	pid_t	pid;
	int		status;
	
	if (!cmd || !cmd->arg || !cmd->arg[0])
		return (0);
	
	if (is_builtin(cmd->arg[0]) && is_parent_builtin(cmd->arg[0]))
		return (execute_builtin_parent(cmd, env));
	pid = fork();
	if (pid < 0)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		setup_child_signals();
		
		if (apply_redirections(cmd->redir))
			exit(1);
		if (is_builtin(cmd->arg[0]))
			return (execute_builtin_child(cmd, env));
		execute_external(cmd, *env);
		exit (0);
	}
	waitpid(pid, &status, 0);
	return (exit_status(status));
}
// executa builtin no parent
int	execute_builtin_parent(t_commands *cmd, t_env **env)
{
	int	saved_in;
	int	saved_out;
	int	status;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);

	if (saved_in < 0 || saved_out < 0)
		return (1);
	if (apply_redirections(cmd->redir))
	{
		dup2(saved_in, STDIN_FILENO);
		dup2(saved_out, STDOUT_FILENO);
		close(saved_in);
		close(saved_out);
		return (1);
	}
	status = builtin_in_parent(cmd, env);
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
	
	return (status);
}

int	execute_builtin_child(t_commands *cmd, t_env **env)
{
	int status;

	status = builtin_dispatch(cmd, env);
	exit (status);
}



/* int	wait_all(pid_t last_pid)
{
	int	status;
	int	last_status;
	int	exit_code;
	pid_t	pid;

	exit_code = 0;
	last_status = 0;
	while ((pid = wait(&status)) > 0)
	{
		if (pid == last_pid)
			last_status = status;
	}
	if (WIFEXITED(status))
		exit_code = (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit_code = (128 + WTERMSIG(status));
	return (exit_code);
} */