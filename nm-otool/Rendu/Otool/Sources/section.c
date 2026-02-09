/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   section.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 10:47:45 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 11:55:38 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

int		find_sect_text(t_bin *binary, uint32_t cmd)
{
	struct section			*sect;
	uint32_t				index;

	index = 0;
	if (cmd == LC_SEGMENT)
	{
		sect = (struct section*)(binary->start + binary->offset);
		if (binary->flags.need_swap)
			ft_swap_section(sect, binary->nsects);
		while (index < binary->nsects)
		{
			if (!ft_strcmp(sect[index].sectname, SECT_TEXT))
			{
				binary->text.addr = sect[index].addr;
				binary->text.size = sect[index].size;
				binary->text.offset = sect[index].offset;
				return (TRUE);
			}
			index++;
		}
	}
	return (FALSE);
}

int		find_sect_text_64(t_bin *binary, uint32_t cmd)
{
	struct section_64		*sect64;
	uint32_t				index;

	index = 0;
	if (cmd == LC_SEGMENT_64)
	{
		sect64 = (struct section_64*)(binary->start + binary->offset);
		if (binary->flags.need_swap)
			ft_swap_section_64(sect64, binary->nsects);
		while (index < binary->nsects)
		{
			if (!ft_strcmp(sect64[index].sectname, SECT_TEXT))
			{
				binary->text.addr = sect64[index].addr;
				binary->text.size = sect64[index].size;
				binary->text.offset = sect64[index].offset;
				return (TRUE);
			}
			index++;
		}
	}
	return (FALSE);
}

void	read_load_cmds(t_bin *binary)
{
	struct load_command	*lc;
	uint32_t			index;

	index = 0;
	lc = (struct load_command*)(binary->start + binary->offset);
	while (index < binary->ncmds)
	{
		if (binary->flags.need_swap)
			ft_swap_load_command(lc);
		if (lc->cmd == LC_SEGMENT)
		{
			read_segment_command(binary);
			if (find_sect_text(binary, lc->cmd))
				return ;
		}
		if (lc->cmd == LC_SEGMENT_64)
		{
			read_segment_command(binary);
			if (find_sect_text_64(binary, lc->cmd))
				return ;
		}
		lc = (struct load_command *)((void *)lc + lc->cmdsize);
		index++;
	}
}
