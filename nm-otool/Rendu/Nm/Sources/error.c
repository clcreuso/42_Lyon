/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 14:58:08 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 16:21:37 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_error(t_file *file)
{
	ft_putstr_fd(file->prog_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(file->error, STDERR_FILENO);
}

void	*error_macho_struct(t_file *file, int error)
{
	if (file->error)
		return (file);
	if (error == OPEN_FAILED || error == STAT_FAILED)
		file->error = ft_strjoin(file->name, ": Permission denied.");
	if (error == EMPTY_FILE || error == INVALID_MAGIC)
		file->error = ft_strjoin(file->name, ":Invalid object file.");
	if (error == MMAP_FAILED)
		file->error = ft_strjoin(file->name, ": Is a directory.");
	if (error == CORRUPTED_FILE)
		file->error = ft_strjoin(file->name, ": Corrupted file");
	return (file);
}
