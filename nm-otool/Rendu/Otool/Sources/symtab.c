/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   symtab.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:33:14 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:42:19 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

t_stat	*find_symtab_command(t_bin *binary)
{
	struct load_command		*lc;
	struct symtab_command	*symtab;
	int						ncmds;

	ncmds = binary->ncmds;
	while (ncmds--)
	{
		lc = (struct load_command*)(binary->start + binary->offset);
		if (binary->flags.need_swap)
			ft_swap_load_command(lc);
		if (lc->cmd == LC_SYMTAB)
		{
			symtab = (struct symtab_command*)(binary->start + binary->offset);
			if (binary->flags.need_swap)
				ft_swap_symtab_command(symtab);
			return (symtab);
		}
		else
			binary->offset += lc->cmdsize;
	}
	return (NULL);
}
