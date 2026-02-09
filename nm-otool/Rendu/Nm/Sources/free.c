/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 15:01:11 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 16:20:01 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void		free_symlist(t_sym *ptr)
{
	t_sym *save;

	while (ptr)
	{
		save = ptr;
		ptr = ptr->next;
		free(save);
	}
}

void		free_binlist(t_bin *ptr)
{
	t_bin *save;

	while (ptr)
	{
		if (ptr->symlist)
			free_symlist(ptr->symlist);
		save = ptr;
		ptr = ptr->next;
		free(save);
	}
}

void		free_file(t_file *file)
{
	if (file->data)
		free_binlist(file->data);
	if (file->fd > 0)
		close(file->fd);
	if (file->buf)
		munmap(file->buf, file->stat.st_size);
	if (file->prog_name)
		free(file->prog_name);
	if (file->error)
		free(file->error);
	if (file->name)
		free(file->name);
	if (file)
		free(file);
}
