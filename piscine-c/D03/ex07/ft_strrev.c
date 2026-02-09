/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 20:59:39 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/10 10:17:31 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	swap;
	int		size;
	int		a;

	a = 0;
	size = ft_strlen(str);
	while (a < size / 2)
	{
		swap = str[size - (a + 1)];
		str[size - (a + 1)] = str[a];
		str[a] = swap;
		a++;
	}
	return (str);
}
