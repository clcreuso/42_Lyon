/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:35:34 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/20 21:49:42 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print(t_contact *lst_tms, t_fillit p)
{
	lst_tms[0].print = 1;
	p.final_tab[p.y + lst_tms[0].y][p.x + lst_tms[0].x] = lst_tms[0].c_tms;
	p.final_tab[p.y + lst_tms[1].y][p.x + lst_tms[1].x] = lst_tms[0].c_tms;
	p.final_tab[p.y + lst_tms[2].y][p.x + lst_tms[2].x] = lst_tms[0].c_tms;
	p.final_tab[p.y + lst_tms[3].y][p.x + lst_tms[3].x] = lst_tms[0].c_tms;
}

void		ft_unprint(t_contact *lst_tms, t_fillit p)
{
	lst_tms[0].print = 0;
	p.final_tab[p.y + lst_tms[0].y][p.x + lst_tms[0].x] = '.';
	p.final_tab[p.y + lst_tms[1].y][p.x + lst_tms[1].x] = '.';
	p.final_tab[p.y + lst_tms[2].y][p.x + lst_tms[2].x] = '.';
	p.final_tab[p.y + lst_tms[3].y][p.x + lst_tms[3].x] = '.';
}

char		ft_check_print(t_contact *lst_tms, t_fillit p)
{
	int a;

	a = 0;
	while (++a < 4)
		if ((p.x + lst_tms[a].x) < 0)
			return (0);
	a = 0;
	while (++a < 4)
		if ((p.x + lst_tms[a].x) >= p.side)
			return (0);
	a = 0;
	while (++a < 4)
		if ((p.y + lst_tms[a].y) >= p.side)
			return (0);
	a = 0;
	while (++a < 4)
		if ((p.final_tab[p.y + lst_tms[a].y][p.x + lst_tms[a].x]) != '.')
			return (0);
	return (1);
}

int			ft_fill_it(t_contact **lst_tms, t_fillit p, int pos, int count)
{
	p.y = pos / p.side;
	p.x = pos % p.side;
	p.tms = 0;
	if (count == 0)
		return (1);
	if (pos == (p.side * p.side))
		return (0);
	while (p.tms < p.nb_tms && p.final_tab[p.y][p.x] == '.')
	{
		while (lst_tms[p.tms][0].print == 1)
			p.tms++;
		if (ft_check_print(lst_tms[p.tms], p))
		{
			ft_print(lst_tms[p.tms], p);
			if (ft_fill_it(lst_tms, p, 0, (count - 1)))
				return (1);
			else
				ft_unprint(lst_tms[p.tms], p);
		}
		return (ft_fill_it(lst_tms, p, (pos + 1), count));
	}
	return (ft_fill_it(lst_tms, p, (pos + 1), count));
}

t_fillit	ft_solve(t_contact **lst_tms, int side, int nb_tms)
{
	t_fillit	p;

	p.side = side;
	p.nb_tms = nb_tms;
	while (!(ft_check_good(lst_tms, nb_tms)))
	{
		p.final_tab = ft_tabnew(p.side);
		ft_fill_it(lst_tms, p, 0, nb_tms);
		if (!(ft_check_good(lst_tms, nb_tms)))
		{
			lst_tms = ft_retry(lst_tms, nb_tms);
			free(p.final_tab);
			p.side++;
		}
	}
	return (p);
}
