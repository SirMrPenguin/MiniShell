/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:58:11 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/21 17:26:54 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute_external(t_commands *command, t_env *env)
{
	char	**envp;
	char	*path;


	envp = create_env_array(command->env);
	if (!envp)
		exit (1); // ??????
	path = get_command_path(envp, command, env);
	
}

int	execute_single_command(t_commands *commands, t_env *env)
{
	
}