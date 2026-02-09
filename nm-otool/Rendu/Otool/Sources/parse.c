/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 14:42:54 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 11:55:00 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

void	print_binary(t_bin *list, t_bin *new)
{
	t_bin	*ptr;

	ptr = list->next;
	while (ptr != new)
	{
		if (ptr->filetype == new->filetype)
			helpers_print_binary(ptr, new);
		ptr = ptr->next;
	}
}

void	helpers_print_binary(t_bin *ptr, t_bin *new)
{
	if (ft_strequ(ptr->cpu_string, "i386") &&
		ft_strequ(new->cpu_string, "x86_64"))
		ptr->print = 0;
	if (ft_strequ(ptr->cpu_string, "x86_64") &&
		ft_strequ(new->cpu_string, "i386"))
		new->print = 0;
	if (ft_strequ(ptr->cpu_string, new->cpu_string))
		new->print = 0;
	if (!ft_strlen(ptr->cpu_string) || !ft_strlen(new->cpu_string))
	{
		if (ptr->flags.is_32_bin && new->flags.is_64_bin)
			ptr->print = 0;
		if (ptr->flags.is_64_bin && new->flags.is_32_bin)
			new->print = 0;
	}
	if (new->print && ptr->print)
	{
		if (ft_strlen(ptr->cpu_string) &&
			!ft_strlen(new->cpu_string))
			new->print = 0;
		if (!ft_strlen(ptr->cpu_string) &&
			ft_strlen(new->cpu_string))
			ptr->print = 0;
	}
}

void	parse_bin_fat(t_file *file, t_bin *binary)
{
	t_bin				*ptr;
	struct fat_arch		*archs;
	struct fat_header	*fat;
	uint32_t			index;

	index = -1;
	ptr = binary;
	fat = (struct fat_header*)binary->start;
	archs = (struct fat_arch*)(binary->start + sizeof(struct fat_header));
	if (binary->flags.need_swap)
		ft_swap_fat_header(fat);
	if (binary->flags.need_swap)
		ft_swap_fat_arch(archs, fat->nfat_arch);
	while (++index < fat->nfat_arch)
	{
		file->buf = binary->start + archs[index].offset;
		if (!ft_strncmp((char*)file->buf, "!<arch>", 7))
			break ;
		if ((ptr->next = initialize_bin_struct(file)))
			parse_file(file, ptr->next);
		print_binary(binary, ptr->next);
		ptr = ptr->next;
	}
	file->buf = binary->start;
}

void	parse_bin_arch(t_file *file, t_bin *binary)
{
	t_bin				*ptr;
	int					index;

	index = 1;
	ptr = binary;
	while (index < file->stat.st_size)
	{
		file->buf = binary->start + index;
		if (initialize_flags_struct(NULL, *(uint32_t*)file->buf))
		{
			if ((ptr->next = initialize_bin_struct(file)))
				parse_file(file, ptr->next);
			ptr = ptr->next;
		}
		index++;
	}
	file->buf = binary->start;
}

void	parse_file(t_file *file, t_bin *binary)
{
	if (binary->flags.is_fat_bin)
		parse_bin_fat(file, binary);
	else
	{
		if (binary->flags.is_32_bin)
		{
			read_header(binary);
			read_load_cmds(binary);
		}
		if (binary->flags.is_64_bin)
		{
			read_header_64(binary);
			read_load_cmds(binary);
		}
	}
	if (binary->flags.is_arch_bin)
		parse_bin_arch(file, binary);
}
