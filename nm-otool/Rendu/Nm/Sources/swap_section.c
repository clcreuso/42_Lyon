/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_section.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:21:07 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:58:28 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_swap_section(struct section *s, uint32_t nsects)
{
	uint32_t n;

	n = 0;
	while (n < nsects)
	{
		s[n].addr = swap_4(s[n].addr);
		s[n].size = swap_4(s[n].size);
		s[n].offset = swap_4(s[n].offset);
		s[n].align = swap_4(s[n].align);
		s[n].reloff = swap_4(s[n].reloff);
		s[n].nreloc = swap_4(s[n].nreloc);
		s[n].flags = swap_4(s[n].flags);
		s[n].reserved1 = swap_4(s[n].reserved1);
		s[n].reserved2 = swap_4(s[n].reserved2);
		n++;
	}
}

void	ft_swap_section_64(struct section_64 *s, uint32_t nsects)
{
	uint32_t n;

	n = 0;
	while (n < nsects)
	{
		s[n].addr = swap_8(s[n].addr);
		s[n].size = swap_8(s[n].size);
		s[n].offset = swap_4(s[n].offset);
		s[n].align = swap_4(s[n].align);
		s[n].reloff = swap_4(s[n].reloff);
		s[n].nreloc = swap_4(s[n].nreloc);
		s[n].flags = swap_4(s[n].flags);
		s[n].reserved1 = swap_4(s[n].reserved1);
		s[n].reserved2 = swap_4(s[n].reserved2);
		n++;
	}
}
