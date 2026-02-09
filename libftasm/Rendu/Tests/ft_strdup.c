/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:36:58 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_strdup_tests(void)
{
	char	*str;
	char	*sys_return;
	char	*lib_return;

	if (!(str = calloc(sizeof(char), 50)))
		return (ANOMALY);
	if (!(str = memcpy(str, "Hello Wolrd !!\0", 15)))
		return (ANOMALY);
	sys_return = strdup(str);
	lib_return = ft_strdup(str);
	if (sys_return == str)
		return (ANOMALY);
	if (lib_return == str)
		return (FAILURE);
	if (strcmp(sys_return, "Hello Wolrd !!\0"))
		return (ANOMALY);
	if (strcmp(lib_return, "Hello Wolrd !!\0"))
		return (FAILURE);
	free(str);
	free(sys_return);
	free(lib_return);
	return (SUCCESS);
}
