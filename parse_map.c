/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:01:02 by dpants            #+#    #+#             */
/*   Updated: 2021/08/05 17:26:33 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_config	init_config(int fd)
{
	t_config	config;

	config.window.mlx = mlx_init();
	config.exit.count = 0;
	config.player.count = 0;
	config.player.col_count = 0;
	config.player.move_count = 0;
	config.map.col_count = 0;
	config.map.height = -1;
	config.map.width = 0;
	config.player.stand = 1;
	config.enm_cout = 0;
	parse_map(&config, fd);
	init_textures(&config);
	return (config);
}

void	get_config_map(int i, char *line, t_config *config)
{
	int	j;

	j = 0;
	while (line[j++])
	{
		if (check_char(line[j]))
			config->map.map[i][j] = line[j];
		if (line[j] == 'E')
		{
			config->exit.count++;
			config->exit.i = i;
			config->exit.j = j;
		}
		if (line[j] == 'P')
		{
			config->player.count++;
			config->player.i = i;
			config->player.j = j;
		}
		if (line[j] == 'C')
			config->map.col_count++;
	}
	config->map.map[i][j] = '\0';
}

void	parse_map(t_config *cfg, int fd)
{
	char	*line;

	cfg->map.map = malloc(sizeof(char *) * 300);
	if (cfg->map.map == NULL)
		exit_error("Malloc error\n");
	while (cfg->map.height++ >= -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cfg->map.width && ft_strlen(line) > 1)
			if (cfg->map.width != ft_strlen(line))
				exit_error("Wrong map size in some lines\n");
		cfg->map.width = ft_strlen(line);
		cfg->map.map[cfg->map.height] = malloc(sizeof(char) * cfg->map.width);
		if (cfg->map.map[cfg->map.height] == NULL)
			exit_error("Malloc error\n");
		get_config_map(cfg->map.height, line, cfg);
		free(line);
	}
	close(fd);
	check_config_map(*cfg);
	init_enemy(cfg);
}
