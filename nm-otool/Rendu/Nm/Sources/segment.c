/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   segment.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 17:57:37 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 15:08:14 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	helpers_read_segment(t_bin *binary, void *addr, int *segnum)
{
	struct section	*section;

	section = (struct section*)addr;
	if (ft_strcmp(section->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(section->segname, SEG_TEXT) == 0)
		binary->sect.text_nsect = *segnum + 1;
	else if (ft_strcmp(section->sectname, SECT_DATA) == 0 &&
				ft_strcmp(section->segname, SEG_DATA) == 0)
		binary->sect.data_nsect = *segnum + 1;
	else if (ft_strcmp(section->sectname, SECT_BSS) == 0 &&
				ft_strcmp(section->segname, SEG_DATA) == 0)
		binary->sect.bss_nsect = *segnum + 1;
}

void	read_segment(struct load_command *lc, t_bin *binary, int *segnum)
{
	struct segment_command		*sg;
	struct section				*section;
	uint32_t					index;

	index = 0;
	sg = (struct segment_command*)lc;
	section = (struct section*)((char *)sg + sizeof(struct segment_command));
	if (binary->flags.need_swap)
	{
		ft_swap_load_command(lc);
		ft_swap_segment_command(sg);
		ft_swap_section(section, sg->nsects);
	}
	while (index < sg->nsects)
	{
		helpers_read_segment(binary, (section + index), segnum);
		*segnum += 1;
		index++;
	}
}

void	helpers_read_segment_64(t_bin *binary, void *addr, int *segnum)
{
	struct section_64	*section;

	section = (struct section_64*)addr;
	if (ft_strcmp(section->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(section->segname, SEG_TEXT) == 0)
		binary->sect.text_nsect = *segnum + 1;
	else if (binary->sect.filetype == MH_KEXT_BUNDLE &&
				ft_strcmp(section->sectname, SECT_TEXT) == 0 &&
				ft_strcmp(section->segname, "__TEXT_EXEC") == 0)
		binary->sect.text_nsect = *segnum + 1;
	else if (ft_strcmp(section->sectname, SECT_DATA) == 0 &&
				ft_strcmp(section->segname, SEG_DATA) == 0)
		binary->sect.data_nsect = *segnum + 1;
	else if (ft_strcmp(section->sectname, SECT_BSS) == 0 &&
				ft_strcmp(section->segname, SEG_DATA) == 0)
		binary->sect.bss_nsect = *segnum + 1;
}

void	read_segment_64(struct load_command *lc, t_bin *binary, int *seg)
{
	struct segment_command_64	*sg;
	struct section_64			*section;
	uint32_t					index;

	index = 0;
	sg = (struct segment_command_64*)lc;
	section = (struct section_64*)((char *)sg + sizeof(*sg));
	if (binary->flags.need_swap)
	{
		ft_swap_load_command(lc);
		ft_swap_segment_command_64(sg);
		ft_swap_section_64(section, sg->nsects);
	}
	while (index < sg->nsects)
	{
		helpers_read_segment_64(binary, (section + index), seg);
		*seg += 1;
		index++;
	}
}

void	read_segment_command(t_file *file, t_bin *binary)
{
	struct load_command	*prev;
	struct load_command	*lc;
	int					segnum;
	u_int32_t			index;

	index = 0;
	segnum = 0;
	lc = (struct load_command*)(binary->start + binary->offset);
	while (index < binary->ncmds)
	{
		if (binary->flags.need_swap)
			ft_swap_load_command(lc);
		if (lc->cmd == LC_SEGMENT)
			read_segment(lc, binary, &segnum);
		else if (lc->cmd == LC_SEGMENT_64)
			read_segment_64(lc, binary, &segnum);
		prev = lc;
		if (lc->cmdsize == 0)
			return ((void)error_macho_struct(file, CORRUPTED_FILE));
		lc = (struct load_command *)((void *)lc + lc->cmdsize);
		if (binary->flags.need_swap)
			ft_swap_load_command(prev);
		index++;
	}
}
