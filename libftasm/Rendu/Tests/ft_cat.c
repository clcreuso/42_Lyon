/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cat.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:28:00 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int		main(int argc, char const *argv[])
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(NULL);
		return (0);
	}
	else
		ft_cat(fd);
	return (0);
}
