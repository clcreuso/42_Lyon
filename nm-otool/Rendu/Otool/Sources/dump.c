/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dump.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:38:08 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 11:54:16 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"
#include <mach-o/arch.h>

int			count_binary(t_file *file)
{
	t_bin	*ptr;
	int		result;

	if (file->error)
	{
		print_error(file);
		return (-1);
	}
	result = 0;
	ptr = file->data;
	while (ptr)
	{
		if (ptr->text.offset > 0)
			result += ptr->print;
		ptr = ptr->next;
	}
	return (result);
}

void		dump_spacing(t_bin *binary, int index)
{
	if (binary->flags.is_32_bin &&
		!ft_strequ(binary->cpu_string, "i386\0") &&
		!ft_strequ(binary->cpu_string, "x86_64\0"))
	{
		if ((index % 4) == 0)
			ft_printf(" ");
	}
	else
		ft_printf(" ");
}

void		dump_text(t_bin *binary)
{
	char		*text;
	uint64_t	index;

	index = 0;
	text = (char*)(binary->start + binary->text.offset);
	while (index < binary->text.size)
	{
		if ((index % 16) == 0)
		{
			if (binary->flags.is_32_bin)
				ft_printf("\n%08llx\t", binary->text.addr);
			else
				ft_printf("\n%016llx\t", binary->text.addr);
			binary->text.addr += 16;
		}
		ft_printf("%02x", (unsigned char)text[index]);
		dump_spacing(binary, index++);
	}
	ft_printf("\n");
}

void		dump_file(t_file *file)
{
	t_bin	*binary;
	int		nbin;

	if ((nbin = count_binary(file)) == -1)
		return ;
	binary = file->data;
	while (binary)
	{
		if (binary->text.offset > 0 && binary->print)
		{
			ft_printf("%s", file->name);
			if (file->data->flags.is_fat_bin && nbin > 1)
				ft_printf(" (architecture %s)", binary->cpu_string);
			ft_printf(":\nContents of (__TEXT,__text) section");
			dump_text(binary);
		}
		binary = binary->next;
	}
}
