/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/31 00:11:10 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_input(char **line, t_env   *env) // env para free(env) em caso de erro
{
	
	if (!*line || !(*line)[0]) // line == NULL ao sair do shell, se !line[0], a string esta vazia só enter
    {
        clear_env(env);
        printf ("exit/n");
        exit(status)???????????;
    }
	if (!closed_quotes(*line))
		return (false);
    tab_to_space(*line); // normaliza tabs em espaços
    if (empty_line(*line)) // verifica se existem apenas espaços 
		return (false);
	remove_extra_spaces(line); // remove espaços a mais no início, fim e durante a linha
/* 	if (!(*line))
		return (false); */ //verificar se é necessário, pois se a linha for vazia não chega aqui
	if (!check_redirections(line)) // verificar se é mm necessário **line
		return (false);




/*     2- erros de syntax (talvez so redir)
        - nao tem mais de 2 redir seguidos separados por espacos 
        - nao existem 2 redir ou pipes sem conteudo entre eles
    3- erro pipes (...)

    3- erros de quotes
     */

}



int	parse(char *commmand_line, t_env *env)
{
	if (!check_input(&commmand_line, env))
	{
		clear_env(env);
		
	}
}
