/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:53:44 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/20 20:58:04 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_contact	*ft_fill_list1(t_contact *lst, char *s, char y, char x)
{
	t_contact *ret;

	ret = lst;
	while (*s)
	{
		if (*s == '#')
		{
			lst->x = x;
			lst++->y = y;
		}
		if (*s == '\n')
		{
			y++;
			x -= 5;
		}
		s++;
		x++;
	}
	return (ret);
}

t_contact	*ft_fill_list2(t_contact *lst, char size, char s_x, char c_tms)
{
	t_contact *ret;

	ret = lst;
	s_x = lst->x;
	while (size--)
	{
		lst->print = 0;
		lst->c_tms = c_tms;
		lst->x -= s_x;
		lst++;
	}
	return (ret);
}

t_contact	**ft_convert_tms(char **tab, int nb_tms)
{
	t_contact	**tab_lst;
	t_contact	**ret;
	char		c_tms;

	c_tms = 'A';
	tab_lst = (t_contact **)malloc(sizeof(t_contact*) * (nb_tms));
	tab_lst[nb_tms] = NULL;
	ret = tab_lst;
	while (nb_tms--)
	{
		*tab_lst = (t_contact *)malloc(sizeof(t_contact) * 5);
		*tab_lst = ft_fill_list1(*tab_lst, *tab, 0, 0);
		*tab_lst = ft_fill_list2(*tab_lst, 4, 0, c_tms++);
		tab_lst++;
		tab++;
	}
	return (ret);
}
