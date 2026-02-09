/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:35:44 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_strcat_tests(void)
{
	char	*sys_return;
	char	*lib_return;
	char	strcat1[20] = "01234\0";
	char	strcat2[20] = "56789\n\0";
	char	ft_strcat1[20] = "01234\0";
	char	ft_strcat2[20] = "56789\n\0";

	sys_return = strcat(strcat1, strcat2);
	lib_return = ft_strcat(ft_strcat1, ft_strcat2);
	if (sys_return != strcat1)
		return (ANOMALY);
	if (lib_return != ft_strcat1)
		return (FAILURE);
	if (strcmp(strcat1, "0123456789\n\0"))
		return (ANOMALY);
	if (strcmp(ft_strcat1, "0123456789\n\0"))
		return (FAILURE);
	return (SUCCESS);
}
