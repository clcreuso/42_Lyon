/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bzero.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:39:00 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_bzero_tests(void)
{
	char string[20] = "0123456789\0";

	if (strlen(string) != 10)
		return (ANOMALY);
	ft_bzero(string, 0);
	if (strlen(string) != 10)
		return (FAILURE);
	if (strlen(string) != 10)
		return (FAILURE);
	ft_bzero(string + 5, 5);
	if (strlen(string) != 5)
		return (FAILURE);
	ft_bzero(string, 5);
	if (strlen(string))
		return (FAILURE);
	else
		return (SUCCESS);
}
