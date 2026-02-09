/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 11:23:46 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/20 09:55:30 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_long_strlen(int argc, char *argv[], int a, int c)
{
	int b;

	while (a < argc)
	{
		b = 0;
		while (argv[a][b])
			b++;
		c += (b + 1);
		a++;
	}
	return (c);
}

char	*ft_concat(char **argv, char *str, int argc, int c)
{
	int		a;
	int		b;

	a = 0;
	while (a < argc - 1)
	{
		b = 0;
		while (argv[a + 1][b])
			str[c++] = argv[a + 1][b++];
		if (a < argc - 1)
			str[c] = '\n';
		a++;
		c++;
	}
	str[c - 1] = '\0';
	return (str);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		size;

	size = ft_long_strlen(argc, argv, 0, 0);
	str = malloc(sizeof(char) * (size + 1));
	str = ft_concat(argv, str, argc, 0);
	return (str);
}
