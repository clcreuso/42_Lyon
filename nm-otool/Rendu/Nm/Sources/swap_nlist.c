/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_nlist.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:25:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:59:02 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_swap_nlist(struct nlist *symbols, uint32_t nsymbols)
{
	uint32_t n;

	n = 0;
	while (n < nsymbols)
	{
		symbols[n].n_un.n_strx = swap_4(symbols[n].n_un.n_strx);
		symbols[n].n_desc = swap_2(symbols[n].n_desc);
		symbols[n].n_value = swap_4(symbols[n].n_value);
	}
}

void	ft_swap_nlist_64(struct nlist_64 *symbols, uint32_t nsymbols)
{
	uint32_t n;

	n = 0;
	while (n < nsymbols)
	{
		symbols[n].n_un.n_strx = swap_4(symbols[n].n_un.n_strx);
		symbols[n].n_desc = swap_2(symbols[n].n_desc);
		symbols[n].n_value = swap_8(symbols[n].n_value);
	}
}
