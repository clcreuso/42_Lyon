/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:32:45 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/13 13:08:39 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_char_is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		ft_char_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_char_is_alphanum(char c)
{
	if (ft_char_is_alpha(c) || ft_char_is_num(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (!(ft_char_is_alphanum(str[a - 1])) && ft_char_is_low(str[a]))
			str[a] -= 32;
		a++;
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] += 32;
	}
	return (str);
}
