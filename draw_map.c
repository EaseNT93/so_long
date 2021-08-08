/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:55:34 by dpants            #+#    #+#             */
/*   Updated: 2021/08/08 18:24:04 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	draw_player(int i, int j, t_config *cfg)
{
	if (cfg->player.stand == 13)
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.plr[0].ptr, j * 32, i * 32);
	if (cfg->player.stand == 1)
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.plr[1].ptr, j * 32, i * 32);
	if (cfg->player.stand == 0)
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.plr[2].ptr, j * 32, i * 32);
	if (cfg->player.stand == 2)
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.plr[3].ptr, j * 32, i * 32);
}

void	draw_enemy(int i, int j, t_config *cfg)
{
	mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.enm.ptr, j * 32, i * 32);
}

void	draw_img(int i, int j, t_config *cfg)
{
	static unsigned int	r = 0;

	mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
	cfg->imgs.emp.ptr, j * 32, i * 32);
	if (cfg->map.map[i][j] == '1')
	{
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.wll.ptr, j * 32, i * 32);
	}
	if (cfg->map.map[i][j] == 'C')
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.clt[((r / 3000) + i + j) % 4].ptr, j * 32, i * 32);
	if (cfg->map.map[i][j] == 'E' && \
	cfg->map.col_count != cfg->player.col_count)
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.ext[0].ptr, j * 32, i * 32);
	else if (cfg->map.map[i][j] == 'E')
		mlx_put_image_to_window(cfg->window.mlx, cfg->window.window, \
		cfg->imgs.ext[1].ptr, j * 32, i * 32);
	if (cfg->map.map[i][j] == 'P')
		draw_player(i, j, cfg);
	if (cfg->map.map[i][j] == 'X')
		draw_enemy(i, j, cfg);
	r++;
}

void	show_text(t_config *cfg)
{
	char	*str;
	char	*nbr;

	nbr = ft_itoa(cfg->player.move_count);
	if (nbr == NULL)
		exit_error("Malloc error\n");
	str = ft_strjoins("Move:", nbr);
	if (str == NULL)
		exit_error("Malloc error\n");
	mlx_string_put(cfg->window.mlx, cfg->window.window, 1, 1, 0xFFFF00, str);
	free(nbr);
	free(str);
}

int	draw_map(t_config *cfg)
{
	int		i;
	int		j;

	mlx_clear_window(cfg->window.window, cfg->window.window);
	i = -1;
	while (i++ != cfg->map.height - 1)
	{
		j = -1;
		while (j++ != cfg->map.width - 1)
			draw_img(i, j, cfg);
	}
	show_text(cfg);
	return (0);
}
