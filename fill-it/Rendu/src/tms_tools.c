/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:51:02 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/21 14:31:14 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tms(char *s)
{
	char nb_tms;

	nb_tms = 1;
	while (*s++)
		if ((*(s - 1) == '\n' && *s == '\n' && *s) && *s)
			nb_tms++;
	return (nb_tms);
}

char	*ft_cut_tms(char *s)
{
	char	*ret;
	char	*str;
	int		nb_sharp;

	nb_sharp = 0;
	if (!(str = ft_strnew(22)))
		return (NULL);
	ret = str;
	while (*(s - 1) != '\n' && *(s - 1))
		s--;
	while (*s && nb_sharp != 4)
	{
		if (*s == '#')
			nb_sharp++;
		*str++ = *s++;
	}
	return (ret);
}

char	**ft_extract_tms(char *s)
{
	char **ret;
	char **tab;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_count_tms(s))))
		return (NULL);
	ret = tab;
	while (*s)
	{
		while (*s != '#' && *s)
			s++;
		if (!(*tab++ = ft_cut_tms(s)))
			return (NULL);
		while (!(*s == '\n' && *(s + 1) == '\n' && *s) && *s)
			s++;
	}
	return (ret);
}

char	*ft_modify_tms(char *str)
{
	char	*tms;
	int		a;
	int		b;

	b = 0;
	a = 0;
	tms = ft_strnew(22);
	while (str[a] == '.')
		a++;
	while (str[a])
	{
		tms[b] = str[a++];
		if (tms[b] == '\n')
			tms[b] = '.';
		b++;
	}
	return (tms);
}
