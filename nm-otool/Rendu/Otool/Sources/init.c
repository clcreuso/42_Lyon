/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:27:59 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 11:12:52 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

int		initialize_flags_struct(t_bin *binary, uint32_t magic)
{
	t_flags	flags;

	*(char*)&flags = 0;
	flags.is_fat_bin = MAGIC_FAT(magic);
	flags.is_32_bin = MAGIC_32(magic);
	flags.is_64_bin = MAGIC_64(magic);
	flags.need_swap = MAGIC_SWAP(magic);
	flags.is_arch_bin = MAGIC_ARCH(magic);
	if (binary)
		binary->flags = flags;
	if (!(*(char*)&flags))
		return (FALSE);
	return (TRUE);
}

t_bin	*initialize_bin_struct(t_file *file)
{
	t_bin	*result;

	result = (t_bin*)ft_memalloc(sizeof(t_bin));
	result->magic = *(uint32_t*)file->buf;
	result->start = file->buf;
	result->print = 1;
	if (!(initialize_flags_struct(result, result->magic)))
		error_macho_struct(file, INVALID_MAGIC);
	return (result);
}

t_file	*initialize_macho_struct(int argc, char const **argv, int index)
{
	t_file	*file;

	file = (t_file*)ft_memalloc(sizeof(t_file));
	file->argc = argc;
	file->prog_name = ft_strdup(argv[0]);
	file->name = ft_strdup(argv[index]);
	if ((file->fd = open(file->name, O_RDONLY)) < 0)
		return (error_macho_struct(file, OPEN_FAILED));
	if (fstat(file->fd, &file->stat) < 0)
		return (error_macho_struct(file, STAT_FAILED));
	if (!file->stat.st_size)
		return (error_macho_struct(file, EMPTY_FILE));
	if (!(file->buf = mmap_fd(file->stat.st_size, file->fd)))
		return (error_macho_struct(file, MMAP_FAILED));
	file->data = initialize_bin_struct(file);
	if (file->error)
		return (error_macho_struct(file, INVALID_MAGIC));
	return (file);
}
