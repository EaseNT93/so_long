/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:17:28 by dpants            #+#    #+#             */
/*   Updated: 2021/08/05 17:43:27 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	textures(t_config *cfg)
{
	cfg->imgs.emp.ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/emp.xpm", &cfg->imgs.emp.width, &cfg->imgs.emp.width);
	cfg->imgs.wll.ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/wll.xpm", &cfg->imgs.wll.width, &cfg->imgs.wll.width);
	cfg->imgs.ext[0].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/ext_c.xpm", &cfg->imgs.ext[0].width, &cfg->imgs.ext[0].width);
	cfg->imgs.ext[1].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/ext_o.xpm", &cfg->imgs.ext[1].width, &cfg->imgs.ext[1].width);
	cfg->imgs.enm.ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/enemy.xpm", &cfg->imgs.enm.width, &cfg->imgs.enm.width);
}

void	textures_c(t_config *cfg)
{
	cfg->imgs.clt[0].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/clt0.xpm", &cfg->imgs.clt[0].width, &cfg->imgs.clt[0].width);
	cfg->imgs.clt[1].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/clt1.xpm", &cfg->imgs.clt[1].width, &cfg->imgs.clt[1].width);
	cfg->imgs.clt[2].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/clt2.xpm", &cfg->imgs.clt[2].width, &cfg->imgs.clt[2].width);
	cfg->imgs.clt[3].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/clt3.xpm", &cfg->imgs.clt[3].width, &cfg->imgs.clt[3].width);
}

void	textures_p(t_config *cfg)
{
	cfg->imgs.plr[0].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/plr_u.xpm", &cfg->imgs.plr[0].width, &cfg->imgs.plr[0].width);
	cfg->imgs.plr[1].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/plr_d.xpm", &cfg->imgs.plr[1].width, &cfg->imgs.plr[1].width);
	cfg->imgs.plr[2].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/plr_l.xpm", &cfg->imgs.plr[2].width, &cfg->imgs.plr[2].width);
	cfg->imgs.plr[3].ptr = mlx_xpm_file_to_image(cfg->window.mlx, \
	"imgs/plr_r.xpm", &cfg->imgs.plr[3].width, &cfg->imgs.plr[3].width);
}

void	init_textures(t_config *cfg)
{
	textures(cfg);
	textures_c(cfg);
	textures_p(cfg);
}
