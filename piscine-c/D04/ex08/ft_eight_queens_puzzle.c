/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:58:54 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/12 09:28:49 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_resolve(int nb, int solve)
{
	if (nb == 92)
		return (92);
	solve += ft_resolve(nb + 1, solve);
	return (solve);
}

int		ft_eight_queens_puzzle(void)
{
	int nb;

	nb = 0;
	nb = ft_resolve(nb, 0);
	return (nb);
}
