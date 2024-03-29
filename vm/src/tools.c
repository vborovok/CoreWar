/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:10:46 by kbethany          #+#    #+#             */
/*   Updated: 2019/12/01 14:39:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

size_t		scip_null_border(size_t i)
{
	size_t	c;

	c = 0;
	while (c++ < NULL_B)
		i++;
	return (i);
}

int			check_fd(char *file)
{
	int	fd;

	fd = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_errno(3);
		return (-1);
	}
	return (fd);
}

int			check_file_size(size_t i, char *file, unsigned char *buf)
{
	if (i > FILE_SIZE)
	{
		i -= FILE_SIZE;
		ft_fprintf(2, "Error: File %s has too large a code \
		(%d bytes > %d bytes)\n", file, i + CHAMP_MAX_SIZE, CHAMP_MAX_SIZE);
		free(buf);
		return (-1);
	}
	return (0);
}

int			check_magic_header(unsigned char *bytecode)
{
	int				magic;
	size_t			i;

	magic = 0x0;
	i = 0;
	while (i < MAGIC_NUM_B)
	{
		magic <<= 8;
		magic |= bytecode[i];
		i++;
	}
	if (magic != COREWAR_EXEC_MAGIC)
	{
		free(bytecode);
		return (-1);
	}
	return (0);
}

int			get_bytecode_size(unsigned char *bytecode, int i, t_champ *champ)
{
	int		code_size;
	size_t	c;

	c = 0;
	code_size = 0x0;
	while (c < 4)
	{
		code_size <<= 8;
		code_size |= bytecode[i];
		i++;
		c++;
	}
	champ->code_size = code_size;
	return (i);
}
