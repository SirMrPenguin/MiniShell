/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:51:07 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/24 03:32:46 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **envp)
{
	char	*line;
	t_env	*env;
	t_commands	*commands;

	init_env(&env, envp);
	while (1)
	{
		setup_signals();
		line = readline("minishell$ ");
		if (!line)
		{
			continue;
		}
		if (line && line[0])
			add_history(line);
		if (!parse(line, env, &commands)) // em caso de erro já dá clean do
			{
				
			}
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