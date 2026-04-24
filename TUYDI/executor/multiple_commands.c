/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 03:58:25 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/24 04:14:03 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_child(t_commands *cmd, t_env *env, int prev_fd, int fd)
{
    setup_child_signals();
    
}

int	execute_commands(t_commands *cmd, t_env **env)
{
    int     fd[2];
	int		prev_fd;
    pid_t   pid;
/*   
	if (!cmd || !cmd->arg || !cmd->arg[0])
		return (0); */
	prev_fd = -1;

    while (cmd)
    {
        if (cmd->next)
            pipe(fd);
        
        pid = fork();
        if (pid < 0)
            return (perror("fork"), 1);
        if (pid == 0)
            exec_child(cmd, env, prev_)
        
    }






        
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

