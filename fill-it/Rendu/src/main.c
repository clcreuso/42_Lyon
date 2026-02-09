/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:23:58 by lotoussa          #+#    #+#             */
/*   Updated: 2017/11/21 18:39:02 by lotoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_first_part(char *file)
{
	t_first_part fp;

	fp = ft_init_first_part();
	if (!(fp.sample = ft_create_sample(file)))
		return (0);
	if (!(fp.tms_nb = ft_tms_nb(fp.sample)))
		return (0);
	if (!(fp.len_sq = ft_next_sqrt(fp.tms_nb * 4)))
		return (0);
	if (!(fp.tab = ft_create_tab(fp.sample)))
		return (0);
	if (!(ft_check_tab(fp.tab)))
		return (0);
	if (!(ft_check_first_part(file)))
		return (0);
	free(fp.sample);
	free(fp.tab);
	return (1);
}

int		ft_check_first_part(char *file)
{
	t_first_part	fp;

	fp = ft_init_first_part();
	if (!(fp.sample = ft_create_sample(file)))
		return (0);
	if (!(fp.tms_nb = ft_tms_nb(fp.sample)))
		return (0);
	if (!(fp.len_sq = ft_next_sqrt(fp.tms_nb * 4)))
		return (0);
	if (!(fp.tab = ft_extract_tms(fp.sample)))
		return (0);
	if (!(ft_check_tms(fp.tab, fp.tms_nb)))
		return (0);
	free(fp.sample);
	free(fp.tab);
	return (1);
}

void	ft_main_resolve(char *file_name)
{
	t_fillit	p;

	p.str = ft_create_sample(file_name);
	p.nb_tms = ft_count_tms(p.str);
	p.side = ft_next_sqrt(p.nb_tms * 4);
	p.tab = ft_extract_tms(p.str);
	p.tab_tms = ft_convert_tms(p.tab, p.nb_tms);
	p = ft_solve(p.tab_tms, p.side, p.nb_tms);
	ft_print_tab(p.final_tab, p.side);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl("usage: ./fillit description_file");
	else
	{
		if (!(ft_first_part(argv[1])))
		{
			ft_putendl("error");
			return (0);
		}
		ft_main_resolve(argv[1]);
	}
	return (0);
}
