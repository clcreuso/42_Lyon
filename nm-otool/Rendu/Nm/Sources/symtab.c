/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   symtab.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:33:14 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 15:08:52 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

t_sym	*refresh_symlist(t_sym *symlist, t_sym *new)
{
	t_sym	*prev;
	t_sym	*ptr;
	int		cmp;

	if (!(ptr = symlist))
		return (new);
	while (ptr)
	{
		cmp = ft_strcmp(new->name, ptr->name);
		if (cmp < 0 || (!cmp && new->value < ptr->value))
		{
			if (ptr == symlist)
			{
				new->next = ptr;
				return (new);
			}
			break ;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	new->next = ptr;
	prev->next = new;
	return (symlist);
}

void	read_symtab_command(struct symtab_command *symtab, t_bin *binary)
{
	struct nlist	*nlist;
	t_sym			*new;
	char			*string;
	uint32_t		index;

	index = 0;
	string = binary->start + symtab->stroff;
	nlist = (struct nlist*)(binary->start + symtab->symoff);
	if (binary->flags.need_swap)
		ft_swap_nlist(nlist, symtab->nsyms);
	while (index < symtab->nsyms)
	{
		if (nlist[index].n_type <= 31)
		{
			new = initialize_sym(binary, nlist[index], string);
			binary->symlist = refresh_symlist(binary->symlist, new);
		}
		index++;
	}
}

void	read_symtab_command_64(struct symtab_command *symtab, t_bin *bin)
{
	t_sym			*new;
	struct nlist_64	*nlist;
	char			*string;
	uint32_t		index;

	index = 0;
	string = bin->start + symtab->stroff;
	nlist = (struct nlist_64*)(bin->start + symtab->symoff);
	if (bin->flags.need_swap)
		ft_swap_nlist_64(nlist, symtab->nsyms);
	while (index < symtab->nsyms)
	{
		if (nlist[index].n_type <= 31)
		{
			new = initialize_sym_64(bin, nlist[index], string);
			bin->symlist = refresh_symlist(bin->symlist, new);
		}
		index++;
	}
}

t_sc	*find_symtab_command(t_bin *binary)
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
