/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dump.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:38:08 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 17:16:29 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

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
		if (ptr->symlist)
			result += ptr->print;
		ptr = ptr->next;
	}
	return (result);
}

void		dump_symlist(t_bin *binary, t_sym *symlist)
{
	while (symlist)
	{
		if (binary->flags.is_32_bin)
		{
			if (symlist->symbol == 'U')
				ft_printf("%8s", "");
			else
				ft_printf("%08llx", symlist->value);
		}
		if (binary->flags.is_64_bin)
		{
			if (symlist->symbol == 'U')
				ft_printf("%16s", "");
			else
				ft_printf("%016llx", symlist->value);
		}
		ft_printf(" %c ", symlist->symbol);
		ft_printf("%s\n", symlist->name);
		symlist = symlist->next;
	}
}

void		dump_info(t_file *file, t_bin *binary, int nbin)
{
	if (!file->data->flags.is_fat_bin &&
		!file->data->flags.is_arch_bin &&
		file->argc > 2)
		ft_printf("\n%s:\n", file->name);
	if (file->data->flags.is_fat_bin && nbin > 1)
		ft_printf("\n%s (for architecture %s):\n", file->name,
													binary->cpu_string);
	if (file->data->flags.is_arch_bin)
		ft_printf("\n%s(%s):\n", file->name, binary->arch_name);
}

void		dump_file(t_file *file)
{
	t_bin	*binary;
	t_sym	*symlist;
	int		nbin;

	if ((nbin = count_binary(file)) == -1)
		return ;
	binary = file->data;
	while (binary)
	{
		symlist = (binary->print) ? binary->symlist : NULL;
		if (symlist)
		{
			dump_info(file, binary, nbin);
			dump_symlist(binary, symlist);
		}
		binary = binary->next;
	}
}
