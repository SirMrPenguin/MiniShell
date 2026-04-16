/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 23:15:18 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/15 23:21:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	has_content(char *line, int begin, int end)
{
	while (line[begin] && begin < end)
	{
		if (line[begin] != ' ')
			return (true);
		begin++;
	}
	return (false);
}

void copy_command(char *array, char *line, int begin, int len)
{
	int i;
	int j;

	i = 0;
/* 	if (line[begin] == '|') // verificar se necessario
		begin++; */
	j = begin + len;
	while (line[begin] && begin < j)
		array[i++] = line[begin++];
	array[i] = '\0';
}

int copy_command_array(char *line, char **command_array, t_var v)
{
	while (line[v.i])
	{
		v.begin = v.i;
		while ((line[v.i] && line[v.i] != '|') ||
			   (line[v.i] == '|' && is_in_quotes(line, v.i)))
			v.i++;
		v.end = v.i;
		if (!has_content(line, v.begin, v.end)) // pipes seguidos
			return (free_array(command_array), 0);
		v.len = v.end - v.begin;
		command_array[v.j] = calloc(v.len + 1, sizeof(char));
		if (!command_array[v.j])
			return (free_array(command_array), 0);

		copy_command(command_array[v.j], line, v.begin, v.len);
		v.j++;
		if (line[v.i] == '|')
			v.i++;
	}
	command_array[v.j] = NULL;
	return (1);
}

char **split_commands(char *line)
{
	t_var v;
	int pipes;
	char **command_array;

	init_var(&v);
	pipes = count_pipes(line);
	command_array = calloc(pipes + 2, sizeof(char *));
	if (!command_array)
		return (NULL);
	if (!copy_command_array(line, command_array, v))
		return (NULL);
	return (command_array);
}
// separa a linha pelos pipes (fora de aspas)

t_token *tokenize_command(char *cmd)
{
	int i;
	t_token *head;
	t_token *new_token;
	i = 0;
	head = NULL;
	while (cmd[i])
	{
		if ((cmd[i] == '<' || cmd[i] == '>') && !is_in_quotes(cmd, i))
			new_token = read_redirection_token(cmd, &i);
		else if (cmd[i] == ' ' && !is_in_quotes(cmd, i))
		{
			i++;
			continue;
		}
		else
			new_token = read_word_token(cmd, &i);
		if (!new_token)
		{
			free_tokens(&head);
			return (NULL);
		}
		add_token(&head, new_token);
	}
	return (head);
}
// criar e ligar tokens e retornar pointer para o topo dos tokens

t_commands *create_command(char *cmd, t_env *env)
{
	t_commands *command;
	t_token *head;
	t_token *current;

	command = calloc(1, sizeof(t_commands));
	if (!command)
		return (NULL);
	command->env = env;
	command->token = tokenize_command(cmd); 
	// cria lista de tokens (retorna pointer para a head da lista q vai ficar guardada em commands->tokens)
	if (!command->token)
	{
		função para libertar t_commands ( +  tokens);
		return (NULL);
	}
	if (!validate_tokens(command->token))
	{
		função para libertar t_commands ( +  tokens);
		return (NULL);
	}
	if ()
	command->next = NULL;
}
// retorna node de t_commands
