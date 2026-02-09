/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_functions.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:56:48 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 17:09:54 by clement     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

void	print_avtar(int code)
{
	if (code == FAILURE)
	{
		if (GENDER == WOMAN)
			ft_puts("🤦‍♀️");
		if (GENDER == MAN)
			ft_puts("🤦‍♂");
	}
	if (code == SUCCESS)
	{
		if (GENDER == WOMAN)
			ft_puts("👸");
		if (GENDER == MAN)
			ft_puts("🤴");
	}
	if (code == ANOMALY)
	{
		if (GENDER == WOMAN)
			ft_puts("🤷‍♀️");
		if (GENDER == MAN)
			ft_puts("🤷‍♂️");
	}
}

void	print_result(int code, char *tests_name)
{
	char str[4096];

	if (code == FAILURE)
		sprintf(str, "%sFAILURE:\t%-20s%s", RED, tests_name, STOP);
	if (code == SUCCESS)
		sprintf(str, "%sSUCCESS:\t%-20s%s", GREEN, tests_name, STOP);
	if (code == ANOMALY)
		sprintf(str, "%sANOMALY:\t%-20s%s", ORANGE, tests_name, STOP);
	ft_putstr(str);
	print_avtar(code);
}
