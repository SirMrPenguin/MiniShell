#include <stdio.h>

int	ft_len_till_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
/* 	if (str[i] == '=')
		i++; */
	return (i);
}

int main ()
{
	char *s = "123=";
	char *a = "1=fdklfkdsf";
	char *b = "123";

	printf ("%i", ft_len_till_equal(s));
	printf ("%i", ft_len_till_equal(a));
	printf ("%i", ft_len_till_equal(b));
}