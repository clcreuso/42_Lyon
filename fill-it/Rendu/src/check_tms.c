/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:39:23 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/21 14:30:14 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_good(t_contact **lst_tms, int nb_tms)
{
	int a;

	a = 0;
	while (a < nb_tms)
		if (lst_tms[a++][0].print == 0)
			return (0);
	return (1);
}

int		ft_check_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!(ft_check_one_tab(tab[i])))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_one_tab(char *tab)
{
	int			i;
	t_content	check;

	i = 0;
	check = ft_init_content();
	while (tab[i])
	{
		if (tab[i] == '.')
			check.point++;
		else if (tab[i] == '#')
			check.block++;
		else if (tab[i] == '\n')
			check.endl++;
		else
			return (0);
		i++;
	}
	return (check.point == 12 && check.block == 4 && check.endl == 4
			&& ft_strlen(tab) == 20 ? 1 : 0);
}

int		ft_check_tms(char **tab, int n)
{
	while (n--)
	{
		if ((ft_check_one_tms(*tab)) == 0)
			return (0);
		tab++;
	}
	return (1);
}

int		ft_check_one_tms(char *str)
{
	char	*tms;

	while (*str == '.')
		str++;
	tms = ft_modify_tms(str);
	if (!(ft_strcmp(tms, "###....#")) || !(ft_strcmp(tms, "#....#...##")))
		return (1);
	if (!(ft_strcmp(tms, "#....###")) || !(ft_strcmp(tms, "##...#....#")))
		return (1);
	if (!(ft_strcmp(tms, "###...#")) || !(ft_strcmp(tms, "#...##....#")))
		return (1);
	if (!(ft_strcmp(tms, "#...###")) || !(ft_strcmp(tms, "#....##...#")))
		return (1);
	if (!(ft_strcmp(tms, "###..#")) || !(ft_strcmp(tms, "##....#....#")))
		return (1);
	if (!(ft_strcmp(tms, "#..###")) || !(ft_strcmp(tms, "#....#....##")))
		return (1);
	if (!(ft_strcmp(tms, "##..##")) || !(ft_strcmp(tms, "#....##....#")))
		return (1);
	if (!(ft_strcmp(tms, "####")) || !(ft_strcmp(tms, "#....#....#....#")))
		return (1);
	if (!(ft_strcmp(tms, "##...##")) || !(ft_strcmp(tms, "##....##"))
			|| !ft_strcmp(tms, "#...##...#"))
		return (1);
	return (0);
}
