/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:51:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/20 22:20:28 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **envp)
{
	char	*line;
	t_env	*env;
	t_jobs	*jobs;

	init_env(&env, envp);
	while (1)
	{
		/////// DAR SETUP AOS SINAIS
		line = readline("minishell$ ");
		if (!line)
			/////idk
		if (line && line[0])
			add_history(line);
		check_input (line);
	}
}



int	main (int ac, char **av, char **envp)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf_fd(2, "Too many arguments, use './minishell' to start.\n");
		return (1);
	}
	minishell(envp);
	return (0);
}