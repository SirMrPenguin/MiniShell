/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/02 03:05:45 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_input(char **line, t_env   *env) // env para free(env) em caso de erro
{
	
	if (!*line) // line == NULL ao sair do shell, se !line[0], a string esta vazia só enter
    {
        clear_env(env);
        printf ("exit/n");
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
	if (!check_redirections_pipes(line)) // verifica só redir e se tem reditr no fim  
		return (false);

}
  
char	**split_commands(char *line) // separa a linha pelos pipes (fora de aspas)
{
	t_var	v;
	int		pipes;
	char	**command_array;
	
	init_var(&v);
	pipes = count_pipes(line);
	command_array = calloc(pipes + 2, sizeof(char*));
	if (!command_array)
		return (NULL);
	if (!copy_command_array(line, command_array, v))
		return (NULL);	
	return (command_array);
}



t_commands	*create_command_list(char *line)
{
	int	i;
	char	**commands_split ;

	i = 0;
	commands_split = split_commands(line); // separar commands pela 
	if (!commands_split)
		return (NULL);
	while (commands_split[i])
		trim_spaces(&commands_split[i++]); // tirar espacos na ponta

	

	free_array(commands_split);
}



bool	parse(char *command_line, t_env *env, t_commands **commands)
{

    
	if (!check_input(&command_line, env))
		return (clear_env(env), false); // é p libertar? o readline continua
	*commands = create_command_list(command_line); // verificar return das funcoes 
	
	
}

