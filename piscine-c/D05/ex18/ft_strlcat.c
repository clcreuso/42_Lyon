/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:37:48 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/13 12:51:58 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	b;
	int				a;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (src[b] && b < nb)
	{
		dest[b + a] = src[b];
		b++;
	}
	while (b < nb)
	{
		dest[a + b] = '\0';
		b++;
	}
	return (dest);
}
