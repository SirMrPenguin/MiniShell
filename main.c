/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:51:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/15 23:56:49 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **envp)
{
	char	*command_line;
	t_env	env;
	t_jobs	*jobs;

	env = env_init(envp);
	while (1)
	{
		/////// DAR SETUP AOS SINAIS
		command_line = readline("minishell$ ");
		if (!command_line)
			/////idk
		if (command_line && command_line[0])
			add_history(command_line);
		parse (command_line);
	}
}



int	main (int ac, char **av, char **envp)
{
	(void)av;
	if (ac != 1)
		return (1);
	minishell(envp);
	return (0);
}