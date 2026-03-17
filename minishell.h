/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:05 by joabotel          #+#    #+#             */
/*   Updated: 2026/03/15 22:27:40 by anisabel         ###   ########.fr       */
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
	bool	redir_error;
	
		
} t_env;


void	minishell(char **envp);

t_env env_init(char **envp)
{
	t_env	env;

	env.status = 0;
	env.redir_error = 0;
	
	if (!envp)
	{
		env.env = create_env();
		return (env);
	}
	else
		env.env = copy_envp(envp);
	return (env);
}



// BUILTINS

int		echo(t_jobs *job);
int		pwd(void);
void	cd(t_jobs *job, t_env *env);

int		count_strings(char **array);
int		ft_len_till_equal(char *str);
bool	ft_is_env_var_valid(char	*str);
//void	print_array(char **array);

// free

void	free_array(char **array);

//env
char	*ft_get_env(char *str, char	**env);
t_env	env_init(char **envp);
char	**copy_env(char **envp);
char	**create_env(void);

#endif