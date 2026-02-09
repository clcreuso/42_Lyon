/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   symbol.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:30:04 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 09:03:37 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

char	read_sect_symbol(uint8_t sect, t_sect list)
{
	if (sect == list.text_nsect)
		return ('t');
	else if (sect == list.data_nsect)
		return ('d');
	else if (sect == list.bss_nsect)
		return ('b');
	else
		return ('s');
}

char	read_symbol(t_sym *list, t_bin *binary)
{
	char c;

	c = '?';
	if ((list->type & N_STAB))
		return ('-');
	if ((list->type & N_TYPE) == N_UNDF)
		c = (list->value) ? 'c' : 'u';
	if ((list->type & N_TYPE) == N_PBUD)
		c = 'u';
	if ((list->type & N_TYPE) == N_ABS)
		c = 'a';
	if ((list->type & N_TYPE) == N_INDR)
		c = 'i';
	if ((list->type & N_TYPE) == N_SECT)
		c = read_sect_symbol(list->sect, binary->sect);
	if ((list->type & N_EXT) && c != '?')
		c = ft_toupper(c);
	return (c);
}
