/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:15:53 by dpants            #+#    #+#             */
/*   Updated: 2021/08/08 18:21:16 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	enemy_move(t_config *c)
{
	int	n;

	n = -1;
	while (++n < c->enm_cout && c->enm_cout != 0)
	{
		if (c->map.map[c->enm[n].i][c->enm[n].j + 1] == '0')
			c->map.map[c->enm[n].i][c->enm[n].j++] = '0';
		else if (c->map.map[c->enm[n].i + 1][c->enm[n].j] == '0')
			c->map.map[c->enm[n].i++][c->enm[n].j] = '0';
		else if (c->map.map[c->enm[n].i][c->enm[n].j - 1] == '0')
			c->map.map[c->enm[n].i][c->enm[n].j--] = '0';
		else if (c->map.map[c->enm[n].i - 1][c->enm[n].j] == '0')
			c->map.map[c->enm[n].i--][c->enm[n].j] = '0';
		c->map.map[c->enm[n].i][c->enm[n].j] = 'X';
	}
}

int	count_enemy(t_config *cfg)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	c = 0;
	while (i++ != cfg->map.height - 1)
	{
		j = -1;
		while (j++ != cfg->map.width - 1)
			if (cfg->map.map[i][j] == '0')
				c++;
	}
	return (c / 2);
}

int	get_random(void)
{
	char	*rnd_char;
	int		rnd;

	rnd_char = malloc(sizeof(char));
	rnd = (int)&rnd_char;
	if (rnd < 0)
		rnd = -rnd;
	rnd /= 8;
	free(rnd_char);
	return (rnd);
}

void	init_enemy(t_config *cfg)
{
	int		i;
	int		j;
	int		c;
	int		rnd;

	i = -1;
	c = count_enemy(cfg);
	rnd = get_random();
	while (i++ < cfg->map.height - 1 && c)
	{
		j = -1;
		rnd = rnd * rnd;
		while (j++ < cfg->map.width - 1)
		{
			if (cfg->map.map[i][j] == '0' && (rnd++ % 21) == 1 && c \
			&& cfg->enm_cout < 99)
			{
				cfg->enm[cfg->enm_cout].i = i;
				cfg->enm[cfg->enm_cout++].j = j;
				cfg->map.map[i++][j] = 'X';
				c--;
			}
		}
	}
}
