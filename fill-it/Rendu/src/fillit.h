/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:21:34 by lotoussa          #+#    #+#             */
/*   Updated: 2017/11/21 14:57:47 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include <stdio.h>

# define BUF_SIZE 599

typedef struct	s_contact
{
	int			x;
	int			y;
	char		c_tms;
	char		print;
}				t_contact;

typedef struct	s_fillit
{
	t_contact	**tab_tms;
	char		**final_tab;
	char		**tab;
	char		*str;
	int			nb_tms;
	int			side;
	int			tms;
	int			y;
	int			x;
}				t_fillit;

typedef struct	s_content
{
	int			point;
	int			block;
	int			endl;
}				t_content;

typedef struct	s_first_part
{
	char		*sample;
	char		**tab;
	int			tms_nb;
	int			len_sq;
}				t_first_part;

/*
**	Functions in the file main.c
*/

int				ft_first_part(char *file);
int				ft_check_first_part(char *file);
void			ft_main_resolve(char *file_name);

/*
**	Functions in the file check_tms.c
*/

int				ft_check_good(t_contact **lst_tms, int nb_tms);
int				ft_check_tms(char **tab, int n);
int				ft_check_tab(char **tab);
int				ft_check_one_tab(char *tab);
int				ft_check_one_tms(char *str);

/*
**	Functions in the file convert_tms.c
*/

t_contact		*ft_fill_list1(t_contact *lst, char *s, char y, char x);
t_contact		*ft_fill_list2(t_contact *lst, char size, char s_x, char c_tms);
t_contact		**ft_convert_tms(char **tab, int nb_tms);

/*
**	Functions in the file fillit_tools.c
*/

char			**ft_create_tab(char *sample);
char			**ft_tabnew(int side);
char			*ft_create_sample(char *file);
void			ft_print_tab(char **tab, int side);
int				ft_tms_nb(char *sample);

/*
**	Functions in the file forced_solve.c
*/

void			ft_print(t_contact *lst_tms, t_fillit p);
void			ft_unprint(t_contact *lst_tms, t_fillit p);
char			ft_check_print(t_contact *lst_tms, t_fillit p);
int				ft_fill_it(t_contact **lst_tms, t_fillit p, int pos, int count);
t_fillit		ft_solve(t_contact **lst_tms, int side, int nb_tms);

/*
**	Functions in the file init_struct.c
*/

t_content		ft_init_content(void);
t_first_part	ft_init_first_part(void);
t_contact		**ft_retry(t_contact **lst_tms, int nb_tms);

/*
**	Functions in the file tms_tools.c
*/

int				ft_count_tms(char *s);
char			*ft_cut_tms(char *s);
char			**ft_extract_tms(char *s);
char			*ft_modify_tms(char *str);

#endif
