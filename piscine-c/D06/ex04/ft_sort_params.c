/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 19:44:51 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/14 18:10:12 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *s1)
{
	int a;

	a = 0;
	while (s1[a])
	{
		ft_putchar(s1[a]);
		a++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] || s2[a])
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (s1[a] - s2[a]);
}

void	ft_sort_params(char *tab[], int len)
{
	char	*swap;
	int		a;
	int		b;

	a = 1;
	while (a < len)
	{
		b = 1;
		while (b < len)
		{
			if (ft_strcmp(tab[a], tab[b]) < 0)
			{
				swap = tab[a];
				tab[a] = tab[b];
				tab[b] = swap;
			}
			b++;
		}
		a++;
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	ft_sort_params(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
