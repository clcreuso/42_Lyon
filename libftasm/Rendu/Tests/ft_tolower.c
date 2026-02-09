/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tolower.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:35:25 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_tolower_tests(void)
{
	int count;

	count = -1000;
	while (count++ < 1000)
		if (ft_tolower(count) != tolower(count))
			return (FAILURE);
	return (SUCCESS);
}
