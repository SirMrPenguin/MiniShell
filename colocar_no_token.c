
#include "../minishell.h"

// verifica se existe alguma coisa entre os redir 

bool	space_between_redir(char *line) 
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] != '<' && line[i] != '>')
			i++;
		if (!line[i])
			break;
		while (line[i] == '<' || line[i] == '>')
			i++;
		while (line[i] == SPACE)
			i++;
		if (line[i] == '<' || line[i] == '>')
		{
			if (line[i] == '<')
				// msg de erro - syntax error near unexpected token `<'
			else
				// msg de erro - syntax error near unexpected token '>'
			return (false);
		}		
	}
	return (true);
}


// tambem verificar se o tem mais do que << e >>
