/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_command.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 12:04:52 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:55:19 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_swap_load_command(struct load_command *lc)
{
	lc->cmd = swap_4(lc->cmd);
	lc->cmdsize = swap_4(lc->cmdsize);
}

void	ft_swap_symtab_command(struct symtab_command *st)
{
	st->cmd = swap_4(st->cmd);
	st->cmdsize = swap_4(st->cmdsize);
	st->symoff = swap_4(st->symoff);
	st->nsyms = swap_4(st->nsyms);
	st->stroff = swap_4(st->stroff);
	st->strsize = swap_4(st->strsize);
}

void	ft_swap_segment_command(struct segment_command *sg)
{
	sg->cmd = swap_4(sg->cmd);
	sg->cmdsize = swap_4(sg->cmdsize);
	sg->vmaddr = swap_4(sg->vmaddr);
	sg->vmsize = swap_4(sg->vmsize);
	sg->fileoff = swap_4(sg->fileoff);
	sg->filesize = swap_4(sg->filesize);
	sg->maxprot = swap_4(sg->maxprot);
	sg->initprot = swap_4(sg->initprot);
	sg->nsects = swap_4(sg->nsects);
	sg->flags = swap_4(sg->flags);
}

void	ft_swap_segment_command_64(struct segment_command_64 *sg)
{
	sg->cmd = swap_4(sg->cmd);
	sg->cmdsize = swap_4(sg->cmdsize);
	sg->vmaddr = swap_8(sg->vmaddr);
	sg->vmsize = swap_8(sg->vmsize);
	sg->fileoff = swap_8(sg->fileoff);
	sg->filesize = swap_8(sg->filesize);
	sg->maxprot = swap_4(sg->maxprot);
	sg->initprot = swap_4(sg->initprot);
	sg->nsects = swap_4(sg->nsects);
	sg->flags = swap_4(sg->flags);
}
