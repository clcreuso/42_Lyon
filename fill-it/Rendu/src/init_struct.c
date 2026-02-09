/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:27:46 by lotoussa          #+#    #+#             */
/*   Updated: 2017/11/21 14:28:55 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_content		ft_init_content(void)
{
	t_content	content;

	content.point = 0;
	content.block = 0;
	content.endl = 0;
	return (content);
}

t_first_part	ft_init_first_part(void)
{
	t_first_part	fp;

	fp.sample = NULL;
	fp.tab = NULL;
	fp.tms_nb = 0;
	fp.len_sq = 0;
	return (fp);
}

t_contact		**ft_retry(t_contact **lst_tms, int nb_tms)
{
	int a;

	a = 0;
	while (a < nb_tms)
		lst_tms[a++][0].print = 0;
	return (lst_tms);
}
