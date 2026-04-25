/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:58:25 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/25 03:12:01 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_multiple_commands(t_commands *cmd, t_env **env)
{
    int     fd[2];
	int		prev_fd;
	int		status;
    pid_t   pid;
	pid_t	last_pid;
	
	prev_fd = -1;
	last_pid = -1;
    while(cmd)
    {
        if (cmd->next && pipe(fd) < 0)
			return (perror("pipe"), 1);
        pid = fork();
        if (pid < 0)
            return (perror("fork"), 1);
        if (pid == 0)
            execute_child(cmd, env, prev_fd, fd);
		last_pid = pid;
		if (prev_fd != -1)
			close(prev_fd);	
		if(cmd->next)
		{
			close (fd[1]); 
			prev_fd = fd[0];
		}
		cmd = cmd->next;
    }
	if (prev_fd != -1)
		close(prev_fd);	
	
	setup_exec_signals();
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0);
	restore_main_signals();
	return (exit_status(status));
}

void execute_child(t_commands *cmd, t_env *env, int prev_fd, int fd[2])
{
    setup_child_signals();
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
	if (apply_redirections(cmd->redir))
		exit(1);

	if (is_builtin(cmd->arg[0]))
		exit (execute_builtin_child(cmd, env));

	execute_external(cmd, env);
    
	exit(0);
}

int	execute_external(t_commands *cmd, t_env *env) // core tudo o que nao seja builtin
{
	char	**envp;
	char	*path;

	envp = create_env_array(env);
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






