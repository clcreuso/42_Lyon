/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:48:26 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 17:08:38 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	ft_strlen_tests(void)
{
	char	*string;
	char	*save;
	int		count;

	count = -1;
	if (!(string = (char *)calloc(256, sizeof(char))))
		return (ANOMALY);
	save = string;
	while (++count < 255)
		string[count] = 'a';
	while (++*string)
		if (ft_strlen(string) != strlen(string))
			return (FAILURE);
	free(save);
	return (SUCCESS);
}
