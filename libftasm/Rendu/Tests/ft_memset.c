/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:32:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_memset_tests(void)
{
	char	*sys_return;
	char	*lib_return;
	char	memset1[20] = "AAAAA\0";
	char	ft_memset1[20] = "AAAAA\0";

	sys_return = memset(memset1, 'B', 4);
	lib_return = ft_memset(ft_memset1, 'B', 4);
	if (sys_return != memset1)
		return (ANOMALY);
	if (lib_return != ft_memset1)
		return (FAILURE);
	if (strcmp(memset1, "BBBBA\0"))
		return (ANOMALY);
	if (strcmp(ft_memset1, "BBBBA\0"))
		return (FAILURE);
	return (SUCCESS);
}
