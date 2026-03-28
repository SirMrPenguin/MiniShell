/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/28 02:22:47 by anisabel         ###   ########.fr       */
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
    tab_to_space(*line); // normaliza tabs em espaços
    if (empty_line(*line)) // verifica se existem apenas espaços 
		return (false);
	*line = remove_spaces(*line);
/* 	if (!(*line))
		return (false); */ //verificar se é necessário, pois se a linha for vazia não chega aqui
	check_redirections()
    




/*     2- erros de syntax (talvez so redir)
        - redir ou pipe no inicio/fim 
        - nao sao so redir ou pipe
        - nao tem mais de 2 redir seguidos ou pipes
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
