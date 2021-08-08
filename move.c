/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:50:42 by dpants            #+#    #+#             */
/*   Updated: 2021/08/05 16:46:30 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	up(t_config *cfg)
{
	if (cfg->map.map[cfg->player.i - 1][cfg->player.j] != '1')
	{
		if (cfg->map.map[cfg->player.i - 1][cfg->player.j] == 'C')
			cfg->player.col_count++;
		if (cfg->player.i == cfg->exit.i && cfg->player.j == cfg->exit.j)
			cfg->map.map[cfg->player.i][cfg->player.j] = 'E';
		else
			cfg->map.map[cfg->player.i][cfg->player.j] = '0';
		cfg->player.i--;
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'E'
			&& cfg->player.col_count == cfg->map.col_count)
			victory_window(*cfg);
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'X')
			defeat_window();
		cfg->map.map[cfg->player.i][cfg->player.j] = 'P';
	}
	cfg->player.stand = 13;
	enemy_move(cfg);
	cfg->player.move_count++;
	printf("Move: %d\n", cfg->player.move_count);
}

void	down(t_config *cfg)
{
	if (cfg->map.map[cfg->player.i + 1][cfg->player.j] != '1')
	{
		if (cfg->map.map[cfg->player.i + 1][cfg->player.j] == 'C')
			cfg->player.col_count++;
		if (cfg->player.i == cfg->exit.i && cfg->player.j == cfg->exit.j)
			cfg->map.map[cfg->player.i][cfg->player.j] = 'E';
		else
			cfg->map.map[cfg->player.i][cfg->player.j] = '0';
		cfg->player.i++;
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'E'
			&& cfg->player.col_count == cfg->map.col_count)
			victory_window(*cfg);
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'X')
			defeat_window();
		cfg->map.map[cfg->player.i][cfg->player.j] = 'P';
	}
	cfg->player.stand = 1;
	enemy_move(cfg);
	cfg->player.move_count++;
	printf("Move: %d\n", cfg->player.move_count);
}

void	left(t_config *cfg)
{
	if (cfg->map.map[cfg->player.i][cfg->player.j - 1] != '1')
	{
		if (cfg->map.map[cfg->player.i][cfg->player.j - 1] == 'C')
			cfg->player.col_count++;
		if (cfg->player.i == cfg->exit.i && cfg->player.j == cfg->exit.j)
			cfg->map.map[cfg->player.i][cfg->player.j] = 'E';
		else
			cfg->map.map[cfg->player.i][cfg->player.j] = '0';
		cfg->player.j--;
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'E'
			&& cfg->player.col_count == cfg->map.col_count)
			victory_window(*cfg);
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'X')
			defeat_window();
		cfg->map.map[cfg->player.i][cfg->player.j] = 'P';
	}
	cfg->player.stand = 0;
	enemy_move(cfg);
	cfg->player.move_count++;
	printf("Move: %d\n", cfg->player.move_count);
}

void	right(t_config *cfg)
{
	if (cfg->map.map[cfg->player.i][cfg->player.j + 1] != '1')
	{
		if (cfg->map.map[cfg->player.i][cfg->player.j + 1] == 'C')
			cfg->player.col_count++;
		if (cfg->player.i == cfg->exit.i && cfg->player.j == cfg->exit.j)
			cfg->map.map[cfg->player.i][cfg->player.j] = 'E';
		else
			cfg->map.map[cfg->player.i][cfg->player.j] = '0';
		cfg->player.j++;
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'E'
			&& cfg->player.col_count == cfg->map.col_count)
			victory_window(*cfg);
		if (cfg->map.map[cfg->player.i][cfg->player.j] == 'X')
			defeat_window();
		cfg->map.map[cfg->player.i][cfg->player.j] = 'P';
	}
	cfg->player.stand = 2;
	enemy_move(cfg);
	cfg->player.move_count++;
	printf("Move: %d\n", cfg->player.move_count);
}

int	key_pressed(int k_code, t_config *config)
{
	if (k_code == 13)
		up(config);
	if (k_code == 1)
		down(config);
	if (k_code == 0)
		left(config);
	if (k_code == 2)
		right(config);
	if (k_code == 53)
		exit(0);
	return (0);
}
