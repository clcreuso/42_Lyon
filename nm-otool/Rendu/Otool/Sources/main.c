/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 12:04:32 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 11:12:23 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

int		main(int argc, char const *argv[])
{
	t_file		*file;
	int			index;

	index = 0;
	while (++index < argc)
	{
		file = NULL;
		if ((file = initialize_macho_struct(argc, argv, index)))
		{
			if (!(file->error))
				parse_file(file, file->data);
			dump_file(file);
		}
		free_file(file);
	}
	return (0);
}
