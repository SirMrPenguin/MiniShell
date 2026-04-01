/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/01 19:16:03 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_input(char **line, t_env   *env) // env para free(env) em caso de erro
{
	
	if (!*line) // line == NULL ao sair do shell, se !line[0], a string esta vazia só enter
    {
        clear_env(env);
        printf ("exit/n");
        exit(status)???????????; // dar exit mm se for só espaço??
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
	if (!check_redirections_pipes(line)) // verifica só redir e se tem reditr no fim  
		return (false);

}

char	**split_commands(char *line)
{
	
}

t_commands	*create_command_list(char *line)
{
	char	**commands_split ;

	commands_split = split_commands(line); // separar commands pela 
}

bool	parse(char *command_line, t_env *env, t_commands **commands)
{

    
	if (!check_input(&command_line, env))
		return (clear_env(env), false); // é p libertar? o readline continua
	*commands = create_command_list(command_line);
	
	
}

