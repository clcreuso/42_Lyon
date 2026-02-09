/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <clcreuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:39:08 by clcreuso          #+#    #+#             */
/*   Updated: 2017/11/20 22:32:29 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tms_nb(char *sample)
{
	int		size;

	size = 0;
	while (*sample)
	{
		if (*sample == '\n' && *(sample + 1) == '\n')
			size++;
		sample++;
	}
	return (*(sample - 1) == '\n' ? size + 1 : size);
}

char	**ft_create_tab(char *sample)
{
	char	**tab;
	int		j;
	int		k;

	k = 0;
	if (ft_count_tms(sample) > 26)
		return (0);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_tms(sample) + 1))))
		return (NULL);
	while (*sample)
	{
		j = 0;
		if (!(tab[k] = (char*)malloc(sizeof(char) * (21))))
			return (NULL);
		while (*sample && (*sample != '\n' || *(sample - 1) != '\n'))
			tab[k][j++] = *sample++;
		tab[k++][j] = '\0';
		sample++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_tabnew(int side)
{
	char	**ret;
	int		y;
	int		x;

	y = 0;
	ret = (char **)malloc(sizeof(char *) * (side + 1));
	if (!ret)
		return (NULL);
	ret[side + 1] = NULL;
	while (y < side)
	{
		x = 0;
		ret[y] = (char *)malloc(sizeof(char) * (side));
		while (x < side)
			ret[y][x++] = '.';
		y++;
	}
	return (ret);
}

char	*ft_create_sample(char *file)
{
	char	*sample;
	int		fd;
	int		ret;

	if (!(sample = ft_memalloc(BUF_SIZE + 1)))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, sample, BUF_SIZE);
	sample[ret] = '\0';
	close(fd);
	if (sample[ret - 1] == '\n' && sample[ret - 2] != '\n')
		return (sample);
	return (0);
}

void	ft_print_tab(char **tab, int side)
{
	int y;
	int x;

	y = 0;
	while (y < side)
	{
		x = 0;
		while (x < side)
			ft_putchar(tab[y][x++]);
		ft_putchar('\n');
		y++;
	}
}
