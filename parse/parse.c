/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:41:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/25 20:29:08 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_input(char *line, t_env   *env) // env para free(env) em caso de erro
{
    
    if (!line || !line[0])
    {
        clear_env(env);
        printf ("exit/n");
        exit(status)???????????/
    }
    remove_tabs(line);
    if (is_everything)



    




    1- tudo espaco / tab e remover das pontas 

    2- erros de syntax (talvez so redir)
        - redir ou pipe no inicio/fim 
        - nao sao so redir ou pipe
        - nao tem mais de 2 redir seguidos ou pipes
        - nao existem 2 redir ou pipes sem conteudo entre eles
    3- erro pipes (...)

    3- erros de quotes
    

}


int	parse(char *commmand_line, char **env)
{
    char *linw;

    line = remove_tabs_and_spaces(command);
    if (!check_input(line, env))
    {
        
    }
}
