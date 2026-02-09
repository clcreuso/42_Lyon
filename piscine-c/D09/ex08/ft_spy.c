/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 10:58:10 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/16 15:33:12 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int		ft_strstr(char *str, char *to_find, int c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (str[b])
	{
		if (to_find[a] == str[b] && (str[b - 1] == 32 || b == 0))
			while (to_find[a] == str[b + a])
				a++;
		if ((str[b + a] == 32 || c == (a + b)) && to_find[a] == '\0')
			return (1);
		a = 0;
		b++;
	}
	return (0);
}

int		ft_check_params(char *str, int c)
{
	char *tab1;
	char *tab2;
	char *tab3;

	tab1 = "president\0";
	tab2 = "kill\0";
	tab3 = "Bauer\0";
	c = ft_strlen(str);
	str[c] = '\0';
	if (ft_strstr(str, tab1, c + 1))
		return (1);
	if (ft_strstr(str, tab2, c + 1))
		return (0);
	if (ft_strstr(str, tab3, c + 1))
		return (0);
	return (0);
}

int		main(int argc, char *argv[])
{
	int a;

	a = 1;
	while (a < argc)
	{
		if (ft_check_params(argv[a], 0))
		{
			write(1, "Alert!!!\n", 8);
			return (0);
		}
		a++;
	}
	return (0);
}
