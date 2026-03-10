/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:28:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/08 03:07:54 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd(void)
{
	char	cwd[PATH_SIZE];

	if (!getcwd(cwd, PATH_SIZE))
		return (ft_printf("getcwd error \n"), 1);
	ft_printf("%s\n", cwd);
	return (0);
}

// int main ()
// {
//     pwd();
// }