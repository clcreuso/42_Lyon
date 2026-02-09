/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cpu.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 11:19:37 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 12:26:03 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_otool.h"

char	*cpu_arm(cpu_subtype_t subtype)
{
	if (subtype == CPU_SUBTYPE_ARM_ALL)
		return ("arm\0");
	if (subtype == CPU_SUBTYPE_ARM64_ALL || subtype == CPU_SUBTYPE_ARM64_V8)
		return ("arm64\0");
	if (subtype == CPU_SUBTYPE_ARM_V4T)
		return ("armv4t\0");
	if (subtype == CPU_SUBTYPE_ARM_V5TEJ)
		return ("armv5\0");
	if (subtype == CPU_SUBTYPE_ARM_XSCALE)
		return ("xscale\0");
	if (subtype == CPU_SUBTYPE_ARM_V6)
		return ("armv6\0");
	if (subtype == CPU_SUBTYPE_ARM_V6M)
		return ("armv6m\0");
	if (subtype == CPU_SUBTYPE_ARM_V7)
		return ("armv7\0");
	if (subtype == CPU_SUBTYPE_ARM_V7F)
		return ("armv7f\0");
	if (subtype == CPU_SUBTYPE_ARM_V7S)
		return ("armv7s\0");
	if (subtype == CPU_SUBTYPE_ARM_V7K)
		return ("armv7k\0");
	if (subtype == CPU_SUBTYPE_ARM_V7M)
		return ("armv7m\0");
	return (subtype == CPU_SUBTYPE_ARM_V8 ? "armv8\0" : "\0");
}

char	*cpu_power_pc(cpu_subtype_t subtype)
{
	if (subtype == CPU_SUBTYPE_POWERPC_ALL)
		return ("ppc\0");
	if (subtype == CPU_SUBTYPE_POWERPC_601)
		return ("ppc601\0");
	if (subtype == CPU_SUBTYPE_POWERPC_603)
		return ("ppc603\0");
	if (subtype == CPU_SUBTYPE_POWERPC_604)
		return ("ppc604\0");
	if (subtype == CPU_SUBTYPE_POWERPC_604e)
		return ("ppc604e\0");
	if (subtype == CPU_SUBTYPE_POWERPC_750)
		return ("ppc750\0");
	if (subtype == CPU_SUBTYPE_POWERPC_7400)
		return ("ppc7400\0");
	if (subtype == CPU_SUBTYPE_POWERPC_7450)
		return ("ppc7450\0");
	if (subtype == CPU_SUBTYPE_POWERPC_970)
		return ("ppc970\0");
	return ("\0");
}

char	*cpu_i386(cpu_subtype_t subtype)
{
	if (subtype == CPU_SUBTYPE_I386_ALL)
		return ("i386\0");
	if (subtype == CPU_SUBTYPE_486)
		return ("i486\0");
	if (subtype == CPU_SUBTYPE_486SX)
		return ("i486SX\0");
	if (subtype == CPU_SUBTYPE_PENT)
		return ("pentium\0");
	if (subtype == CPU_SUBTYPE_586)
		return ("i586\0");
	if (subtype == CPU_SUBTYPE_PENTPRO)
		return ("pentpro\0");
	if (subtype == CPU_SUBTYPE_PENTPRO)
		return ("i686\0");
	if (subtype == CPU_SUBTYPE_PENTII_M3)
		return ("pentIIm3\0");
	if (subtype == CPU_SUBTYPE_PENTII_M5)
		return ("pentIIm5\0");
	if (subtype == CPU_SUBTYPE_PENTIUM_4)
		return ("pentium4\0");
	return ("\0");
}

char	*cpu_other_type(cpu_type_t type, cpu_subtype_t subtype)
{
	if (type == CPU_TYPE_POWERPC64)
		return ("ppc64\0");
	if (type == CPU_TYPE_I860 && subtype == CPU_SUBTYPE_I860_ALL)
		return ("i860\0");
	if (type == CPU_TYPE_X86_64 && subtype == CPU_SUBTYPE_X86_64_ALL)
		return ("x86_64\0");
	if (type == CPU_TYPE_MC680x0 && subtype == CPU_SUBTYPE_MC680x0_ALL)
		return ("m68k\0");
	if (type == CPU_TYPE_HPPA && subtype == CPU_SUBTYPE_HPPA_ALL)
		return ("hppa\0");
	if (type == CPU_TYPE_MC88000 && subtype == CPU_SUBTYPE_MC88000_ALL)
		return ("m88k\0");
	if (type == CPU_TYPE_SPARC && subtype == CPU_SUBTYPE_SPARC_ALL)
		return ("sparc\0");
	if (type == CPU_TYPE_MC680x0 && subtype == CPU_SUBTYPE_MC68030_ONLY)
		return ("m68030\0");
	if (type == CPU_TYPE_MC680x0 && subtype == CPU_SUBTYPE_MC68040)
		return ("m68040\0");
	if (type == CPU_TYPE_HPPA && subtype == CPU_SUBTYPE_HPPA_7100LC)
		return ("hppa7100LC\0");
	return ("\0");
}

char	*cpu_identifier(cpu_type_t type, cpu_subtype_t subtype)
{
	if (type == CPU_TYPE_I386)
		return (cpu_i386(subtype));
	if (type == CPU_TYPE_POWERPC)
		return (cpu_power_pc(subtype));
	if (type == CPU_TYPE_ARM)
		return (cpu_arm(subtype));
	return (cpu_other_type(type, subtype));
}
