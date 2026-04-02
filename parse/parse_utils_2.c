/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 23:15:18 by anisabel          #+#    #+#             */
/*   Updated: 2026/04/02 02:55:43 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_pipes(char *line)  
{
    int i;
    int counter;
    
    i = 0;
	counter = 0;
    while (line[i])
	{
		if (line[i] == '|' && !is_in_quotes(line, i))
			counter++;
		i++;
	}
	return (counter);
}

int	count_char (int begin, int end)
{
	if (end < begin)
		return (0);
	return (end - begin);
}

void	copy_command(char *array, char *line, int begin, int len)
{
	int	i;
	int	j;

	i = 0;
	if (line[begin] == '|') // verificar se necessario
		begin++;
	j = begin + len;
	while (line[begin] && begin < j)
		array[i++] = line[begin++];
	array[i] = '\0';
}

int	copy_command_array(char *line, char **command_array, t_var v)
{
	while (line[v.i])
	{
		v.begin = v.i;
		while (line[v.i] && line[v.i] != '|' || 
				(line[v.i] == '|' && is_in_quotes(line, v.i)))
			v.i++;
		v.end = v.i;
		v.len = count_char(v.begin, v.end);
		command_array[v.j] = calloc(v.len + 1, sizeof(char));
		if (!command_array[v.j])
		{
			free_array(command_array);
			return 0;
		}
		copy_command(command_array[v.j], line, v.begin, v.len);
		v.j++;
		if (line[v.i] == '|')
			v.i++;
	}
	command_array[v.j] = NULL;
	return (1);
}


/* 
int main (int ac, char **av)
{
	(void)ac;

	int pipes = count_pipes(av[1]);

	printf("pipes em %s = %d\n", av[1], pipes);
} */