/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   macros_nm.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 10:29:53 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 12:17:50 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MACROS_NM_H
# define MACROS_NM_H

# define OPEN_FAILED			1
# define STAT_FAILED			2
# define EMPTY_FILE				3
# define INVALID_MAGIC			4
# define MMAP_FAILED			5
# define CORRUPTED_FILE			6

# define ARCH_MAGIC				0x72613c21
# define ARCH_CIGAM				0x213c6172

# define MAGIC_ARCH(x)			(x == ARCH_MAGIC || x == ARCH_CIGAM)

# define MAGIC_FAT(x)			(MAGIC_IS_FAT32(x) || MAGIC_IS_FAT64(x))

# define MAGIC_32(x)			(MAGIC_IS_32(x) || MAGIC_IS_FAT32(x))
# define MAGIC_IS_32(x)			(x == MH_MAGIC || x == MH_CIGAM)
# define MAGIC_IS_FAT32(x)		(x == FAT_MAGIC || x == FAT_CIGAM)

# define MAGIC_64(x)			(MAGIC_IS_64(x) || MAGIC_IS_FAT64(x))
# define MAGIC_IS_64(x)			(x == MH_MAGIC_64 || x == MH_CIGAM_64)
# define MAGIC_IS_FAT64(x)		(x == FAT_MAGIC_64 || x == FAT_CIGAM_64)

# define MAGIC_SWAP(x)			(MAGIC_IS_SWAP(x) || MAGIC_IS_FATSWAP(x))
# define MAGIC_IS_SWAP(x)		(x == MH_CIGAM || x == MH_CIGAM_64)
# define MAGIC_IS_FATSWAP(x)	(x == FAT_CIGAM || x == FAT_CIGAM_64)

#endif
