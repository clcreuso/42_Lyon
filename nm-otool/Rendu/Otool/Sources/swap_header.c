/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_header.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 11:46:38 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:59:49 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_swap_fat_header(struct fat_header *fh)
{
	fh->magic = swap_4(fh->magic);
	fh->nfat_arch = swap_4(fh->nfat_arch);
}

void	ft_swap_mach_header(struct mach_header *mh)
{
	mh->magic = swap_4(mh->magic);
	mh->cputype = swap_4(mh->cputype);
	mh->cpusubtype = swap_4(mh->cpusubtype);
	mh->filetype = swap_4(mh->filetype);
	mh->ncmds = swap_4(mh->ncmds);
	mh->sizeofcmds = swap_4(mh->sizeofcmds);
	mh->flags = swap_4(mh->flags);
}

void	ft_swap_mach_header_64(struct mach_header_64 *mh)
{
	mh->magic = swap_4(mh->magic);
	mh->cputype = swap_4(mh->cputype);
	mh->cpusubtype = swap_4(mh->cpusubtype);
	mh->filetype = swap_4(mh->filetype);
	mh->ncmds = swap_4(mh->ncmds);
	mh->sizeofcmds = swap_4(mh->sizeofcmds);
	mh->flags = swap_4(mh->flags);
	mh->reserved = swap_4(mh->reserved);
}

void	ft_swap_fat_arch(struct fat_arch *fa, uint32_t n_fa)
{
	uint32_t n;

	n = 0;
	while (n < n_fa)
	{
		fa[n].cputype = swap_4(fa[n].cputype);
		fa[n].cpusubtype = swap_4(fa[n].cpusubtype);
		fa[n].offset = swap_4(fa[n].offset);
		fa[n].size = swap_4(fa[n].size);
		fa[n].align = swap_4(fa[n].align);
		n++;
	}
}
