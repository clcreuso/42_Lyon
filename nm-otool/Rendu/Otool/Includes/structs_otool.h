/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structs_otool.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 10:52:23 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 09:24:04 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCTS_OTOOL_H
# define STRUCTS_OTOOL_H

typedef struct stat				t_stat;
typedef struct symtab_command	t_sc;

typedef struct	s_flags
{
	char		need_swap:1;
	char		is_32_bin:1;
	char		is_64_bin:1;
	char		is_fat_bin:1;
	char		is_arch_bin:1;
}				t_flags;

typedef struct	s_text
{
	uint64_t	addr;
	uint64_t	offset;
	uint64_t	size;
}				t_text;

typedef struct	s_bin
{
	uint32_t		filetype;
	uint32_t		cputype;
	u_int32_t		magic;
	u_int32_t		ncmds;
	u_int32_t		nsects;
	u_int32_t		offset;
	u_int32_t		print;
	t_flags			flags;
	t_text			text;
	void			*start;
	char			*arch_name;
	char			*cpu_string;
	void			*next;
}				t_bin;

typedef struct	s_file
{
	u_int32_t	argc;
	char		*prog_name;
	char		*error;
	char		*name;
	void		*buf;
	t_bin		*data;
	t_stat		stat;
	int32_t		fd;
}				t_file;

#endif
