/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:44:29 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/20 18:52:45 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char				*ft_strcpy(char *dest, char *src)
{
	int a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char				*ft_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*param;
	int			a;

	a = 0;
	param = malloc(sizeof(t_stock_par) * (ac + 1));
	while (a < ac)
	{
		param[a].str = av[a];
		param[a].copy = ft_strdup(av[a]);
		param[a].size_param = ft_strlen(av[a]);
		param[a].tab = ft_split_whitespaces(av[a]);
		a++;
	}
	param[a].str = NULL;
	return (param + 0);
}
