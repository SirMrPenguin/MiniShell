	if (line[len - 1] == '<' || line[len - 1] == '>' || line[len - 1] == '|' || line[0] == '|')
	{ 
		//print erro (syntax error near unexpected token `newline');
		return (false);
	}