/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:05 by joabotel          #+#    #+#             */
/*   Updated: 2026/03/28 00:50:22 by anisabel         ###   ########.fr       */
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
# define DQ 34
# define SQ 39
# define SPACE 32

typedef struct s_jobs
{
	int				type;
	char			**job;
	struct s_jobs	*next;
} t_jobs;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		visible;
	t_env	*next;	
} t_env;


void	minishell(char **envp);

// BUILTINS



int		count_strings(char **array);
int		ft_len_till_equal(char *str);

/*bool	ft_is_env_var_valid(char	*str); */
//void	print_array(char **array);

// free

void	free_array(char **array);
void	clear_env(t_env *env);


//env
void	init_env(t_env **env, char **envp);
int		add_var_to_env(t_env **env, char *key, char *value, int visible);
int		create_env(t_env **env);
int		copy_env(t_env **env, char	**envp);
t_env	*new_env_node(char *key, char *value, int visible);
void	add_to_env(t_env **env, t_env *new_node); // adiciona um node no fim da linked list

// parse

int		parse(char *command_line, char **env);
bool	check_input(char **line, t_env   *env);

bool	closed_quotes(char *line);

void	tab_to_space(char *line);
bool	is_in_quotes(char *str, int pos);

bool	empty_line(char *line);

char	*remove_spaces(char *line);
int		ft_strlen_no_spaces(char *str);



#endif