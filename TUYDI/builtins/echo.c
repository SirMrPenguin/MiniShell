/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:13:59 by joabotel          #+#    #+#             */
/*   Updated: 2026/03/08 16:13:28 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	after_flag(char **array)
{
	int	i;
	int	j;

	i = 1;
	while (array[i])
	{
		if (array[i][0] == '-' && array[i][1] == 'n')
		{
			j = 2;
			while (array[i][j] == 'n')
				j++;
			if (array[i][j])
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

int	echo(t_jobs *job)
{
	int		i;
	bool	has_flag;

	if (!job->job[1]) // apenas foi mandado "echo", imprime newline
		return (ft_nl_fd(1), 0); // pq retornar 0
	has_flag = false;
	i = after_flag(job->job);
	if (i > 1)
		has_flag = true;
	while (job->job[i])
	{
		if (job->job[i][0])
			ft_printf("%s", job->job[i]);
		if (job->job[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!has_flag)
		ft_printf("\n");
	return (0);
}

// int main(void)
// {
// 	t_jobs	job;

// 	char *cmd1[] = {"echo", "hello", "world", NULL};
// 	char *cmd2[] = {"echo", "-n", "hello", "world", NULL};
// 	char *cmd3[] = {"echo", "-nnnn", "hello", "world", NULL};
// 	char *cmd4[] = {"echo", "-nnnn", "-nb", "hello", NULL};
// 	char *cmd5[] = {"echo", NULL};

// 	job.job = cmd1;
// 	echo(&job);

// 	job.job = cmd2;
// 	echo(&job);

// 	job.job = cmd3;
// 	echo(&job);

// 	job.job = cmd4;
// 	echo(&job);

// 	job.job = cmd5;
// 	echo(&job);

// 	return (0);
// }
