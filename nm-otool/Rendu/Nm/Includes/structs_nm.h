/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   structs_nm.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 10:31:29 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 16:48:51 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCTS_NM_H
# define STRUCTS_NM_H

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

typedef struct	s_sym
{
	uint8_t		type;
	uint8_t		sect;
	u_int64_t	value;
	char		symbol;
	char		*name;
	void		*next;
}				t_sym;

typedef struct	s_sect
{
	uint32_t	filetype;
	uint32_t	bss_nsect;
	uint32_t	data_nsect;
	uint32_t	text_nsect;
}				t_sect;

typedef struct	s_bin
{
	u_int32_t		ncmds;
	u_int32_t		magic;
	u_int32_t		offset;
	t_flags			flags;
	t_sect			sect;
	cpu_type_t		cputype;
	cpu_subtype_t	cpusubtype;
	t_sym			*symlist;
	void			*start;
	char			*cpu_string;
	char			*arch_name;
	char			print;
	void			*next;
}				t_bin;

typedef struct	s_file
{
	u_int32_t	argc;
	char		*prog_name;
	char		*error;
	char		*name;
	void		*buf;
	void		*threshold;
	t_bin		*data;
	t_stat		stat;
	int32_t		fd;
}				t_file;

#endif
