/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 15:59:55 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 11:54:01 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	read_header(t_bin *binary)
{
	struct mach_header	*header;

	header = (struct mach_header*)binary->start;
	if (binary->flags.need_swap)
		ft_swap_mach_header(header);
	binary->ncmds = header->ncmds;
	binary->cputype = header->cputype;
	binary->cpusubtype = header->cpusubtype;
	binary->cpu_string = cpu_identifier(header->cputype, header->cpusubtype);
	binary->sect.filetype = header->filetype;
	binary->offset += sizeof(struct mach_header);
}

void	read_header_64(t_bin *binary)
{
	struct mach_header_64	*header;

	header = (struct mach_header_64*)binary->start;
	if (binary->flags.need_swap)
		ft_swap_mach_header_64(header);
	binary->ncmds = header->ncmds;
	binary->cputype = header->cputype;
	binary->cpusubtype = header->cpusubtype;
	binary->cpu_string = cpu_identifier(header->cputype, header->cpusubtype);
	binary->sect.filetype = header->filetype;
	binary->offset += sizeof(struct mach_header_64);
}
