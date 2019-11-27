#include "vm.h"

int		get_tdir_big_size(int i)
{
	int		tdir;
	size_t	c;

	c = 0;
	tdir = 0;
	while (c < DIR_SIZE)
	{
		tdir |= g_arena->list[i % MEM_SIZE].com;
		if (c <= 2)
			tdir <<= 8;
		i++;
		c++;
	}
	return (tdir);
}

short	get_tdir_small_size(int i)
{
	short	tdir;

	tdir = 0;
	tdir |= g_arena->list[i % MEM_SIZE].com;
	tdir <<= 8;
	i++;
	tdir |= g_arena->list[i % MEM_SIZE].com;
	return (tdir);
}

int		get_treg(int scip_size)
{
	int		treg;
	size_t	i;

	i = (g_bogies->index + scip_size) % MEM_SIZE;
	if (g_arena->list[i % MEM_SIZE].champ == 0)
		return (16);
	treg = g_arena->list[i % MEM_SIZE].com;
	if (treg == 0)
		return (16);
	treg -= 1;
	return (treg);
}

int		get_tind(int size_flag, int scip_size)
{
	short	tind;
	int		temp;

	tind = get_tdir_small_size((g_bogies->index + scip_size) % MEM_SIZE);
	tind %= IDX_MOD;
	temp = get_tdir_big_size((g_bogies->index + tind) % MEM_SIZE);
	return (temp);
}