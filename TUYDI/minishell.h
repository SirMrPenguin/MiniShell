/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:05 by joabotel          #+#    #+#             */
/*   Updated: 2026/04/24 15:46:35 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft_updated/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>

#define PATH_SIZE 4096
#define DQ 34
#define SQ 39
// # define SPACE 32    erro com define de readline (?)

typedef enum s_type
{
	// PIPE,
	WORD,		// ls, grep, cat
	OPTION,		// -n, -l
	FILES,		// file.txt
	REDIR_IN,	// <
	REDIR_IN2,	// << heredoc
	REDIR_OUT,	// >
	REDIR_OUT2, // >>
	ERROR,		// token invalido ou erro de parsing
	MAIN,		// processo principal
	CHILD,		// processo filho
	PIPE,		//
	HERE_DOC,	// <<
	IGNORE		// tokens a ser ignorados = espaços, strings vazias, quotes tratadas (???)
} t_type;

typedef struct s_token
{
	char *content;
	t_type type;
	t_token *next;
} t_token;

typedef struct s_commands
{
	char **arg;
	t_env *env;
	t_token *token;
	t_redir *redir;
	t_commands *next;
} t_commands;

typedef struct s_redir
{
	int type;
	char *content;
	t_redir *next;
} t_redir;

typedef struct s_env
{
	char *key;
	char *value;
	int visible;
	t_env *next;
} t_env; // atualizar init_var ao adicionar variáveis

typedef struct s_var
{
	int i;
	int j;
	int begin;
	int end;
	int len;
	char *new;
} t_var;

typedef struct s_quote_status
{
	bool in_sq;
	bool in_dq;
} t_quote_status;

void minishell(char **envp);

// BUILTINS

int count_strings(char **array);
int ft_len_till_equal(char *str);

/*bool	ft_is_env_var_valid(char	*str); */
// void	print_array(char **array);

// free

void free_array(char **array);
void clear_env(t_env *env);
void free_tokens(t_token **token);

// env
void init_env(t_env **env, char **envp);
int add_var_to_env(t_env **env, char *key, char *value, int visible);
int create_env(t_env **env);
int copy_env(t_env **env, char **envp);
t_env *new_env_node(char *key, char *value, int visible);
void add_to_env(t_env **env, t_env *new_node); // adiciona um node no fim da linked list

// parse

bool parse(char *command_line, t_env *env, t_commands **commands);
bool check_input(char **line, t_env *env);

bool closed_quotes(char *line);

void tab_to_space(char *line);
bool is_in_quotes(char *str, int pos);
void update_quotes(char c, t_quote_status *status);

bool empty_line(char *line);

void remove_extra_spaces(char **line);
void only_one_space(char **line, char **new, t_var v, t_quote_status status);
void trim_spaces(char **line);

int ft_strlen_no_spaces(char *str);
int count_chars_one_space(char *line);
void init_var(t_var *var); // remover se nunca for usado

bool check_redirections_pipes(char *line);
bool is_all_redir(char *line);
bool is_all_pipe(char *line);

t_commands *create_command_list(char *cmd, t_env *env);
char **split_commands(char *line);
int count_pipes(char *line); // conta pipes fora de aspas
// int			count_char (int begin, int end); // conta char entre 2 pos
void copy_command(char *array, char *line, int begin, int len);
int copy_command_array(char *line, char **command_array, t_var v);
bool has_content(char *line, int begin, int end);

t_commands *create_command(char *cmd, t_env *env);
t_token *tokenize_command(char *cmd);

void update_quotes(char c, t_quote_status *status);
t_token *read_word_token(char *cmd, int *i);
t_token *create_token(char *str, int type);
void add_token(t_token **list, t_token *new_token);

bool validate_tokens(t_token *token);
bool build_redir(t_commands *command);
void add_redir(t_redir *list, t_redir *new);
t_redir *new_redir(t_type type, char *content);
bool is_redir_type(t_token *token);
bool build_argv(t_commands *command);
bool add_word_to_argv(char **argv, char *word, int *i);
t_token *skip_redir_and_target(t_token *tmp);
int count_args(t_token *token);


// executor


int		apply_redirections(t_redir *redir);
int		redir_append(t_redir *redir);
int		redir_out(t_redir *redir);
int		redir_in(t_redir *redir);
int		redir_heredoc(t_redir *redir); //!!!!!!!!!!!!

int		envp_size(t_env *env);
char	*join_env(t_env *env);
char	**create_env_array(t_env	*env);

char	*join_path(char *path, char *command);
char	*find_path(char **paths, char** argv);
bool	check_access(char *command_path);
char	*get_command_path(char **argv, char *command, t_env *env);

int		is_builtin(char *cmd);
void    handler_sigint(int  signal);
void    setup_child_signals(void);
void    setup_signals(void);
int		exit_status(int status);


#endif