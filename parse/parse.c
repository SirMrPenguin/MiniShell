/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/13 01:08:39 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_input(char **line, t_env   *env) // env para free(env) em caso de erro
{
	
	if (!*line) // line == NULL ao sair do shell, se !line[0], a string esta vazia só enter
    {
        clear_env(env);
        printf ("exit\n");
        //exit(status)???????????; // dar exit mm se for só espaço??
    }
	if (!(*line)[0])
		return (false); ;
	if (!closed_quotes(*line))
		return (false);
    tab_to_space(*line); // normaliza tabs em espaços
    if (empty_line(*line)) // verifica se existem apenas espaços 
		return (false);
	remove_extra_spaces(line); // remove espaços a mais no início, fim e durante a linha
/* 	if (!(*line))
		return (false); */ //verificar se é necessário, pois se a linha for vazia não chega aqui
	if (!check_redirections_pipes(*line)) // verifica só redir/pipe e se tem reditr no fim e pipe no inicio/fim + rdir invalidas
		return (false);
}

!!!!!!!!!!!!!!!!! verificar se espaços em aspas em check_input !!!!!!!!!!!;

t_commands	*create_command_list(char *cmd, t_env *env)
{
	int			i;
	char		**commands_split;
	t_commands	*commands;
	t_commands	*current;
	

	i = 0;
	commands_split = split_commands(cmd); // separar commands por pipes
	if (!commands_split)
		return (NULL);
	while (commands_split[i])
		trim_spaces(&commands_split[i++]); // tirar espacos nas pontas
	commands = create_command(commands_split[0], env);
		
	current = commands; // igualar current a commands, para dps retornar *t_commands (sem ter alterado o pointer principal)
	i = 0;
	while (commands_split[++i])
	{
		current->next = create_command(commands_split[i], env);
		current = current->next;
	}
	return (free_array(commands_split), commands);
}

bool	parse(char *command_line, t_env *env, t_commands **commands)
{

    
	if (!check_input(&command_line, env))
		return (clear_env(env), false); // é p libertar? o readline continua
	*commands = create_command_list(command_line); 
		// verificar return das funcoes &&
		// retorna o pointer para a head da lista de comandos
	
	
}

