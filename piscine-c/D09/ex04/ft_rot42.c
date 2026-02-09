/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fttttt_rot42.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 21:20:49 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/16 10:53:11 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		vj_sxqh_yi_qbfxq(char s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		return (1);
	return (0);
}

char	vj_hej(char s)
{
	if (!(vj_sxqh_yi_qbfxq(s)))
		return (s);
	if ((s > 'J' && s <= 'Z') || (s > 'j' && s <= 'z'))
		s -= 26;
	s += 16;
	return (s);
}

char	*ft_rot42(char *ijh)
{
	int q;

	q = 0;
	while (ijh[q])
	{
		ijh[q] = vj_hej(ijh[q]);
		q++;
	}
	return (ijh);
}
