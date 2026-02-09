/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 14:59:45 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 11:35:01 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	*mmap_fd(size_t size, int fd)
{
	void	*zone;

	zone = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (zone == MAP_FAILED)
		return (NULL);
	return (zone);
}

char	*arch_name(char *buf)
{
	int i;

	i = 0;
	while (buf[i - 2] != 96)
		i--;
	return (buf + i);
}

void	*overpass_file(t_file *file, void *addr, int offset)
{
	void	*new_addr;

	new_addr = (addr + offset);
	if (new_addr > file->threshold || new_addr < file->buf)
	{
		error_macho_struct(file, CORRUPTED_FILE);
		return (NULL);
	}
	return (new_addr);
}
