/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 03:07:53 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/22 20:23:37 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_in(t_redir *redir)
{
	int	fd;

	fd = open(redir->content, O_RDONLY);
	if (fd < 0)
		return (perror(redir->content), 1); // se content = 'file.txt' o output tipico é file.txt: No such file or directory
	if (dup2(fd, STDIN_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

int	redir_out(t_redir *redir)
{
	int	fd;
	
	fd = open(redir->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror(redir->content), 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

int	redir_append(t_redir *redir)
{
	int	fd;
	
	fd = open(redir->content, O_WRONLY | O_CREAT |  O_APPEND, 0644);
	if (fd < 0)
		return (perror(redir->content), 1); // se content = 'file.txt' o output tipico é file.txt: No such file or directory
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(fd), perror("dup2"), 1);
	close(fd);
	return (0);
}

int	redir_heredoc(t_redir *redir)
{
	
}

int	apply_redirections(t_redir *redir)
{
	while (redir)
	{
		if (redir->type == REDIR_IN)
		{
			if (redir_in(redir) != 0)
				return (1);
		}
		else if (redir->type == REDIR_OUT)
		{
			if (redir_out(redir) != 0)
				return (1);
		}
		else if (redir->type == REDIR_OUT2)
		{
			if (redir_append(redir) != 0)
				return (1);
		}
/* 			if (redir->type == REDIR_IN2)
			{
				
			} */
		redir = redir->next;
	}
	return (0);
}