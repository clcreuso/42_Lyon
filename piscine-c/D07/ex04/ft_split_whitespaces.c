/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:55:46 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/20 09:50:23 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_separtion(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (ft_separtion(str[i]) && str[i] != '\0')
		i++;
	while (!(ft_separtion(str[i])) && str[i] != '\0')
		i++;
	return (i + 1);
}

int		ft_count_words(char *str)
{
	int	nb_w;
	int	a;

	a = 0;
	nb_w = 0;
	while (str[a])
	{
		while (ft_separtion(str[a]) && str[a] != '\0')
			a++;
		if (str[a] != '\0')
			nb_w++;
		while (!(ft_separtion(str[a])) && str[a] != '\0')
			a++;
	}
	return (nb_w);
}

char	**ft_fill_tab(char **tab, char *str1, int nb_w, int d)
{
	int	a;
	int	b;
	int c;

	a = 0;
	c = 0;
	while (c < nb_w)
	{
		d = 0;
		while (ft_separtion(str1[a]) && str1[a] != '\0')
			a++;
		b = ft_strlen(str1 + a);
		tab[c] = malloc(sizeof(char) * b);
		while (d < b - 1)
		{
			tab[c][d++] = str1[a++];
			tab[c][d] = '\0';
		}
		c++;
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		nb_w;

	nb_w = ft_count_words(str);
	tab = malloc(sizeof(char *) * (nb_w + 1));
	tab[nb_w] = NULL;
	tab = ft_fill_tab(tab, str, nb_w, 0);
	return (tab);
}
