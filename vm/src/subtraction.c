/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:16:36 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/29 15:14:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	subtraction_norminette(int reg1, int reg2, int reg3)
{
	g_bogies->regs[reg3] = g_bogies->regs[reg1] - \
											g_bogies->regs[reg2];
	if (g_bogies->regs[reg3] == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	g_bogies->aim = 4;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | sub r%d r%d r%d\n", g_bogies->num,
			reg1 + 1, reg2 + 1, reg3 + 1);
	move_caret(g_bogies->aim + 1);
}

void	subtraction(void)
{
	unsigned char	arg_byte;
	int				reg1;
	int				reg2;
	int				reg3;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	if (is_treg(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG) &&
		is_treg(arg_byte, THIRD_ARG))
	{
		reg1 = get_treg(2);
		reg2 = get_treg(3);
		reg3 = get_treg(4);
		if (reg1 >= REG_NUMBER || reg2 >= REG_NUMBER || reg3 >= REG_NUMBER)
		{
			skip_bytes(SUB_OP);
			return ;
		}
		subtraction_norminette(reg1, reg2, reg3);
	}
	else
	{
		skip_bytes(SUB_OP);
		return ;
	}
}
