/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:35:05 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_memcpy_tests(void)
{
	char	*sys_return;
	char	*lib_return;
	char	memcpy1[20] = "0123456789\0";
	char	memcpy2[20] = "9876543210\0";
	char	ft_memcpy1[20] = "0123456789\0";
	char	ft_memcpy2[20] = "9876543210\0";

	sys_return = memcpy(memcpy1, memcpy2, 5);
	lib_return = ft_memcpy(ft_memcpy1, ft_memcpy2, 5);
	if (sys_return != memcpy1)
		return (ANOMALY);
	if (lib_return != ft_memcpy1)
		return (FAILURE);
	if (strcmp(memcpy1, "9876556789\0"))
		return (ANOMALY);
	if (strcmp(ft_memcpy1, "9876556789\0"))
		return (FAILURE);
	return (SUCCESS);
}
