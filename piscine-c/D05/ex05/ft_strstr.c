/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:03:52 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/12 20:24:56 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (str[b])
	{
		if (to_find[a] == str[b])
			while (to_find[a] == str[b + a])
				a++;
		if (to_find[a] == '\0')
			return (str + b);
		else
			a = 0;
		b++;
	}
	return (0);
}
