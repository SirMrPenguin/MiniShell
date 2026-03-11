/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:05 by joabotel          #+#    #+#             */
/*   Updated: 2026/03/11 00:39:54 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PATH_SIZE 4096

typedef struct s_jobs
{
	int				type;
	char			**job;
	struct s_jobs	*next;
} t_jobs;

typedef struct s_env
{
	char	**env;
	int		status;
		
} t_env;

// BUILTINS

int	echo(t_jobs *job);
int	pwd(void);
void	cd(t_jobs *job, t_env *env);

int count_strings(char **array);

//env
char	*ft_get_env(char *str, char	**env);

#endif