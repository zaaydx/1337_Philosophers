
#include "philosophers.h"

int	ft_ispositive(int *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] > '9' || s[i] < '0') && s[0] != '-' && s[0] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	is_digits(char **argv, int c)
{
	int	i;

	i = 1;
	while (i < c)
	{
		if (!check_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isspace(int c)
{
	return ((c > 8 && c < 14) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	int		r;

	r = 0;
	i = 0;
	sig = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			r = (r * 10) + (str[i] - 48);
		else
			break ;
		i++;
	}
	return (r * sig);
}