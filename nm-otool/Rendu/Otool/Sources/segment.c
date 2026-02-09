/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   segment.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 17:57:37 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 14:41:51 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

void	read_segment_command(t_bin *binary)
{
	struct load_command			*lc;
	struct segment_command		*sg;
	struct segment_command_64	*sg64;

	lc = (struct load_command*)(binary->start + binary->offset);
	if (binary->flags.need_swap)
		ft_swap_load_command(lc);
	if (binary->flags.is_32_bin)
	{
		sg = (struct segment_command*)(binary->start + binary->offset);
		if (binary->flags.need_swap)
			ft_swap_segment_command(sg);
		binary->offset += sizeof(struct segment_command);
		binary->nsects = sg->nsects;
	}
	if (binary->flags.is_64_bin)
	{
		sg64 = (struct segment_command_64*)(binary->start + binary->offset);
		if (binary->flags.need_swap)
			ft_swap_segment_command_64(sg64);
		binary->offset += sizeof(struct segment_command_64);
		binary->nsects = sg64->nsects;
	}
}
